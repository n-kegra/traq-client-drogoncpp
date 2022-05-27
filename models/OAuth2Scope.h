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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eread:
            return Json::Value("read");
        case Value::ewrite:
            return Json::Value("write");
        case Value::emanage_bot:
            return Json::Value("manage_bot");
        case Value::Unknown:
            return Json::Value(Json::nullValue);
        }
    }
    OAuth2Scope& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "read") {
            this->value = Value::eread;
        } else
        if (s == "write") {
            this->value = Value::ewrite;
        } else
        if (s == "manage_bot") {
            this->value = Value::emanage_bot;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> traQ::OAuth2Scope Json::Value::as<traQ::OAuth2Scope>() const { return traQ::OAuth2Scope(*this); }

#endif
