// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "TextureInfoJsonHandler.h"

#include <CesiumGltf/PropertyTexture.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/DictionaryJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace CesiumGltf {
class PropertyTextureJsonHandler : public TextureInfoJsonHandler {
public:
  using ValueType = PropertyTexture;

  PropertyTextureJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, PropertyTexture* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyPropertyTexture(
      const std::string& objectType,
      const std::string_view& str,
      PropertyTexture& o);

private:
  PropertyTexture* _pObject = nullptr;
  CesiumJsonReader::StringJsonHandler _name;
  CesiumJsonReader::StringJsonHandler _classProperty;
  CesiumJsonReader::DictionaryJsonHandler<
      std::vector<int64_t>,
      CesiumJsonReader::ArrayJsonHandler<
          int64_t,
          CesiumJsonReader::IntegerJsonHandler<int64_t>>>
      _properties;
};
} // namespace CesiumGltf