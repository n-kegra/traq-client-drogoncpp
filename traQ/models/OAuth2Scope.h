#ifndef TRAQ_OAuth2Scope_H
#define TRAQ_OAuth2Scope_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// OAuth2スコープ
struct OAuth2Scope {
    enum class Value {
        eRead,
        eWrite,
        eManage_bot,
        Unknown,
    } value;
    OAuth2Scope();
    operator Json::Value() const;
    OAuth2Scope(const Json::Value& __value);
    OAuth2Scope(const Value __value);

    Json::Value toJson() const;
    OAuth2Scope& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OAuth2Scope Json::Value::as<traQApi::OAuth2Scope>() const;

#endif
