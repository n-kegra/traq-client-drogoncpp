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

    Json::Value toJson() const {
        Json::Value _json;
        _json["providerName"] = (providerName);
        return _json;
    }
    PostUnlinkExternalAccount& fromJson(const Json::Value& _json) {
        providerName = _json["providerName"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PostUnlinkExternalAccount Json::Value::as<traQ::PostUnlinkExternalAccount>() const { return traQ::PostUnlinkExternalAccount(*this); }

#endif
