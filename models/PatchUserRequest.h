#ifndef _PatchUserRequest_H
#define _PatchUserRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserAccountState.h"

namespace traQ {

// ユーザー情報編集リクエスト
struct PatchUserRequest {
    std::string displayName;
    std::string twitterId;
    UserAccountState state;
    std::string role;

    PatchUserRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchUserRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchUserRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PatchUserRequest Json::Value::as<traQ::PatchUserRequest>() const;

#endif
