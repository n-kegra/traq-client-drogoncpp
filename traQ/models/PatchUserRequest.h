#ifndef TRAQ_PatchUserRequest_H
#define TRAQ_PatchUserRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/UserAccountState.h>

namespace traQApi {

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
template <> inline traQApi::PatchUserRequest Json::Value::as<traQApi::PatchUserRequest>() const {
    return traQApi::PatchUserRequest(*this);
};

#endif
