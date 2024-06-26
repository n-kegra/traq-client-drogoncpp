#ifndef TRAQ_Webhook_H
#define TRAQ_Webhook_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// Webhook情報
struct Webhook {
    std::string id;
    std::string botUserId;
    std::string displayName;
    std::string description;
    bool secure;
    std::string channelId;
    std::string ownerId;
    std::string createdAt;
    std::string updatedAt;

    Webhook() = default;
    operator Json::Value() const;
    Webhook(const Json::Value& __value);

    Json::Value toJson() const;
    Webhook& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Webhook Json::Value::as<traQApi::Webhook>() const;

#endif
