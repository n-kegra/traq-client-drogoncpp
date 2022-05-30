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

    Json::Value toJson() const;
    ThumbnailInfo& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ThumbnailInfo Json::Value::as<traQApi::ThumbnailInfo>() const;

#endif
