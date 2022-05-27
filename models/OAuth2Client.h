#ifndef _OAuth2Client_H
#define _OAuth2Client_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OAuth2Scope.h"
#include <vector>

namespace traQAPI {

// OAuth2クライアント情報
struct OAuth2Client {
    std::string id;
    std::string name;
    std::string description;
    std::string developerId;
    std::vector<OAuth2Scope> scopes;

    OAuth2Client() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2Client(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    OAuth2Client& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::OAuth2Client Json::Value::as<traQAPI::OAuth2Client>() const;

#endif
