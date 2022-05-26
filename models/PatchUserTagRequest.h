#ifndef _PatchUserTagRequest_H
#define _PatchUserTagRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザーのタグの編集リクエスト
struct PatchUserTagRequest {
    bool isLocked;

    operator Json::Value() const {
        return this->toJson();
    }
    PatchUserTagRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["isLocked"] = (isLocked);
        return _json;
    }
    PatchUserTagRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        isLocked = _json["isLocked"].as<bool>();
        return *this;
    }
};

}

#endif
