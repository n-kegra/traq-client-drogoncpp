#ifndef _PostLinkExternalAccount_H
#define _PostLinkExternalAccount_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// POST /users/me/ex-accounts/link 用リクエストボディ
struct PostLinkExternalAccount {
    std::string providerName;

    operator Json::Value() const {
        return this->toJson();
    }
    PostLinkExternalAccount(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["providerName"] = (providerName);
        return _json;
    }
    PostLinkExternalAccount& fromJson(const Json::Value& _json) {
        Json::Value _json;
        providerName = _json["providerName"].as<std::string>();
        return *this;
    }
};

}

#endif
