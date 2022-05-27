#ifndef _PatchUserGroupRequest_H
#define _PatchUserGroupRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザーグループ編集リクエスト
struct PatchUserGroupRequest {
    std::string name;
    std::string description;
    std::string type;

    PatchUserGroupRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchUserGroupRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        _json["type"] = (type);
        return _json;
    }
    PatchUserGroupRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        type = _json["type"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PatchUserGroupRequest Json::Value::as<traQ::PatchUserGroupRequest>() const { return traQ::PatchUserGroupRequest(*this); }

#endif
