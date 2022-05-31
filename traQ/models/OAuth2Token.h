#ifndef TRAQ_OAuth2Token_H
#define TRAQ_OAuth2Token_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["access_token"] = (accessUnderscoretoken);
        _json["token_type"] = (tokenUnderscoretype);
        _json["expires_in"] = (expiresUnderscorein);
        _json["refresh_token"] = (refreshUnderscoretoken);
        _json["scope"] = (scope);
        _json["id_token"] = (idUnderscoretoken);
        return _json;
    }
    OAuth2Token& fromJson(const Json::Value& _json) {
        accessUnderscoretoken = _json["access_token"].as<std::string>();
        tokenUnderscoretype = _json["token_type"].as<std::string>();
        expiresUnderscorein = _json["expires_in"].as<int32_t>();
        refreshUnderscoretoken = _json["refresh_token"].as<std::string>();
        scope = _json["scope"].as<std::string>();
        idUnderscoretoken = _json["id_token"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::OAuth2Token Json::Value::as<traQApi::OAuth2Token>() const {
    return traQApi::OAuth2Token(*this);
};

#endif
