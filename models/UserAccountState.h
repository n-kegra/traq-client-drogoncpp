#ifndef _UserAccountState_H
#define _UserAccountState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const;
    UserAccountState& fromJson(const Json::Value& _json);
};

}
template <> traQ::UserAccountState Json::Value::as<traQ::UserAccountState>() const;

#endif
