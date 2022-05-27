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

    Json::Value toJson() const {
        Json::Value _json;
        _json["role"] = (role);
        return _json;
    }
    PatchGroupMemberRequest& fromJson(const Json::Value& _json) {
        role = _json["role"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PatchGroupMemberRequest Json::Value::as<traQ::PatchGroupMemberRequest>() const { return traQ::PatchGroupMemberRequest(*this); }

#endif
