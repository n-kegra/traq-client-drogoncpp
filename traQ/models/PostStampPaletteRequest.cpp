#include <traQ/models/PostStampPaletteRequest.h>

namespace traQApi {

Json::Value PostStampPaletteRequest::toJson() const {
    Json::Value _json;
    _json["stamps"] = __Helper::toJson(stamps);
    _json["name"] = (name);
    _json["description"] = (description);
    return _json;
}
PostStampPaletteRequest& PostStampPaletteRequest::fromJson(const Json::Value& _json) {
    for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
        stamps.emplace((*_it).as<std::string>());    
    }
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    return *this;
}

}
template <> traQApi::PostStampPaletteRequest Json::Value::as<traQApi::PostStampPaletteRequest>() const {
    return traQApi::PostStampPaletteRequest(*this);
}
