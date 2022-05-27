#ifndef _OAuth2Token_H
#define _OAuth2Token_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
        _json["accessUnderscoretoken"] = (accessUnderscoretoken);
        _json["tokenUnderscoretype"] = (tokenUnderscoretype);
        _json["expiresUnderscorein"] = (expiresUnderscorein);
        _json["refreshUnderscoretoken"] = (refreshUnderscoretoken);
        _json["scope"] = (scope);
        _json["idUnderscoretoken"] = (idUnderscoretoken);
        return _json;
    }
    OAuth2Token& fromJson(const Json::Value& _json) {
        accessUnderscoretoken = _json["accessUnderscoretoken"].as<std::string>();
        tokenUnderscoretype = _json["tokenUnderscoretype"].as<std::string>();
        expiresUnderscorein = _json["expiresUnderscorein"].as<int32_t>();
        refreshUnderscoretoken = _json["refreshUnderscoretoken"].as<std::string>();
        scope = _json["scope"].as<std::string>();
        idUnderscoretoken = _json["idUnderscoretoken"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::OAuth2Token Json::Value::as<traQ::OAuth2Token>() const { return traQ::OAuth2Token(*this); }

#endif
