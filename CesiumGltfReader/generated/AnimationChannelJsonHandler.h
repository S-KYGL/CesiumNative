// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "AnimationChannelTargetJsonHandler.h"
#include "ExtensibleObjectJsonHandler.h"
#include "IntegerJsonHandler.h"
#include <CesiumGltf/Reader.h>

namespace CesiumGltf {
struct AnimationChannel;

class AnimationChannelJsonHandler : public ExtensibleObjectJsonHandler {
public:
  AnimationChannelJsonHandler(const ReadModelOptions& options) noexcept;
  void reset(IJsonHandler* pHandler, AnimationChannel* pObject);
  AnimationChannel* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* Key(const char* str, size_t length, bool copy) override;

protected:
  IJsonHandler* AnimationChannelKey(const char* str, AnimationChannel& o);

private:
  AnimationChannel* _pObject = nullptr;
  IntegerJsonHandler<int32_t> _sampler;
  AnimationChannelTargetJsonHandler _target;
};
} // namespace CesiumGltf
