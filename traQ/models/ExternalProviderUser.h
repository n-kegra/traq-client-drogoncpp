#ifndef TRAQ_ExternalProviderUser_H
#define TRAQ_ExternalProviderUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> traQApi::ExternalProviderUser Json::Value::as<traQApi::ExternalProviderUser>() const;

#endif
