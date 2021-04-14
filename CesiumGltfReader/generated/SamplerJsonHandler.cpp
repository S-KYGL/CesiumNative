// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#include "SamplerJsonHandler.h"
#include "CesiumGltf/Sampler.h"

#include <cassert>
#include <string>

using namespace CesiumGltf;

SamplerJsonHandler::SamplerJsonHandler(const ReaderContext& context) noexcept
    : NamedObjectJsonHandler(context),
      _magFilter(),
      _minFilter(),
      _wrapS(),
      _wrapT() {}

void SamplerJsonHandler::reset(
    CesiumJsonReader::IJsonReader* pParentReader,
    Sampler* pObject) {
  NamedObjectJsonHandler::reset(pParentReader, pObject);
  this->_pObject = pObject;
}

Sampler* SamplerJsonHandler::getObject() { return this->_pObject; }

void SamplerJsonHandler::reportWarning(
    const std::string& warning,
    std::vector<std::string>&& context) {
  if (this->getCurrentKey()) {
    context.emplace_back(std::string(".") + this->getCurrentKey());
  }
  this->parent()->reportWarning(warning, std::move(context));
}

CesiumJsonReader::IJsonReader*
SamplerJsonHandler::readObjectKey(const std::string_view& str) {
  assert(this->_pObject);
  return this->readObjectKeySampler(Sampler::TypeName, str, *this->_pObject);
}

CesiumJsonReader::IJsonReader* SamplerJsonHandler::readObjectKeySampler(
    const std::string& objectType,
    const std::string_view& str,
    Sampler& o) {
  using namespace std::string_literals;

  if ("magFilter"s == str)
    return property("magFilter", this->_magFilter, o.magFilter);
  if ("minFilter"s == str)
    return property("minFilter", this->_minFilter, o.minFilter);
  if ("wrapS"s == str)
    return property("wrapS", this->_wrapS, o.wrapS);
  if ("wrapT"s == str)
    return property("wrapT", this->_wrapT, o.wrapT);

  return this->readObjectKeyNamedObject(objectType, str, *this->_pObject);
}
