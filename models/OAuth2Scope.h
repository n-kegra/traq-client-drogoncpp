#ifndef _OAuth2Scope_H
#define _OAuth2Scope_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::OAuth2Scope Json::Value::as<traQ::OAuth2Scope>() const;

#endif
