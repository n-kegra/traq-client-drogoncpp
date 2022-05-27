#include "User.h"

namespace traQ {

Json::Value User::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["displayName"] = (displayName);
    _json["iconFileId"] = (iconFileId);
    _json["bot"] = (bot);
    _json["state"] = (state);
    _json["updatedAt"] = (updatedAt);
    return _json;
}
User& User::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    name = _json["name"].as<std::string>();
    displayName = _json["displayName"].as<std::string>();
    iconFileId = _json["iconFileId"].as<std::string>();
    bot = _json["bot"].as<bool>();
    state = _json["state"].as<UserAccountState>();
    updatedAt = _json["updatedAt"].as<std::string>();
    return *this;
}

}
template <> traQ::User Json::Value::as<traQ::User>() const {
    return traQ::User(*this);
}
