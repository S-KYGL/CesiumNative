#pragma once

#include <Cesium3DTilesSelection/Exp_TileContent.h>
#include <Cesium3DTilesSelection/Exp_TileContentLoadInfo.h>
#include <Cesium3DTilesSelection/Exp_TileUserDataStorage.h>
#include <CesiumAsync/Future.h>
#include <CesiumAsync/IAssetAccessor.h>

#include <memory>
#include <functional>

namespace Cesium3DTilesSelection {
class Tile;

struct TileLoadResult {
  TileContentKind contentKind;
  TileLoadState state;
  uint16_t httpStatusCode;
  std::function<void(Tile&)> deferredTileInitializer;
};

class TilesetContentLoader {
public:
  virtual ~TilesetContentLoader() = default;

  virtual CesiumAsync::Future<TileLoadResult> loadTileContent(
      TilesetContentLoader& currentLoader,
      const TileContentLoadInfo& loadInfo,
      const std::vector<CesiumAsync::IAssetAccessor::THeader>&
          requestHeaders) = 0;
};
} // namespace Cesium3DTilesSelection
