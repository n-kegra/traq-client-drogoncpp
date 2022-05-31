#ifndef TRAQ_UserAccountState_H
#define TRAQ_UserAccountState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザーアカウント状態 0: 停止 1: 有効 2: 一時停止
struct UserAccountState {
    enum class Value {
        e0,
        e1,
        e2,
        Unknown,
    } value;
    UserAccountState() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    UserAccountState(const Json::Value& __value) {
        this->fromJson(__value);
    }
    UserAccountState(const Value __value) : value(__value) {}

    Json::Value toJson() const {
        switch(this->value) {
        case Value::e0:
            return Json::Value(0);
        case Value::e1:
            return Json::Value(1);
        case Value::e2:
            return Json::Value(2);
        default:
            return Json::Value(Json::nullValue);
        }
    }
    UserAccountState& fromJson(const Json::Value& _json) {
        auto s = _json.asLargestInt();
        if (s == 0) {
            this->value = Value::e0;
        } else
        if (s == 1) {
            this->value = Value::e1;
        } else
        if (s == 2) {
            this->value = Value::e2;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> inline traQApi::UserAccountState Json::Value::as<traQApi::UserAccountState>() const {
    return traQApi::UserAccountState(*this);
};

#endif
