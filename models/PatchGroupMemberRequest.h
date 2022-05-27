#ifndef _PatchGroupMemberRequest_H
#define _PatchGroupMemberRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザーグループメンバー編集リクエスト
struct PatchGroupMemberRequest {
    std::string role;

    PatchGroupMemberRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchGroupMemberRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchGroupMemberRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PatchGroupMemberRequest Json::Value::as<traQ::PatchGroupMemberRequest>() const;

#endif
