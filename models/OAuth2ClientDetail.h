#ifndef _OAuth2ClientDetail_H
#define _OAuth2ClientDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OAuth2Scope.h"
#include <vector>

namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["developerId"] = (developerId);
        _json["description"] = (description);
        _json["name"] = (name);
        _json["scopes"] = Helper::toJson(scopes);
        _json["callbackUrl"] = (callbackUrl);
        _json["secret"] = (secret);
        return _json;
    }
    OAuth2ClientDetail& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        developerId = _json["developerId"].as<std::string>();
        description = _json["description"].as<std::string>();
        name = _json["name"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            scopes.emplace_back((*_it).as<OAuth2Scope>());    
        }
        callbackUrl = _json["callbackUrl"].as<std::string>();
        secret = _json["secret"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::OAuth2ClientDetail Json::Value::as<traQ::OAuth2ClientDetail>() const { return traQ::OAuth2ClientDetail(*this); }

#endif
