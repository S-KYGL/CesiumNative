// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Reader.h"
#include "CesiumJsonReader/DoubleJsonHandler.h"
#include "ExtensibleObjectJsonHandler.h"

namespace CesiumGltf {
struct ReaderContext;
struct CameraPerspective;

class CameraPerspectiveJsonHandler : public ExtensibleObjectJsonHandler {
public:
  CameraPerspectiveJsonHandler(const ReaderContext& context) noexcept;
  void reset(IJsonReader* pParentReader, CameraPerspective* pObject);
  CameraPerspective* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonReader* readObjectKey(const std::string_view& str) override;

protected:
  IJsonReader* readObjectKeyCameraPerspective(
      const std::string& objectType,
      const std::string_view& str,
      CameraPerspective& o);

private:
  CameraPerspective* _pObject = nullptr;
  CesiumJsonReader::DoubleJsonHandler _aspectRatio;
  CesiumJsonReader::DoubleJsonHandler _yfov;
  CesiumJsonReader::DoubleJsonHandler _zfar;
  CesiumJsonReader::DoubleJsonHandler _znear;
};
} // namespace CesiumGltf
