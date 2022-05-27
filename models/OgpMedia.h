#ifndef _OgpMedia_H
#define _OgpMedia_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// OGPに含まれる画像の情報
struct OgpMedia {
    std::string url;
    std::string secureUrl;
    std::string type;
    int32_t width;
    int32_t height;

    OgpMedia() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    OgpMedia(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    OgpMedia& fromJson(const Json::Value& _json);
};

}
template <> traQ::OgpMedia Json::Value::as<traQ::OgpMedia>() const;

#endif
