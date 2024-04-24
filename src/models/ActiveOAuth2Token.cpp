#include <traQ/models/ActiveOAuth2Token.h>
#include "../Helper.h"

namespace traQApi {

ActiveOAuth2Token::operator Json::Value() const {
    return this->toJson();
}
ActiveOAuth2Token::ActiveOAuth2Token(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value ActiveOAuth2Token::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["clientId"] = (clientId);
    _json["scopes"] = __Helper::toJson(scopes);
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
template <> traQApi::ActiveOAuth2Token Json::Value::as<traQApi::ActiveOAuth2Token>() const {
    return traQApi::ActiveOAuth2Token(*this);
};
