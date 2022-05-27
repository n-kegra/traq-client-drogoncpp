#include "Ogp.h"

namespace traQAPI {

Json::Value Ogp::toJson() const {
    Json::Value _json;
    _json["type"] = (type);
    _json["title"] = (title);
    _json["url"] = (url);
    _json["images"] = Helper::toJson(images);
    _json["description"] = (description);
    _json["videos"] = Helper::toJson(videos);
    return _json;
}
Ogp& Ogp::fromJson(const Json::Value& _json) {
    type = _json["type"].as<std::string>();
    title = _json["title"].as<std::string>();
    url = _json["url"].as<std::string>();
    for (auto _it = _json["images"].begin(); _it != _json["images"].end(); _it++) {
        images.emplace_back((*_it));    
    }
    description = _json["description"].as<std::string>();
    for (auto _it = _json["videos"].begin(); _it != _json["videos"].end(); _it++) {
        videos.emplace_back((*_it));    
    }
    return *this;
}

}
template <> traQAPI::Ogp Json::Value::as<traQAPI::Ogp>() const {
    return traQAPI::Ogp(*this);
}
