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

    operator Json::Value() const {
        return this->toJson();
    }
    UserAccountState(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    UserAccountState& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
