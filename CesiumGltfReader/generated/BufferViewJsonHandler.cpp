// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "BufferViewJsonHandler.h"
#include "CesiumGltf/BufferView.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

BufferViewJsonHandler::BufferViewJsonHandler(
    const ReaderContext& context) noexcept
    : NamedObjectJsonHandler(context),
      _buffer(),
      _byteOffset(),
      _byteLength(),
      _byteStride(),
      _target() {}

void BufferViewJsonHandler::reset(
    CesiumJsonReader::IJsonReader* pParentReader,
    BufferView* pObject) {
  NamedObjectJsonHandler::reset(pParentReader, pObject);
  this->_pObject = pObject;
}

BufferView* BufferViewJsonHandler::getObject() { return this->_pObject; }

void BufferViewJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

CesiumJsonReader::IJsonReader*
BufferViewJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyBufferView(
      BufferView::TypeName,
      str,
      *this->_pObject);
}

CesiumJsonReader::IJsonReader* BufferViewJsonHandler::readObjectKeyBufferView(
    const std::string& objectType,
    const std::string_view& str,
    BufferView& o) {
  using namespace std::string_literals;

  if ("buffer"s == str)
    return property("buffer", this->_buffer, o.buffer);
  if ("byteOffset"s == str)
    return property("byteOffset", this->_byteOffset, o.byteOffset);
  if ("byteLength"s == str)
    return property("byteLength", this->_byteLength, o.byteLength);
  if ("byteStride"s == str)
    return property("byteStride", this->_byteStride, o.byteStride);
  if ("target"s == str)
    return property("target", this->_target, o.target);

  return this->readObjectKeyNamedObject(objectType, str, *this->_pObject);
}
