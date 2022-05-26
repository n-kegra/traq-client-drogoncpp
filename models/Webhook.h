#ifndef _Webhook_H
#define _Webhook_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    operator Json::Value() const {
        return this->toJson();
    }
    Webhook(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["botUserId"] = (botUserId);
        _json["displayName"] = (displayName);
        _json["description"] = (description);
        _json["secure"] = (secure);
        _json["channelId"] = (channelId);
        _json["ownerId"] = (ownerId);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        return _json;
    }
    Webhook& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        botUserId = _json["botUserId"].as<std::string>();
        displayName = _json["displayName"].as<std::string>();
        description = _json["description"].as<std::string>();
        secure = _json["secure"].as<bool>();
        channelId = _json["channelId"].as<std::string>();
        ownerId = _json["ownerId"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        return *this;
    }
};

}

#endif
