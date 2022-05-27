#include "OAuth2Token.h"

namespace traQAPI {

Json::Value OAuth2Token::toJson() const {
    Json::Value _json;
    _json["accessUnderscoretoken"] = (accessUnderscoretoken);
    _json["tokenUnderscoretype"] = (tokenUnderscoretype);
    _json["expiresUnderscorein"] = (expiresUnderscorein);
    _json["refreshUnderscoretoken"] = (refreshUnderscoretoken);
    _json["scope"] = (scope);
    _json["idUnderscoretoken"] = (idUnderscoretoken);
    return _json;
}
OAuth2Token& OAuth2Token::fromJson(const Json::Value& _json) {
    accessUnderscoretoken = _json["accessUnderscoretoken"].as<std::string>();
    tokenUnderscoretype = _json["tokenUnderscoretype"].as<std::string>();
    expiresUnderscorein = _json["expiresUnderscorein"].as<int32_t>();
    refreshUnderscoretoken = _json["refreshUnderscoretoken"].as<std::string>();
    scope = _json["scope"].as<std::string>();
    idUnderscoretoken = _json["idUnderscoretoken"].as<std::string>();
    return *this;
}

}
template <> traQAPI::OAuth2Token Json::Value::as<traQAPI::OAuth2Token>() const {
    return traQAPI::OAuth2Token(*this);
}
