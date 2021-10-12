// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "TextureInfoJsonHandler.h"

#include <CesiumGltf/MaterialPBRMetallicRoughness.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/DoubleJsonHandler.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>

namespace CesiumGltf {
class ExtensionReaderContext;

class MaterialPBRMetallicRoughnessJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = MaterialPBRMetallicRoughness;

  MaterialPBRMetallicRoughnessJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void
  reset(IJsonHandler* pParentHandler, MaterialPBRMetallicRoughness* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyMaterialPBRMetallicRoughness(
      const std::string& objectType,
      const std::string_view& str,
      MaterialPBRMetallicRoughness& o);

private:
  MaterialPBRMetallicRoughness* _pObject = nullptr;
  CesiumJsonReader::
      ArrayJsonHandler<double, CesiumJsonReader::DoubleJsonHandler>
          _baseColorFactor;
  TextureInfoJsonHandler _baseColorTexture;
  CesiumJsonReader::DoubleJsonHandler _metallicFactor;
  CesiumJsonReader::DoubleJsonHandler _roughnessFactor;
  TextureInfoJsonHandler _metallicRoughnessTexture;
};
} // namespace CesiumGltf
