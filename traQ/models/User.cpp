#include <traQ/models/User.h>

namespace traQApi {

User::operator Json::Value() const {
    return this->toJson();
}
User::User(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::User Json::Value::as<traQApi::User>() const {
    return traQApi::User(*this);
};
