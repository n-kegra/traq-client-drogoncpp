#include <traQ/models/ClipFolder.h>

namespace traQApi {

Json::Value ClipFolder::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["createdAt"] = (createdAt);
    _json["ownerId"] = (ownerId);
    _json["description"] = (description);
    return _json;
}
ClipFolder& ClipFolder::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    name = _json["name"].as<std::string>();
    createdAt = _json["createdAt"].as<std::string>();
    ownerId = _json["ownerId"].as<std::string>();
    description = _json["description"].as<std::string>();
    return *this;
}

}
template <> traQApi::ClipFolder Json::Value::as<traQApi::ClipFolder>() const {
    return traQApi::ClipFolder(*this);
}
