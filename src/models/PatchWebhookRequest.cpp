#include <traQ/models/PatchWebhookRequest.h>
#include "../Helper.h"

namespace traQApi {

PatchWebhookRequest::operator Json::Value() const {
    return this->toJson();
}
PatchWebhookRequest::PatchWebhookRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PatchWebhookRequest Json::Value::as<traQApi::PatchWebhookRequest>() const {
    return traQApi::PatchWebhookRequest(*this);
};
