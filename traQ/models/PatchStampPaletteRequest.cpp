#include <traQ/models/PatchStampPaletteRequest.h>

namespace traQApi {

Json::Value PatchStampPaletteRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    _json["stamps"] = __Helper::toJson(stamps);
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
template <> traQApi::PatchStampPaletteRequest Json::Value::as<traQApi::PatchStampPaletteRequest>() const {
    return traQApi::PatchStampPaletteRequest(*this);
}