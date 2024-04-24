#ifndef TRAQ_PatchGroupMemberRequest_H
#define TRAQ_PatchGroupMemberRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// ユーザーグループメンバー編集リクエスト
struct PatchGroupMemberRequest {
    std::string role;

    PatchGroupMemberRequest() = default;
    operator Json::Value() const;
    PatchGroupMemberRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchGroupMemberRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchGroupMemberRequest Json::Value::as<traQApi::PatchGroupMemberRequest>() const;

#endif
