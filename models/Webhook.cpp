#include "Webhook.h"

namespace traQAPI {

Json::Value Webhook::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["botUserId"] = (botUserId);
    _json["displayName"] = (displayName);
    _json["description"] = (description);
    _json["secure"] = (secure);
    _json["channelId"] = (channelId);
    _json["ownerId"] = (ownerId);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    return _json;
}
Webhook& Webhook::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    botUserId = _json["botUserId"].as<std::string>();
    displayName = _json["displayName"].as<std::string>();
    description = _json["description"].as<std::string>();
    secure = _json["secure"].as<bool>();
    channelId = _json["channelId"].as<std::string>();
    ownerId = _json["ownerId"].as<std::string>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    return *this;
}

}
template <> traQAPI::Webhook Json::Value::as<traQAPI::Webhook>() const {
    return traQAPI::Webhook(*this);
}
