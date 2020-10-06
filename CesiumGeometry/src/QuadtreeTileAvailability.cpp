#include "CesiumGeometry/QuadtreeTileAvailability.h"
#include <algorithm>

namespace CesiumGeometry {

    QuadtreeTileAvailability::QuadtreeTileAvailability(const QuadtreeTilingScheme& tilingScheme, uint32_t maximumLevel) :
        _tilingScheme(tilingScheme),
        _maximumLevel(maximumLevel),
        _rootNodes(this->_tilingScheme.getRootTilesX() * this->_tilingScheme.getRootTilesY())
    {
        for (uint32_t j = 0; j < this->_tilingScheme.getRootTilesY(); ++j) {
            uint32_t rowStart = j * this->_tilingScheme.getRootTilesX();
            for (uint32_t i = 0; i < this->_tilingScheme.getRootTilesX(); ++i) {
                QuadtreeTileID id(0, i, j);
                Rectangle extent = tilingScheme.tileToRectangle(id);
                this->_rootNodes[rowStart + i] = std::make_unique<QuadtreeNode>(id, extent, nullptr);
            }
        }
    }

    void QuadtreeTileAvailability::addAvailableTileRange(const QuadtreeTileRectangularRange& range) {
        Rectangle ll = this->_tilingScheme.tileToRectangle(QuadtreeTileID(range.level, range.minimumX, range.minimumY));
        Rectangle ur = this->_tilingScheme.tileToRectangle(QuadtreeTileID(range.level, range.maximumX, range.maximumY));

        RectangleWithLevel rectangleWithLevel {
            range.level,
            Rectangle(
                ll.minimumX,
                ll.minimumY,
                ur.maximumX,
                ur.maximumY
            )
        };

        for (std::unique_ptr<QuadtreeNode>& pNode : this->_rootNodes) {
            if (pNode->extent.overlaps(rectangleWithLevel.rectangle)) {
                putRectangleInQuadtree(this->_tilingScheme, this->_maximumLevel, *pNode, rectangleWithLevel);
            }
        }
    }

    uint32_t QuadtreeTileAvailability::computeMaximumLevelAtPosition(const glm::dvec2& position) const {
        // Find the root node that contains this position.
        for (const std::unique_ptr<QuadtreeNode>& pNode : this->_rootNodes) {
            if (pNode->extent.contains(position)) {
                return findMaxLevelFromNode(nullptr, *pNode, position);
            }
        }

        return 0;
    }

    bool QuadtreeTileAvailability::isTileAvailable(const QuadtreeTileID& id) const {
        // Get the center of the tile and find the maximum level at that position.
        // Because availability is by tile, if the level is available at that point, it
        // is sure to be available for the whole tile.  We assume that if a tile at level n exists,
        // then all its parent tiles back to level 0 exist too.  This isn't really enforced
        // anywhere, but Cesium would never load a tile for which this is not true.
        CesiumGeometry::Rectangle rectangle = this->_tilingScheme.tileToRectangle(id);
        glm::dvec2 center = rectangle.getCenter();
        return this->computeMaximumLevelAtPosition(center) >= id.level;
    }

    /*static*/ void QuadtreeTileAvailability::putRectangleInQuadtree(const QuadtreeTilingScheme& tilingScheme, uint32_t maximumLevel, QuadtreeTileAvailability::QuadtreeNode& node, const QuadtreeTileAvailability::RectangleWithLevel& rectangle) {
        QuadtreeNode* pNode = &node;

        while (pNode->id.level < maximumLevel) {
            createNodeChildrenIfNecessary(*pNode, tilingScheme);
            if (pNode->ll && pNode->ll->extent.fullyContains(rectangle.rectangle)) {
                pNode = pNode->ll.get();
            } else if (pNode->lr && pNode->lr->extent.fullyContains(rectangle.rectangle)) {
                pNode = pNode->lr.get();
            } else if (pNode->ul && pNode->ul->extent.fullyContains(rectangle.rectangle)) {
                pNode = pNode->ul.get();
            } else if (pNode->ur && pNode->ur->extent.fullyContains(rectangle.rectangle)) {
                pNode = pNode->ur.get();
            } else {
                break;
            }
        }

        if (
            pNode->rectangles.size() == 0 ||
            pNode->rectangles.back().level <= rectangle.level
        ) {
            pNode->rectangles.push_back(rectangle);
        } else {
            // Maintain ordering by level when inserting.
            std::push_heap(pNode->rectangles.begin(), pNode->rectangles.end(), QuadtreeTileAvailability::rectangleLevelComparator);
        }
    }

