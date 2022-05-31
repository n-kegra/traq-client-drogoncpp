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
    operator Json::Value() const {
        return this->toJson();
    }
    BotTokens(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["verificationToken"] = (verificationToken);
        _json["accessToken"] = (accessToken);
        return _json;
    }
    BotTokens& fromJson(const Json::Value& _json) {
        verificationToken = _json["verificationToken"].as<std::string>();
        accessToken = _json["accessToken"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::BotTokens Json::Value::as<traQApi::BotTokens>() const {
    return traQApi::BotTokens(*this);
};

#endif
