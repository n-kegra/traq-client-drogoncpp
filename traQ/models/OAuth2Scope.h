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
        eread,
        ewrite,
        emanage_bot,
        Unknown,
    } value;
    OAuth2Scope() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2Scope(const Json::Value& __value) {
        this->fromJson(__value);
    }
    OAuth2Scope(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    OAuth2Scope& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OAuth2Scope Json::Value::as<traQApi::OAuth2Scope>() const;

#endif
