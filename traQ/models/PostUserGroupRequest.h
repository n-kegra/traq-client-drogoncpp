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
    operator Json::Value() const {
        return this->toJson();
    }
    PostUserGroupRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        _json["type"] = (type);
        return _json;
    }
    PostUserGroupRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        type = _json["type"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostUserGroupRequest Json::Value::as<traQApi::PostUserGroupRequest>() const {
    return traQApi::PostUserGroupRequest(*this);
};

#endif
