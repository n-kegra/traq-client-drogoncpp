#ifndef _PostWebhookRequest_H
#define _PostWebhookRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::PostWebhookRequest Json::Value::as<traQ::PostWebhookRequest>() const;

#endif
