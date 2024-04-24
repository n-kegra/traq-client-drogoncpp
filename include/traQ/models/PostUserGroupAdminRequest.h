#ifndef TRAQ_PostUserGroupAdminRequest_H
#define TRAQ_PostUserGroupAdminRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// グループ管理者追加リクエスト
struct PostUserGroupAdminRequest {
    std::string id;

    PostUserGroupAdminRequest() = default;
    operator Json::Value() const;
    PostUserGroupAdminRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostUserGroupAdminRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostUserGroupAdminRequest Json::Value::as<traQApi::PostUserGroupAdminRequest>() const;

#endif
