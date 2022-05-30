#ifndef TRAQ_PatchWebhookRequest_H
#define TRAQ_PatchWebhookRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// Webhook情報変更リクエスト
struct PatchWebhookRequest {
    std::string name;
    std::string description;
    std::string channelId;
    std::string secret;
    std::string ownerId;

    PatchWebhookRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchWebhookRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchWebhookRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchWebhookRequest Json::Value::as<traQApi::PatchWebhookRequest>() const;

#endif
