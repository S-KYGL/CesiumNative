// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltfReader/NamedObjectJsonHandler.h"

#include <CesiumGltf/Skin.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace CesiumGltfReader {
class SkinJsonHandler : public CesiumGltfReader::NamedObjectJsonHandler {
public:
  using ValueType = CesiumGltf::Skin;

  SkinJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, CesiumGltf::Skin* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeySkin(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::Skin& o);

private:
  CesiumGltf::Skin* _pObject = nullptr;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _inverseBindMatrices;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _skeleton;
  CesiumJsonReader::
      ArrayJsonHandler<int32_t, CesiumJsonReader::IntegerJsonHandler<int32_t>>
          _joints;
};
} // namespace CesiumGltfReader