#ifndef _ActiveOAuth2Token_H
#define _ActiveOAuth2Token_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OAuth2Scope.h"
#include <vector>

namespace traQ {

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

    Json::Value toJson() const;
    ActiveOAuth2Token& fromJson(const Json::Value& _json);
};

}
template <> traQ::ActiveOAuth2Token Json::Value::as<traQ::ActiveOAuth2Token>() const;

#endif
