#ifndef _OAuth2ClientDetail_H
#define _OAuth2ClientDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OAuth2Scope.h"
#include <vector>

namespace traQAPI {

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
    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2ClientDetail(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    OAuth2ClientDetail& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::OAuth2ClientDetail Json::Value::as<traQAPI::OAuth2ClientDetail>() const;

#endif
