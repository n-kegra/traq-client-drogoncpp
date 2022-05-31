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

    Json::Value toJson() const {
        Json::Value _json;
        _json["providerName"] = (providerName);
        return _json;
    }
    PostLinkExternalAccount& fromJson(const Json::Value& _json) {
        providerName = _json["providerName"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostLinkExternalAccount Json::Value::as<traQApi::PostLinkExternalAccount>() const {
    return traQApi::PostLinkExternalAccount(*this);
};

#endif
