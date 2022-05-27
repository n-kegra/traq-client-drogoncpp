#ifndef _ExternalProviderUser_H
#define _ExternalProviderUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// 外部認証アカウントユーザー
struct ExternalProviderUser {
    std::string providerName;
    std::string linkedAt;
    std::string externalName;

    ExternalProviderUser() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ExternalProviderUser(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ExternalProviderUser& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::ExternalProviderUser Json::Value::as<traQAPI::ExternalProviderUser>() const;

#endif
