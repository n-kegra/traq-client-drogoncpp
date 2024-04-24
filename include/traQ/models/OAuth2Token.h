#ifndef TRAQ_OAuth2Token_H
#define TRAQ_OAuth2Token_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

struct OAuth2Token {
    std::string accessUnderscoretoken;
    std::string tokenUnderscoretype;
    int32_t expiresUnderscorein;
    std::string refreshUnderscoretoken;
    std::string scope;
    std::string idUnderscoretoken;

    OAuth2Token() = default;
    operator Json::Value() const;
    OAuth2Token(const Json::Value& __value);

    Json::Value toJson() const;
    OAuth2Token& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OAuth2Token Json::Value::as<traQApi::OAuth2Token>() const;

#endif
