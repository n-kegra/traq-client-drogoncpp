#ifndef TRAQ_ActiveOAuth2Token_H
#define TRAQ_ActiveOAuth2Token_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

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
    operator Json::Value() const;
    ActiveOAuth2Token(const Json::Value& __value);

    Json::Value toJson() const;
    ActiveOAuth2Token& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ActiveOAuth2Token Json::Value::as<traQApi::ActiveOAuth2Token>() const;

#endif
