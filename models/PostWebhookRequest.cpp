#include "PostWebhookRequest.h"

namespace traQAPI {

Json::Value PostWebhookRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    _json["channelId"] = (channelId);
    _json["secret"] = (secret);
    return _json;
}
PostWebhookRequest& PostWebhookRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    channelId = _json["channelId"].as<std::string>();
    secret = _json["secret"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostWebhookRequest Json::Value::as<traQAPI::PostWebhookRequest>() const {
    return traQAPI::PostWebhookRequest(*this);
}
