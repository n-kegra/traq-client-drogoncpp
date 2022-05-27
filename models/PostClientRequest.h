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

    Json::Value toJson() const;
    PostClientRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PostClientRequest Json::Value::as<traQ::PostClientRequest>() const;

#endif
