#ifndef TRAQ_PostWebhookRequest_H
#define TRAQ_PostWebhookRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// Webhook作成リクエスト
struct PostWebhookRequest {
    std::string name;
    std::string description;
    std::string channelId;
    std::string secret;

    PostWebhookRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostWebhookRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        _json["channelId"] = (channelId);
        _json["secret"] = (secret);
        return _json;
    }
    PostWebhookRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        secret = _json["secret"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostWebhookRequest Json::Value::as<traQApi::PostWebhookRequest>() const {
    return traQApi::PostWebhookRequest(*this);
};

#endif
