#include <traQ/models/PatchStampPaletteRequest.h>
#include "../Helper.h"

namespace traQApi {

PatchStampPaletteRequest::operator Json::Value() const {
    return this->toJson();
}
PatchStampPaletteRequest::PatchStampPaletteRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
        stamps.emplace((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQApi::PatchStampPaletteRequest Json::Value::as<traQApi::PatchStampPaletteRequest>() const {
    return traQApi::PatchStampPaletteRequest(*this);
};
