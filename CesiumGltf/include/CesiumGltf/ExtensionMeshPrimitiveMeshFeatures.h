// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Library.h"

#include <CesiumUtility/ExtensibleObject.h>
#include <CesiumUtility/JsonValue.h>

#include <cstdint>
#include <vector>

namespace CesiumGltf {
/**
 * @brief `EXT_mesh_features` extension for a primitive in a glTF model, to
 * associate it with the root `EXT_mesh_features` object.
 */
struct CESIUMGLTF_API ExtensionMeshPrimitiveMeshFeatures final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName =
      "ExtensionMeshPrimitiveMeshFeatures";
  static inline constexpr const char* ExtensionName = "EXT_mesh_features";

  /**
   * @brief An array of feature IDs. A property table at index `i` corresponds
   * to the `featureIds` entry at the same index. Additional feature ID entries
   * may be present, so the length of the `featureIds` array must be greater
   * than or equal to the length of the `propertyTables` array.
   */
  std::vector<CesiumUtility::JsonValue> featureIds;

  /**
   * @brief An array of IDs of property tables from the root `EXT_mesh_features`
   * object. A property table at index `i` corresponds to the `featureIds` entry
   * at the same index.
   */
  std::vector<int32_t> propertyTables;

  /**
   * @brief An array of IDs of property textures from the root
   * `EXT_mesh_features` object.
   */
  std::vector<int32_t> propertyTextures;
};
} // namespace CesiumGltf