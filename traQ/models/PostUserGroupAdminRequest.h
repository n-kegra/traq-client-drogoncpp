#ifndef TRAQ_PostUserGroupAdminRequest_H
#define TRAQ_PostUserGroupAdminRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// グループ管理者追加リクエスト
struct PostUserGroupAdminRequest {
    std::string id;

    PostUserGroupAdminRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostUserGroupAdminRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        return _json;
    }
    PostUserGroupAdminRequest& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostUserGroupAdminRequest Json::Value::as<traQApi::PostUserGroupAdminRequest>() const {
    return traQApi::PostUserGroupAdminRequest(*this);
};

#endif
