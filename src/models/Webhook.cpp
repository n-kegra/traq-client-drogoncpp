#include <traQ/models/Webhook.h>
#include "../Helper.h"

namespace traQApi {

Webhook::operator Json::Value() const {
    return this->toJson();
}
Webhook::Webhook(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::Webhook Json::Value::as<traQApi::Webhook>() const {
    return traQApi::Webhook(*this);
};
