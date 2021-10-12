// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "AccessorSparseJsonHandler.h"
#include "NamedObjectJsonHandler.h"

#include <CesiumGltf/Accessor.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/BoolJsonHandler.h>
#include <CesiumJsonReader/DoubleJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace CesiumGltf {
class ExtensionReaderContext;

class AccessorJsonHandler : public NamedObjectJsonHandler {
public:
  using ValueType = Accessor;

  AccessorJsonHandler(
      const CesiumJsonReader::ExtensionReaderContext& context) noexcept;
  void reset(IJsonHandler* pParentHandler, Accessor* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyAccessor(
      const std::string& objectType,
      const std::string_view& str,
      Accessor& o);

private:
  Accessor* _pObject = nullptr;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _bufferView;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _byteOffset;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _componentType;
  CesiumJsonReader::BoolJsonHandler _normalized;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _count;
  CesiumJsonReader::StringJsonHandler _type;
  CesiumJsonReader::
      ArrayJsonHandler<double, CesiumJsonReader::DoubleJsonHandler>
          _max;
  CesiumJsonReader::
      ArrayJsonHandler<double, CesiumJsonReader::DoubleJsonHandler>
          _min;
  AccessorSparseJsonHandler _sparse;
};
} // namespace CesiumGltf
