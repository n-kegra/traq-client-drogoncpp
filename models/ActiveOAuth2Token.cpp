#include "ActiveOAuth2Token.h"

namespace traQ {

Json::Value ActiveOAuth2Token::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["clientId"] = (clientId);
    _json["scopes"] = Helper::toJson(scopes);
    _json["issuedAt"] = (issuedAt);
    return _json;
}
ActiveOAuth2Token& ActiveOAuth2Token::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    clientId = _json["clientId"].as<std::string>();
    for (auto _it = _json["scopes"].begin(); _it != _json["scopes"].end(); _it++) {
        scopes.emplace_back((*_it).as<OAuth2Scope>());    
    }
    issuedAt = _json["issuedAt"].as<std::string>();
    return *this;
}

}
template <> traQ::ActiveOAuth2Token Json::Value::as<traQ::ActiveOAuth2Token>() const {
    return traQ::ActiveOAuth2Token(*this);
}