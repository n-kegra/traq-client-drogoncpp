#include "PatchWebhookRequest.h"

namespace traQAPI {

Json::Value PatchWebhookRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    _json["channelId"] = (channelId);
    _json["secret"] = (secret);
    _json["ownerId"] = (ownerId);
    return _json;
}
PatchWebhookRequest& PatchWebhookRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    channelId = _json["channelId"].as<std::string>();
    secret = _json["secret"].as<std::string>();
    ownerId = _json["ownerId"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PatchWebhookRequest Json::Value::as<traQAPI::PatchWebhookRequest>() const {
    return traQAPI::PatchWebhookRequest(*this);
}