    /*static*/ bool QuadtreeTileAvailability::rectangleLevelComparator(const QuadtreeTileAvailability::RectangleWithLevel& a, const QuadtreeTileAvailability::RectangleWithLevel& b) {
        return a.level < b.level;
    }

    /*static*/ uint32_t QuadtreeTileAvailability::findMaxLevelFromNode(QuadtreeTileAvailability::QuadtreeNode* pStopNode, QuadtreeTileAvailability::QuadtreeNode& node, const glm::dvec2& position) {
        uint32_t maxLevel = 0;
        QuadtreeTileAvailability::QuadtreeNode* pNode = &node;

        // Find the deepest quadtree node containing this point.
        bool found = false;
        while (!found) {
            uint32_t ll = pNode->ll && pNode->ll->extent.contains(position) ? 1 : 0;
            uint32_t lr = pNode->lr && pNode->lr->extent.contains(position) ? 1 : 0;
            uint32_t ul = pNode->ul && pNode->ul->extent.contains(position) ? 1 : 0;
            uint32_t ur = pNode->ur && pNode->ur->extent.contains(position) ? 1 : 0;

            // The common scenario is that the point is in only one quadrant and we can simply
            // iterate down the tree.  But if the point is on a boundary between tiles, it is
            // in multiple tiles and we need to check all of them, so use recursion.
            if (ll + lr + ul + ur > 1) {
                if (ll) {
                    maxLevel = std::max(maxLevel, findMaxLevelFromNode(pNode, *pNode->ll, position));
                }
                if (lr) {
                    maxLevel = std::max(maxLevel, findMaxLevelFromNode(pNode, *pNode->lr, position));
                }
                if (ul) {
                    maxLevel = std::max(maxLevel, findMaxLevelFromNode(pNode, *pNode->ul, position));
                }
                if (ur) {
                    maxLevel = std::max(maxLevel, findMaxLevelFromNode(pNode, *pNode->ur, position));
                }
                break;
            } else if (ll) {
                pNode = pNode->ll.get();
            } else if (lr) {
                pNode = pNode->lr.get();
            } else if (ul) {
                pNode = pNode->ul.get();
            } else if (ur) {
                pNode = pNode->ur.get();
            } else {
                found = true;
            }
        }

        // Wal up the tree until we find a rectangle that contains this point.
        while (pNode != pStopNode) {
            const std::vector<RectangleWithLevel>& rectangles = pNode->rectangles;

            // Rectangles are sorted by level, lowest first.
            if (rectangles.size() > 0) {
                for (size_t i = rectangles.size() - 1; i >= 0 && rectangles[i].level > maxLevel; --i) {
                    const RectangleWithLevel& rectangle = rectangles[i];
                    if (rectangle.rectangle.contains(position)) {
                        maxLevel = rectangle.level;
                    }
                }
            }

            pNode = pNode->pParent;
        }

        return maxLevel;
    }

    /*static*/ void QuadtreeTileAvailability::createNodeChildrenIfNecessary(QuadtreeTileAvailability::QuadtreeNode& node, const QuadtreeTilingScheme& tilingScheme) {
        if (node.ll) {
            return;
        }

        QuadtreeTileID llID(node.id.level + 1, node.id.x * 2, node.id.y * 2);
        node.ll = std::make_unique<QuadtreeNode>(llID, tilingScheme.tileToRectangle(llID), &node);
        
        QuadtreeTileID lrID(llID.level, llID.x + 1, llID.y);
        node.lr = std::make_unique<QuadtreeNode>(lrID, tilingScheme.tileToRectangle(lrID), &node);

        QuadtreeTileID ulID(llID.level, llID.x, llID.y + 1);
        node.ul = std::make_unique<QuadtreeNode>(ulID, tilingScheme.tileToRectangle(ulID), &node);

        QuadtreeTileID urID(llID.level, llID.x + 1, llID.y + 1);
        node.ur = std::make_unique<QuadtreeNode>(urID, tilingScheme.tileToRectangle(urID), &node);
    }

}
