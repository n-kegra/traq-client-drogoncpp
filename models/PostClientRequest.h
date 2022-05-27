#ifndef _PostClientRequest_H
#define _PostClientRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OAuth2Scope.h"
#include <vector>

namespace traQ {

// OAuth2クライアント作成リクエスト
struct PostClientRequest {
    std::string name;
    std::string callbackUrl;
    std::vector<OAuth2Scope> scopes;
    std::string description;

    PostClientRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostClientRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["callbackUrl"] = (callbackUrl);
        _json["scopes"] = Helper::toJson(scopes);
        _json["description"] = (description);
        return _json;
    }
    PostClientRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        callbackUrl = _json["callbackUrl"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            scopes.emplace_back((*_it).as<OAuth2Scope>());    
        }
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PostClientRequest Json::Value::as<traQ::PostClientRequest>() const { return traQ::PostClientRequest(*this); }

#endif
