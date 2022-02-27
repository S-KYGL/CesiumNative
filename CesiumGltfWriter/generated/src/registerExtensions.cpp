// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!

#include "registerExtensions.h"

#include "ModelJsonWriter.h"

#include <CesiumGltf/Buffer.h>
#include <CesiumGltf/BufferView.h>
#include <CesiumGltf/ExtensionBufferExtMeshoptCompression.h>
#include <CesiumGltf/ExtensionBufferViewExtMeshoptCompression.h>
#include <CesiumGltf/ExtensionCesiumRTC.h>
#include <CesiumGltf/ExtensionCesiumTileEdges.h>
#include <CesiumGltf/ExtensionExtMeshGpuInstancing.h>
#include <CesiumGltf/ExtensionKhrDracoMeshCompression.h>
#include <CesiumGltf/ExtensionKhrMaterialsUnlit.h>
#include <CesiumGltf/ExtensionKhrTextureBasisu.h>
#include <CesiumGltf/ExtensionMeshPrimitiveExtFeatureMetadata.h>
#include <CesiumGltf/ExtensionMeshPrimitiveExtMeshFeatures.h>
#include <CesiumGltf/ExtensionMeshPrimitiveExtStructuralMetadata.h>
#include <CesiumGltf/ExtensionModelExtFeatureMetadata.h>
#include <CesiumGltf/ExtensionModelExtStructuralMetadata.h>
#include <CesiumGltf/ExtensionNodeExtInstanceFeatures.h>
#include <CesiumGltf/Material.h>
#include <CesiumGltf/MeshPrimitive.h>
#include <CesiumGltf/Model.h>
#include <CesiumGltf/Node.h>
#include <CesiumGltf/Texture.h>
#include <CesiumJsonWriter/ExtensionWriterContext.h>

namespace CesiumGltfWriter {

void registerExtensions(CesiumJsonWriter::ExtensionWriterContext& context) {
  (void)context;
  context.registerExtension<CesiumGltf::Model, ExtensionCesiumRTCJsonWriter>();
  context.registerExtension<
      CesiumGltf::Model,
      ExtensionModelExtFeatureMetadataJsonWriter>();
  context.registerExtension<
      CesiumGltf::Model,
      ExtensionModelExtStructuralMetadataJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionCesiumTileEdgesJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionMeshPrimitiveExtFeatureMetadataJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionMeshPrimitiveExtMeshFeaturesJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionMeshPrimitiveExtStructuralMetadataJsonWriter>();
  context.registerExtension<
      CesiumGltf::MeshPrimitive,
      ExtensionKhrDracoMeshCompressionJsonWriter>();
  context.registerExtension<
      CesiumGltf::Texture,
      ExtensionKhrTextureBasisuJsonWriter>();
  context.registerExtension<
      CesiumGltf::Node,
      ExtensionExtMeshGpuInstancingJsonWriter>();
  context.registerExtension<
      CesiumGltf::Node,
      ExtensionNodeExtInstanceFeaturesJsonWriter>();
  context.registerExtension<
      CesiumGltf::Node,
      ExtensionExtMeshGpuInstancingJsonWriter>();
  context.registerExtension<
      CesiumGltf::Buffer,
      ExtensionBufferExtMeshoptCompressionJsonWriter>();
  context.registerExtension<
      CesiumGltf::BufferView,
      ExtensionBufferViewExtMeshoptCompressionJsonWriter>();
  context.registerExtension<
      CesiumGltf::Material,
      ExtensionKhrMaterialsUnlitJsonWriter>();
}
} // namespace CesiumGltfWriter
