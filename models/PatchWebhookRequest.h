#ifndef _PatchWebhookRequest_H
#define _PatchWebhookRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::PatchWebhookRequest Json::Value::as<traQ::PatchWebhookRequest>() const;

#endif
