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
    operator Json::Value() const;
    PatchUserRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchUserRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchUserRequest Json::Value::as<traQApi::PatchUserRequest>() const;

#endif
