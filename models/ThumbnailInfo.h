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

    Json::Value toJson() const;
    ThumbnailInfo& fromJson(const Json::Value& _json);
};

}
template <> traQ::ThumbnailInfo Json::Value::as<traQ::ThumbnailInfo>() const;

#endif
