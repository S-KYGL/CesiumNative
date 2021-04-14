#pragma once

#include "CesiumJsonReader/JsonReader.h"
#include <cassert>

namespace CesiumJsonReader {
class DoubleJsonHandler : public JsonReader {
public:
  DoubleJsonHandler() noexcept;
  void reset(IJsonReader* pParent, double* pDouble);

  virtual IJsonReader* readInt32(int32_t i) override;
  virtual IJsonReader* readUint32(uint32_t i) override;
  virtual IJsonReader* readInt64(int64_t i) override;
  virtual IJsonReader* readUint64(uint64_t i) override;
  virtual IJsonReader* readDouble(double d) override;

private:
  double* _pDouble = nullptr;
};
} // namespace CesiumJsonReader
