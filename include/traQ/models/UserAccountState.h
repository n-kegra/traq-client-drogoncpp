#ifndef TRAQ_UserAccountState_H
#define TRAQ_UserAccountState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// ユーザーアカウント状態 0: 停止 1: 有効 2: 一時停止
struct UserAccountState {
    enum class Value {
        e0,
        e1,
        e2,
        Unknown,
    } value;
    UserAccountState();
    operator Json::Value() const;
    UserAccountState(const Json::Value& __value);
    UserAccountState(const Value __value);

    Json::Value toJson() const;
    UserAccountState& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserAccountState Json::Value::as<traQApi::UserAccountState>() const;

#endif
