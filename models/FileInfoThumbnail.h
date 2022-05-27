#ifndef _FileInfoThumbnail_H
#define _FileInfoThumbnail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// サムネイル情報 サムネイルが存在しない場合はnullになります Deprecated: thumbnailsを参照してください
struct FileInfoThumbnail {
    std::string mime;
    int32_t width;
    int32_t height;

    FileInfoThumbnail() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    FileInfoThumbnail(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["mime"] = (mime);
        _json["width"] = (width);
        _json["height"] = (height);
        return _json;
    }
    FileInfoThumbnail& fromJson(const Json::Value& _json) {
        mime = _json["mime"].as<std::string>();
        width = _json["width"].as<int32_t>();
        height = _json["height"].as<int32_t>();
        return *this;
    }
};

}
template <> traQ::FileInfoThumbnail Json::Value::as<traQ::FileInfoThumbnail>() const { return traQ::FileInfoThumbnail(*this); }

#endif
