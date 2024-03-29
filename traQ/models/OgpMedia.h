#ifndef TRAQ_OgpMedia_H
#define TRAQ_OgpMedia_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["url"] = (url);
        _json["secureUrl"] = (secureUrl);
        _json["type"] = (type);
        _json["width"] = (width);
        _json["height"] = (height);
        return _json;
    }
    OgpMedia& fromJson(const Json::Value& _json) {
        url = _json["url"].as<std::string>();
        secureUrl = _json["secureUrl"].as<std::string>();
        type = _json["type"].as<std::string>();
        width = _json["width"].as<int32_t>();
        height = _json["height"].as<int32_t>();
        return *this;
    }
};

}
template <> inline traQApi::OgpMedia Json::Value::as<traQApi::OgpMedia>() const {
    return traQApi::OgpMedia(*this);
};

#endif
