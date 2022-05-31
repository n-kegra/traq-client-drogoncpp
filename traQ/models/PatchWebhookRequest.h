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

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        _json["channelId"] = (channelId);
        _json["secret"] = (secret);
        _json["ownerId"] = (ownerId);
        return _json;
    }
    PatchWebhookRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        secret = _json["secret"].as<std::string>();
        ownerId = _json["ownerId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PatchWebhookRequest Json::Value::as<traQApi::PatchWebhookRequest>() const {
    return traQApi::PatchWebhookRequest(*this);
};

#endif
