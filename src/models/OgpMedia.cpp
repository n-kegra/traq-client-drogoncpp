#include <traQ/models/OgpMedia.h>
#include "../Helper.h"

namespace traQApi {

OgpMedia::operator Json::Value() const {
    return this->toJson();
}
OgpMedia::OgpMedia(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value OgpMedia::toJson() const {
    Json::Value _json;
    _json["url"] = (url);
    _json["secureUrl"] = (secureUrl);
    _json["type"] = (type);
    _json["width"] = (width);
    _json["height"] = (height);
    return _json;
}
OgpMedia& OgpMedia::fromJson(const Json::Value& _json) {
    url = _json["url"].as<std::string>();
    secureUrl = _json["secureUrl"].as<std::string>();
    type = _json["type"].as<std::string>();
    width = _json["width"].as<int32_t>();
    height = _json["height"].as<int32_t>();
    return *this;
}

}
template <> traQApi::OgpMedia Json::Value::as<traQApi::OgpMedia>() const {
    return traQApi::OgpMedia(*this);
};
