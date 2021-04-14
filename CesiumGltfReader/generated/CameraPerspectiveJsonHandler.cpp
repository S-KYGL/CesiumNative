// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "CameraPerspectiveJsonHandler.h"
#include "CesiumGltf/CameraPerspective.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

CameraPerspectiveJsonHandler::CameraPerspectiveJsonHandler(
    const ReaderContext& context) noexcept
    : ExtensibleObjectJsonHandler(context),
      _aspectRatio(),
      _yfov(),
      _zfar(),
      _znear() {}

void CameraPerspectiveJsonHandler::reset(
    CesiumJsonReader::IJsonReader* pParentReader,
    CameraPerspective* pObject) {
  ExtensibleObjectJsonHandler::reset(pParentReader, pObject);
  this->_pObject = pObject;
}

CameraPerspective* CameraPerspectiveJsonHandler::getObject() {
  return this->_pObject;
}

void CameraPerspectiveJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

CesiumJsonReader::IJsonReader*
CameraPerspectiveJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeyCameraPerspective(
      CameraPerspective::TypeName,
      str,
      *this->_pObject);
}

CesiumJsonReader::IJsonReader*
CameraPerspectiveJsonHandler::readObjectKeyCameraPerspective(
    const std::string& objectType,
    const std::string_view& str,
    CameraPerspective& o) {
  using namespace std::string_literals;

  if ("aspectRatio"s == str)
    return property("aspectRatio", this->_aspectRatio, o.aspectRatio);
  if ("yfov"s == str)
    return property("yfov", this->_yfov, o.yfov);
  if ("zfar"s == str)
    return property("zfar", this->_zfar, o.zfar);
  if ("znear"s == str)
    return property("znear", this->_znear, o.znear);

  return this->readObjectKeyExtensibleObject(objectType, str, *this->_pObject);
}
