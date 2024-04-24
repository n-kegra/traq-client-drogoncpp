#ifndef TRAQ_OAuth2ClientDetail_H
#define TRAQ_OAuth2ClientDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <traQ/models/OAuth2Scope.h>
#include <vector>

namespace traQApi {

// OAuth2クライアント詳細情報
struct OAuth2ClientDetail {
    std::string id;
    std::string developerId;
    std::string description;
    std::string name;
    std::vector<OAuth2Scope> scopes;
    std::string callbackUrl;
    std::string secret;

    OAuth2ClientDetail() = default;
    operator Json::Value() const;
    OAuth2ClientDetail(const Json::Value& __value);

    Json::Value toJson() const;
    OAuth2ClientDetail& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OAuth2ClientDetail Json::Value::as<traQApi::OAuth2ClientDetail>() const;

#endif
