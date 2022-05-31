#ifndef TRAQ_ActiveOAuth2Token_H
#define TRAQ_ActiveOAuth2Token_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/OAuth2Scope.h>
#include <vector>

namespace traQApi {

// 有効なOAuth2トークン情報
struct ActiveOAuth2Token {
    std::string id;
    std::string clientId;
    std::vector<OAuth2Scope> scopes;
    std::string issuedAt;

    ActiveOAuth2Token() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ActiveOAuth2Token(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["clientId"] = (clientId);
        _json["scopes"] = __Helper::toJson(scopes);
        _json["issuedAt"] = (issuedAt);
        return _json;
    }
    ActiveOAuth2Token& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        clientId = _json["clientId"].as<std::string>();
        for (auto _it = _json["scopes"].begin(); _it != _json["scopes"].end(); _it++) {
            scopes.emplace_back((*_it).as<OAuth2Scope>());    
        }
        issuedAt = _json["issuedAt"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::ActiveOAuth2Token Json::Value::as<traQApi::ActiveOAuth2Token>() const {
    return traQApi::ActiveOAuth2Token(*this);
};

#endif
