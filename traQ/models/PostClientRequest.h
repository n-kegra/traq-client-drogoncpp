#ifndef TRAQ_PostClientRequest_H
#define TRAQ_PostClientRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/OAuth2Scope.h>
#include <vector>

namespace traQApi {

// OAuth2クライアント作成リクエスト
struct PostClientRequest {
    std::string name;
    std::string callbackUrl;
    std::vector<OAuth2Scope> scopes;
    std::string description;

    PostClientRequest() = default;
    operator Json::Value() const;
    PostClientRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostClientRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostClientRequest Json::Value::as<traQApi::PostClientRequest>() const;

#endif
