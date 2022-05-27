#ifndef _ExternalProviderUser_H
#define _ExternalProviderUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["providerName"] = (providerName);
        _json["linkedAt"] = (linkedAt);
        _json["externalName"] = (externalName);
        return _json;
    }
    ExternalProviderUser& fromJson(const Json::Value& _json) {
        providerName = _json["providerName"].as<std::string>();
        linkedAt = _json["linkedAt"].as<std::string>();
        externalName = _json["externalName"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::ExternalProviderUser Json::Value::as<traQ::ExternalProviderUser>() const { return traQ::ExternalProviderUser(*this); }

#endif
