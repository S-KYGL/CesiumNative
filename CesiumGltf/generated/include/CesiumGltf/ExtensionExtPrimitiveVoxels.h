// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Bounds.h"
#include "CesiumGltf/Library.h"
#include "CesiumGltf/Padding.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <cstdint>
#include <optional>
#include <vector>

namespace CesiumGltf {
/**
 * @brief `EXT_primitive_voxels` extension for a primitive in a glTF model, to
 * specify voxel grid geomtetry for volumetric data
 */
struct CESIUMGLTF_API ExtensionExtPrimitiveVoxels final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName = "ExtensionExtPrimitiveVoxels";
  static inline constexpr const char* ExtensionName = "EXT_primitive_voxels";

  /**
   * @brief Dimensions of the voxel grid. x/y/z for a box, r/z/theta for a
   * cylinder, lon/lat/height for an ellipsoid.
   */
  std::vector<int64_t> dimensions;

  /**
   * @brief bounds
   */
  CesiumGltf::Bounds bounds;

  /**
   * @brief padding
   */
  std::optional<CesiumGltf::Padding> padding;
};
} // namespace CesiumGltf
