#include "CesiumGltf/Writer.h"
#include "AccessorWriter.h"
#include "AnimationWriter.h"
#include "AssetWriter.h"
#include <iostream>
#include <rapidjson/prettywriter.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <stdexcept>

std::vector<std::byte>
CesiumGltf::writeModelToByteArray(const Model& model, WriteOptions options) {

    std::vector<std::byte> result;
    if (options != (WriteOptions::GLB | WriteOptions::EmbedBuffers |
                    WriteOptions::EmbedImages)) {
        throw std::runtime_error(
            "Unsupported configuration. Only (GLB + "
            "EmbedBuffers + EmbedImages) supported for now.");
    }

    rapidjson::StringBuffer strBuffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strBuffer);
    writer.StartObject();
    CesiumGltf::writeAccessor(model.accessors, writer);
    CesiumGltf::writeAnimation(model.animations, writer);
    CesiumGltf::writeAsset(model.asset, writer);
    // writeMesh
    // writePrimitive
    // writeBuffer...

    writer.EndObject();
    return result;
}