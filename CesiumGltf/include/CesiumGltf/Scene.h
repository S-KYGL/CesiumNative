// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/NamedObject.h"
#include <cstdint>
#include <vector>

namespace CesiumGltf {
    /**
     * @brief The root nodes of a scene.
     */
    struct Scene final : public NamedObject {

        /**
         * @brief The indices of each root node.
         */
        std::vector<int32_t> nodes;

    };
}
