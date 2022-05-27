#include "PatchStampPaletteRequest.h"

namespace traQ {

Json::Value PatchStampPaletteRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    _json["stamps"] = Helper::toJson(stamps);
    return _json;
}
PatchStampPaletteRequest& PatchStampPaletteRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
        stamps.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQ::PatchStampPaletteRequest Json::Value::as<traQ::PatchStampPaletteRequest>() const {
    return traQ::PatchStampPaletteRequest(*this);
}
