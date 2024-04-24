#ifndef TRAQ_OAuth2Client_H
#define TRAQ_OAuth2Client_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <traQ/models/OAuth2Scope.h>
#include <vector>

namespace traQApi {

// OAuth2クライアント情報
struct OAuth2Client {
    std::string id;
    std::string name;
    std::string description;
    std::string developerId;
    std::vector<OAuth2Scope> scopes;

    OAuth2Client() = default;
    operator Json::Value() const;
    OAuth2Client(const Json::Value& __value);

    Json::Value toJson() const;
    OAuth2Client& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OAuth2Client Json::Value::as<traQApi::OAuth2Client>() const;

#endif
