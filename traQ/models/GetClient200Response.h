#ifndef TRAQ_GetClient200Response_H
#define TRAQ_GetClient200Response_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/OAuth2Client.h>
#include <traQ/models/OAuth2ClientDetail.h>
#include <traQ/models/OAuth2Scope.h>
#include <vector>

namespace traQApi {

struct GetClient200Response {
    std::string id;
    std::string name;
    std::string description;
    std::string developerId;
    std::vector<OAuth2Scope> scopes;
    std::string callbackUrl;
    std::string secret;

    GetClient200Response() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    GetClient200Response(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    GetClient200Response& fromJson(const Json::Value& _json);
};

}
template <> traQApi::GetClient200Response Json::Value::as<traQApi::GetClient200Response>() const;

#endif
