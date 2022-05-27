#ifndef _OAuth2Token_H
#define _OAuth2Token_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

struct OAuth2Token {
    std::string accessUnderscoretoken;
    std::string tokenUnderscoretype;
    int32_t expiresUnderscorein;
    std::string refreshUnderscoretoken;
    std::string scope;
    std::string idUnderscoretoken;

    OAuth2Token() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2Token(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    OAuth2Token& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::OAuth2Token Json::Value::as<traQAPI::OAuth2Token>() const;

#endif
