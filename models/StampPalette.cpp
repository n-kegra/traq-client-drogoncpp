#include "StampPalette.h"

namespace traQ {

Json::Value StampPalette::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["stamps"] = Helper::toJson(stamps);
    _json["creatorId"] = (creatorId);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    _json["description"] = (description);
    return _json;
}
StampPalette& StampPalette::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    name = _json["name"].as<std::string>();
    for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
        stamps.emplace_back((*_it).as<std::string>());    
    }
    creatorId = _json["creatorId"].as<std::string>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    description = _json["description"].as<std::string>();
    return *this;
}

}
template <> traQ::StampPalette Json::Value::as<traQ::StampPalette>() const {
    return traQ::StampPalette(*this);
}
