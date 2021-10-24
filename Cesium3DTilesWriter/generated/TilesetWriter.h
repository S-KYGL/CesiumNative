// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <Cesium3DTiles/Tileset.h>
#include <CesiumJsonWriter/ExtensionWriterContext.h>
#include <CesiumJsonWriter/JsonWriter.h>

namespace Cesium3DTiles {

struct TilesetWriter {
  static void write(
      const Tileset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TileWriter {
  static void write(
      const Tile& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ContentWriter {
  static void write(
      const Content& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BoundingVolumeWriter {
  static void write(
      const BoundingVolume& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertiesWriter {
  static void write(
      const Properties& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AssetWriter {
  static void write(
      const Asset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

} // namespace Cesium3DTiles