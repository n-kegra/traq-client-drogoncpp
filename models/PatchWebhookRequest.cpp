#include "PatchWebhookRequest.h"

namespace traQ {

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
template <> traQ::PatchWebhookRequest Json::Value::as<traQ::PatchWebhookRequest>() const {
    return traQ::PatchWebhookRequest(*this);
}
