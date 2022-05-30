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

    Json::Value toJson() const;
    PostWebhookRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostWebhookRequest Json::Value::as<traQApi::PostWebhookRequest>() const;

#endif
