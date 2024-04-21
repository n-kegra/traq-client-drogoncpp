#ifndef TRAQ_Ogp_H
#define TRAQ_Ogp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/OgpMedia.h>
#include <vector>

namespace traQApi {

// OGPの情報
struct Ogp {
    std::string type;
    std::string title;
    std::string url;
    std::vector<OgpMedia> images;
    std::string description;
    std::vector<OgpMedia> videos;

    Ogp() = default;
    operator Json::Value() const;
    Ogp(const Json::Value& __value);

    Json::Value toJson() const;
    Ogp& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Ogp Json::Value::as<traQApi::Ogp>() const;

#endif
