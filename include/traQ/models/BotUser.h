#ifndef TRAQ_BotUser_H
#define TRAQ_BotUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// BOTユーザー対
struct BotUser {
    std::string id;
    std::string botUserId;

    BotUser() = default;
    operator Json::Value() const;
    BotUser(const Json::Value& __value);

    Json::Value toJson() const;
    BotUser& fromJson(const Json::Value& _json);
};

}
template <> traQApi::BotUser Json::Value::as<traQApi::BotUser>() const;

#endif
