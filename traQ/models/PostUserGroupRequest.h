#ifndef TRAQ_PostUserGroupRequest_H
#define TRAQ_PostUserGroupRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザーグループ作成リクエスト
struct PostUserGroupRequest {
    std::string name;
    std::string description;
    std::string type;

    PostUserGroupRequest() = default;
    operator Json::Value() const;
    PostUserGroupRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostUserGroupRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostUserGroupRequest Json::Value::as<traQApi::PostUserGroupRequest>() const;

#endif
