#ifndef TRAQ_PostLinkExternalAccount_H
#define TRAQ_PostLinkExternalAccount_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// POST /users/me/ex-accounts/link 用リクエストボディ
struct PostLinkExternalAccount {
    std::string providerName;

    PostLinkExternalAccount() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostLinkExternalAccount(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostLinkExternalAccount& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostLinkExternalAccount Json::Value::as<traQApi::PostLinkExternalAccount>() const;

#endif