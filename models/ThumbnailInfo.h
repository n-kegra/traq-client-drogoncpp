#ifndef _ThumbnailInfo_H
#define _ThumbnailInfo_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ThumbnailType.h"

namespace traQ {

struct ThumbnailInfo {
    ThumbnailType type;
    std::string mime;
    int32_t width;
    int32_t height;

    ThumbnailInfo() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ThumbnailInfo(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["type"] = (type);
        _json["mime"] = (mime);
        _json["width"] = (width);
        _json["height"] = (height);
        return _json;
    }
    ThumbnailInfo& fromJson(const Json::Value& _json) {
        type = _json["type"].as<ThumbnailType>();
        mime = _json["mime"].as<std::string>();
        width = _json["width"].as<int32_t>();
        height = _json["height"].as<int32_t>();
        return *this;
    }
};

}
template <> traQ::ThumbnailInfo Json::Value::as<traQ::ThumbnailInfo>() const { return traQ::ThumbnailInfo(*this); }

#endif
