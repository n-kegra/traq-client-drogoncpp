#ifndef TRAQ_PostUnlinkExternalAccount_H
#define TRAQ_PostUnlinkExternalAccount_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// POST /users/me/ex-accounts/unlink 用リクエストボディ
struct PostUnlinkExternalAccount {
    std::string providerName;

    PostUnlinkExternalAccount() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostUnlinkExternalAccount(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostUnlinkExternalAccount& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostUnlinkExternalAccount Json::Value::as<traQApi::PostUnlinkExternalAccount>() const;

#endif
