#ifndef _Webhook_H
#define _Webhook_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

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
    operator Json::Value() const {
        return this->toJson();
    }
    Webhook(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    Webhook& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::Webhook Json::Value::as<traQAPI::Webhook>() const;

#endif
