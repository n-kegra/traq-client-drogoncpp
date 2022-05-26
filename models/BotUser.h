#ifndef _BotUser_H
#define _BotUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// BOTユーザー対
struct BotUser {
    std::string id;
    std::string botUserId;

    operator Json::Value() const {
        return this->toJson();
    }
    BotUser(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["botUserId"] = (botUserId);
        return _json;
    }
    BotUser& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        botUserId = _json["botUserId"].as<std::string>();
        return *this;
    }
};

}

#endif
