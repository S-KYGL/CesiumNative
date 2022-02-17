// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!

#include "registerExtensions.h"

#include "ExtensionBufferExtMeshoptCompressionJsonHandler.h"
#include "ExtensionBufferViewExtMeshoptCompressionJsonHandler.h"
#include "ExtensionCesiumRTCJsonHandler.h"
#include "ExtensionCesiumTileEdgesJsonHandler.h"
#include "ExtensionExtMeshGpuInstancingJsonHandler.h"
#include "ExtensionKhrDracoMeshCompressionJsonHandler.h"
#include "ExtensionKhrMaterialsUnlitJsonHandler.h"
#include "ExtensionMeshPrimitiveExtFeatureMetadataJsonHandler.h"
#include "ExtensionMeshPrimitiveExtMeshFeaturesJsonHandler.h"
#include "ExtensionMeshPrimitiveExtStructuralMetadataJsonHandler.h"
#include "ExtensionModelExtFeatureMetadataJsonHandler.h"
#include "ExtensionModelExtStructuralMetadataJsonHandler.h"

#include <CesiumGltf/Buffer.h>
#include <CesiumGltf/BufferView.h>
#include <CesiumGltf/Material.h>
#include <CesiumGltf/MeshPrimitive.h>
#include <CesiumGltf/Model.h>
#include <CesiumGltf/Node.h>
#include <CesiumJsonReader/ExtensionReaderContext.h>

namespace CesiumGltfReader {

void registerExtensions(CesiumJsonReader::ExtensionReaderContext& context) {
  (void)context;
  context.registerExtension<CesiumGltf::Model, ExtensionCesiumRTCJsonHandler>();
  context.registerExtension<
      CesiumGltf::Model,
      ExtensionModelExtFeatureMetadataJsonHandler>();
  context.registerExtension<
      CesiumGltf::Model,
      ExtensionModelExtStructuralMetadataJsonHandler>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionCesiumTileEdgesJsonHandler>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionMeshPrimitiveExtFeatureMetadataJsonHandler>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionMeshPrimitiveExtMeshFeaturesJsonHandler>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionMeshPrimitiveExtStructuralMetadataJsonHandler>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionKhrDracoMeshCompressionJsonHandler>();
  context.registerExtension<
      CesiumGltf::Node,
      ExtensionExtMeshGpuInstancingJsonHandler>();
  context.registerExtension<
      CesiumGltf::Buffer,
      ExtensionBufferExtMeshoptCompressionJsonHandler>();
  context.registerExtension<
      CesiumGltf::BufferView,
      ExtensionBufferViewExtMeshoptCompressionJsonHandler>();
  context.registerExtension<
      CesiumGltf::Material,
      ExtensionKhrMaterialsUnlitJsonHandler>();
}
} // namespace CesiumGltfReader
