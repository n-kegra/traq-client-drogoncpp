#ifndef TRAQ_OgpMedia_H
#define TRAQ_OgpMedia_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// OGPに含まれる画像の情報
struct OgpMedia {
    std::string url;
    std::string secureUrl;
    std::string type;
    int32_t width;
    int32_t height;

    OgpMedia() = default;
    operator Json::Value() const;
    OgpMedia(const Json::Value& __value);

    Json::Value toJson() const;
    OgpMedia& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OgpMedia Json::Value::as<traQApi::OgpMedia>() const;

#endif
