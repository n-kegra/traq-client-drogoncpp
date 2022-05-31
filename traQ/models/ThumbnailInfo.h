#ifndef TRAQ_ThumbnailInfo_H
#define TRAQ_ThumbnailInfo_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ThumbnailType.h>

namespace traQApi {

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
template <> inline traQApi::ThumbnailInfo Json::Value::as<traQApi::ThumbnailInfo>() const {
    return traQApi::ThumbnailInfo(*this);
};

#endif
