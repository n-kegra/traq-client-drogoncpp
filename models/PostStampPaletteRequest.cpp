#include "PostStampPaletteRequest.h"

namespace traQ {

Json::Value PostStampPaletteRequest::toJson() const {
    Json::Value _json;
    _json["stamps"] = Helper::toJson(stamps);
    _json["name"] = (name);
    _json["description"] = (description);
    return _json;
}
PostStampPaletteRequest& PostStampPaletteRequest::fromJson(const Json::Value& _json) {
    for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
        stamps.emplace_back((*_it).as<std::string>());    
    }
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    return *this;
}

}
template <> traQ::PostStampPaletteRequest Json::Value::as<traQ::PostStampPaletteRequest>() const {
    return traQ::PostStampPaletteRequest(*this);
}
