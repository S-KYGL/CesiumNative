// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!

#include "TilesetWriter.h"

#include <CesiumJsonWriter/ExtensionWriterContext.h>
#include <CesiumJsonWriter/ExtensionsWriter.h>
#include <CesiumJsonWriter/JsonWriter.h>

using namespace CesiumJsonWriter;
using namespace CesiumUtility;

namespace Cesium3DTiles {

namespace {

void writeJson(
    const Asset& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context);

void writeJson(
    const BoundingVolume& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context);

void writeJson(
    const Content& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context);

void writeJson(
    const Tile& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context);

void writeJson(
    const Properties& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context);

void writeJson(
    const Tileset& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context);

[[maybe_unused]] void writeJson(
    const std::string& str,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& /* context */) {
  jsonWriter.String(str);
}

[[maybe_unused]] void writeJson(
    double val,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& /* context */) {
  jsonWriter.Double(val);
}

[[maybe_unused]] void writeJson(
    bool val,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& /* context */) {
  jsonWriter.Bool(val);
}

[[maybe_unused]] void writeJson(
    int64_t val,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& /* context */) {
  jsonWriter.Int64(val);
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::vector<T>& list,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  jsonWriter.StartArray();
  for (const T& item : list) {
    writeJson(item, jsonWriter, context);
  }
  jsonWriter.EndArray();
}

template <typename... Ts>
[[maybe_unused]] void writeJson(
    const std::variant<Ts...>& val,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  std::visit(
      [&jsonWriter, &context](const auto& arg) {
        writeJson(arg, jsonWriter, context);
      },
      val);
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::optional<T>& val,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  if (val.has_value()) {
    writeJson(*val, jsonWriter, context);
  } else {
    jsonWriter.Null();
  }
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::unordered_map<std::string, T>& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  jsonWriter.StartObject();
  for (const auto& item : obj) {
    jsonWriter.Key(item.first);
    writeJson(item.second, jsonWriter, context);
  }
  jsonWriter.EndObject();
}
} // namespace

/////////////////////////////////////////
// Writer for Asset
/////////////////////////////////////////

namespace {
void writeJson(
    const Asset& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("version");
  writeJson(obj.version, jsonWriter, context);

  if (obj.tilesetVersion.has_value()) {
    jsonWriter.Key("tilesetVersion");
    writeJson(obj.tilesetVersion, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  jsonWriter.EndObject();
}
} // namespace

void AssetWriter::write(
    const Asset& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

/////////////////////////////////////////
// Writer for BoundingVolume
/////////////////////////////////////////

namespace {
void writeJson(
    const BoundingVolume& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  if (!obj.box.empty()) {
    jsonWriter.Key("box");
    writeJson(obj.box, jsonWriter, context);
  }

  if (!obj.region.empty()) {
    jsonWriter.Key("region");
    writeJson(obj.region, jsonWriter, context);
  }

  if (!obj.sphere.empty()) {
    jsonWriter.Key("sphere");
    writeJson(obj.sphere, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  jsonWriter.EndObject();
}
} // namespace

void BoundingVolumeWriter::write(
    const BoundingVolume& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

/////////////////////////////////////////
// Writer for Content
/////////////////////////////////////////

namespace {
void writeJson(
    const Content& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  if (obj.boundingVolume.has_value()) {
    jsonWriter.Key("boundingVolume");
    writeJson(obj.boundingVolume, jsonWriter, context);
  }

  jsonWriter.Key("uri");
  writeJson(obj.uri, jsonWriter, context);

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  jsonWriter.EndObject();
}
} // namespace

void ContentWriter::write(
    const Content& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

/////////////////////////////////////////
// Writer for Tile
/////////////////////////////////////////

namespace {
void writeJson(
    const Tile& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("boundingVolume");
  writeJson(obj.boundingVolume, jsonWriter, context);

  if (obj.viewerRequestVolume.has_value()) {
    jsonWriter.Key("viewerRequestVolume");
    writeJson(obj.viewerRequestVolume, jsonWriter, context);
  }

  jsonWriter.Key("geometricError");
  writeJson(obj.geometricError, jsonWriter, context);

  if (obj.refine.has_value()) {
    jsonWriter.Key("refine");
    writeJson(obj.refine, jsonWriter, context);
  }

  jsonWriter.Key("transform");
  writeJson(obj.transform, jsonWriter, context);

  if (obj.content.has_value()) {
    jsonWriter.Key("content");
    writeJson(obj.content, jsonWriter, context);
  }

  if (!obj.children.empty()) {
    jsonWriter.Key("children");
    writeJson(obj.children, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  jsonWriter.EndObject();
}
} // namespace

void TileWriter::write(
    const Tile& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

/////////////////////////////////////////
// Writer for Properties
/////////////////////////////////////////

namespace {
void writeJson(
    const Properties& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("maximum");
  writeJson(obj.maximum, jsonWriter, context);

  jsonWriter.Key("minimum");
  writeJson(obj.minimum, jsonWriter, context);

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  jsonWriter.EndObject();
}
} // namespace

void PropertiesWriter::write(
    const Properties& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

/////////////////////////////////////////
// Writer for Tileset
/////////////////////////////////////////

namespace {
void writeJson(
    const Tileset& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("asset");
  writeJson(obj.asset, jsonWriter, context);

  if (!obj.properties.empty()) {
    jsonWriter.Key("properties");
    writeJson(obj.properties, jsonWriter, context);
  }

  jsonWriter.Key("geometricError");
  writeJson(obj.geometricError, jsonWriter, context);

  jsonWriter.Key("root");
  writeJson(obj.root, jsonWriter, context);

  if (!obj.extensionsUsed.empty()) {
    jsonWriter.Key("extensionsUsed");
    writeJson(obj.extensionsUsed, jsonWriter, context);
  }

  if (!obj.extensionsRequired.empty()) {
    jsonWriter.Key("extensionsRequired");
    writeJson(obj.extensionsRequired, jsonWriter, context);
  }

  if (!obj.extensions.empty()) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  jsonWriter.EndObject();
}
} // namespace

void TilesetWriter::write(
    const Tileset& obj,
    JsonWriter& jsonWriter,
    const ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

} // namespace Cesium3DTiles
