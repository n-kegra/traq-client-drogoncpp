#include <traQ/models/PostWebhookRequest.h>
#include "../Helper.h"

namespace traQApi {

PostWebhookRequest::operator Json::Value() const {
    return this->toJson();
}
PostWebhookRequest::PostWebhookRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PostWebhookRequest Json::Value::as<traQApi::PostWebhookRequest>() const {
    return traQApi::PostWebhookRequest(*this);
};
