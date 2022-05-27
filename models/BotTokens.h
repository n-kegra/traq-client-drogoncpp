#ifndef _BotTokens_H
#define _BotTokens_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// BOTのトークン情報
struct BotTokens {
    std::string verificationToken;
    std::string accessToken;

    BotTokens() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    BotTokens(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    BotTokens& fromJson(const Json::Value& _json);
};

}
template <> traQ::BotTokens Json::Value::as<traQ::BotTokens>() const;

#endif
