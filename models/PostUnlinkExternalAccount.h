#ifndef _PostUnlinkExternalAccount_H
#define _PostUnlinkExternalAccount_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::PostUnlinkExternalAccount Json::Value::as<traQ::PostUnlinkExternalAccount>() const;

#endif
