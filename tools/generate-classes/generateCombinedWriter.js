const fs = require("fs");
const path = require("path");

const getNameFromSchema = require("./getNameFromSchema");
const unindent = require("./unindent");

function generateCombinedWriter(options) {
  const {
    writerOutputDir,
    config,
    namespace,
    writerNamespace,
    rootSchema,
    writers,
    extensions,
  } = options;

  const name = getNameFromSchema(config, rootSchema);

  const header = `
        // This file was generated by generate-classes.
        // DO NOT EDIT THIS FILE!
        #pragma once

        // forward declarations
        namespace CesiumJsonWriter {
          class JsonWriter;
          class ExtensionWriterContext;
        } // namespace CesiumJsonWriter

        // forward declarations
        namespace ${namespace} {
          ${writers
            .map((writer) => {
              return writer.writeForwardDeclaration;
            })
            .join("\n")}
        } // namespace ${namespace}

        namespace ${writerNamespace} {          
          ${writers
            .map((writer) => {
              return writer.writeDeclaration;
            })
            .join("\n")}

        void registerExtensions(CesiumJsonWriter::ExtensionWriterContext& context); 

        } // namespace ${writerNamespace}
  `;

  const implementation = `
        // This file was generated by generate-classes.
        // DO NOT EDIT THIS FILE!
        
        #include "${name}JsonWriter.h"
        
        #include <CesiumJsonWriter/ExtensionWriterContext.h>
        #include <CesiumJsonWriter/writeJsonExtensions.h>
        #include <CesiumJsonWriter/JsonObjectWriter.h>
        #include <CesiumJsonWriter/JsonWriter.h>

        ${writers
          .map((writer) => {
            return writer.writeInclude;
          })
          .join("\n")}
        
        namespace ${writerNamespace} {
        
        namespace {
        
        ${writers
          .map((writer) => {
            return writer.writeJsonDeclaration;
          })
          .join("\n")}
        
        [[maybe_unused]] void writeJson(
            const std::string& str,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
          jsonWriter.String(str);
        }
        
        [[maybe_unused]] void writeJson(
            double val,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
          jsonWriter.Double(val);
        }
        
        [[maybe_unused]] void writeJson(
            bool val,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
          jsonWriter.Bool(val);
        }
        
        [[maybe_unused]] void writeJson(
            int64_t val,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
          jsonWriter.Int64(val);
        }

        [[maybe_unused]] void writeJson(
            int32_t val,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
          jsonWriter.Int64(val);
        }
        
        [[maybe_unused]] void writeJson(
            const CesiumUtility::JsonValue::Object& obj,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
          jsonWriter.StartObject();
          for (const auto& item : obj) {
            jsonWriter.Key(item.first);
            writeJsonValue(item.second, jsonWriter);
          }
          jsonWriter.EndObject();
        }
        
        [[maybe_unused]] void writeJson(
            const CesiumUtility::JsonValue& value,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
          writeJsonValue(value, jsonWriter);
        }      

        template <typename T>
        [[maybe_unused]] void writeJson(
            const std::map<std::string, T>& obj,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& context) {
          jsonWriter.StartObject();
          for (const auto& item : obj) {
            jsonWriter.Key(item.first);
            writeJson(item.second, jsonWriter, context);
          }
          jsonWriter.EndObject();
        }

        template <typename T>
        [[maybe_unused]] void writeJson(
            const std::vector<T>& list,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& context) {
          jsonWriter.StartArray();
          for (const T& item : list) {
            writeJson(item, jsonWriter, context);
          }
          jsonWriter.EndArray();
        }
        
        template <typename T>
        [[maybe_unused]] void writeJson(
            const std::optional<T>& val,
            CesiumJsonWriter::JsonWriter& jsonWriter,
            const CesiumJsonWriter::ExtensionWriterContext& context) {
          if (val.has_value()) {
            writeJson(*val, jsonWriter, context);
          } else {
            jsonWriter.Null();
          }
        }
        
        ${writers
          .map((writer) => {
            return writer.writeJsonDefinition;
          })
          .join("\n")}

        } // namespace ${writerNamespace}

        ${writers
          .map((writer) => {
            return writer.writeDefinition;
          })
          .join("\n")}
        
        void registerExtensions(CesiumJsonWriter::ExtensionWriterContext& context) {
          (void)context;
          ${writers
            .map((writer) => {
              return writer.writeExtensionsRegistration;
            })
            .join("\n")}
        }
        } // namespace ${writerNamespace}
  
  `;

  const writerHeaderOutputDir = path.join(
    writerOutputDir,
    "generated",
    "src",
    writerNamespace
  );
  fs.mkdirSync(writerHeaderOutputDir, { recursive: true });

  const headerOutputPath = path.join(
    writerHeaderOutputDir,
    `${name}JsonWriter.h`
  );

  const implementationOutputPath = path.join(
    writerHeaderOutputDir,
    `${name}JsonWriter.cpp`
  );

  fs.writeFileSync(headerOutputPath, unindent(header), "utf-8");
  fs.writeFileSync(implementationOutputPath, unindent(implementation), "utf-8");
}

module.exports = generateCombinedWriter;
