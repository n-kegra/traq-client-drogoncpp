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

    Json::Value toJson() const {
        Json::Value _json;
        _json["displayName"] = (displayName);
        _json["twitterId"] = (twitterId);
        _json["state"] = (state);
        _json["role"] = (role);
        return _json;
    }
    PatchUserRequest& fromJson(const Json::Value& _json) {
        displayName = _json["displayName"].as<std::string>();
        twitterId = _json["twitterId"].as<std::string>();
        state = _json["state"].as<UserAccountState>();
        role = _json["role"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PatchUserRequest Json::Value::as<traQ::PatchUserRequest>() const { return traQ::PatchUserRequest(*this); }

#endif
