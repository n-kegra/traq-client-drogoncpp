#include <traQ/models/OAuth2Token.h>

namespace traQApi {

OAuth2Token::operator Json::Value() const {
    return this->toJson();
}
OAuth2Token::OAuth2Token(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value OAuth2Token::toJson() const {
    Json::Value _json;
    _json["access_token"] = (accessUnderscoretoken);
    _json["token_type"] = (tokenUnderscoretype);
    _json["expires_in"] = (expiresUnderscorein);
    _json["refresh_token"] = (refreshUnderscoretoken);
    _json["scope"] = (scope);
    _json["id_token"] = (idUnderscoretoken);
    return _json;
}
OAuth2Token& OAuth2Token::fromJson(const Json::Value& _json) {
    accessUnderscoretoken = _json["access_token"].as<std::string>();
    tokenUnderscoretype = _json["token_type"].as<std::string>();
    expiresUnderscorein = _json["expires_in"].as<int32_t>();
    refreshUnderscoretoken = _json["refresh_token"].as<std::string>();
    scope = _json["scope"].as<std::string>();
    idUnderscoretoken = _json["id_token"].as<std::string>();
    return *this;
}

}
template <> traQApi::OAuth2Token Json::Value::as<traQApi::OAuth2Token>() const {
    return traQApi::OAuth2Token(*this);
};
