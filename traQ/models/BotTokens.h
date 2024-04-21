#ifndef TRAQ_BotTokens_H
#define TRAQ_BotTokens_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// BOTのトークン情報
struct BotTokens {
    std::string verificationToken;
    std::string accessToken;

    BotTokens() = default;
    operator Json::Value() const;
    BotTokens(const Json::Value& __value);

    Json::Value toJson() const;
    BotTokens& fromJson(const Json::Value& _json);
};

}
template <> traQApi::BotTokens Json::Value::as<traQApi::BotTokens>() const;

#endif
