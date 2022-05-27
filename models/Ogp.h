#ifndef _Ogp_H
#define _Ogp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OgpMedia.h"
#include <vector>

namespace traQAPI {

// OGPの情報
struct Ogp {
    std::string type;
    std::string title;
    std::string url;
    std::vector<OgpMedia> images;
    std::string description;
    std::vector<OgpMedia> videos;

    Ogp() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Ogp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    Ogp& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::Ogp Json::Value::as<traQAPI::Ogp>() const;

#endif
