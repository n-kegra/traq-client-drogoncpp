#ifndef TRAQ_PatchGroupMemberRequest_H
#define TRAQ_PatchGroupMemberRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> inline traQApi::PatchGroupMemberRequest Json::Value::as<traQApi::PatchGroupMemberRequest>() const {
    return traQApi::PatchGroupMemberRequest(*this);
};

#endif
