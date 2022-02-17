// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "ExtensionExtStructuralMetadataPropertyMappingPropertyJsonHandler.h"

#include <CesiumGltf/ExtensionExtStructuralMetadataPropertyMapping.h>
#include <CesiumJsonReader/DictionaryJsonHandler.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace CesiumJsonReader {
class ExtensionReaderContext;
}

namespace CesiumGltfReader {
class ExtensionExtStructuralMetadataPropertyMappingJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = CesiumGltf::ExtensionExtStructuralMetadataPropertyMapping;

  ExtensionExtStructuralMetadataPropertyMappingJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(
      IJsonHandler* pParentHandler,
      CesiumGltf::ExtensionExtStructuralMetadataPropertyMapping* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyExtensionExtStructuralMetadataPropertyMapping(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::ExtensionExtStructuralMetadataPropertyMapping& o);

private:
  CesiumGltf::ExtensionExtStructuralMetadataPropertyMapping* _pObject = nullptr;
  CesiumJsonReader::StringJsonHandler _name;
  CesiumJsonReader::StringJsonHandler _classProperty;
  CesiumJsonReader::DictionaryJsonHandler<
      CesiumGltf::ExtensionExtStructuralMetadataPropertyMappingProperty,
      ExtensionExtStructuralMetadataPropertyMappingPropertyJsonHandler>
      _properties;
};
} // namespace CesiumGltfReader
