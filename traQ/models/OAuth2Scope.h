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
        case Value::eRead:
            return Json::Value("read");
        case Value::eWrite:
            return Json::Value("write");
        case Value::eManage_bot:
            return Json::Value("manage_bot");
        default:
            return Json::Value(Json::nullValue);
        }
    }
    OAuth2Scope& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "read") {
            this->value = Value::eRead;
        } else
        if (s == "write") {
            this->value = Value::eWrite;
        } else
        if (s == "manage_bot") {
            this->value = Value::eManage_bot;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> inline traQApi::OAuth2Scope Json::Value::as<traQApi::OAuth2Scope>() const {
    return traQApi::OAuth2Scope(*this);
};

#endif
