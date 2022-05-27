#ifndef _BotUser_H
#define _BotUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// BOTユーザー対
struct BotUser {
    std::string id;
    std::string botUserId;

    BotUser() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    BotUser(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    BotUser& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::BotUser Json::Value::as<traQAPI::BotUser>() const;

#endif
