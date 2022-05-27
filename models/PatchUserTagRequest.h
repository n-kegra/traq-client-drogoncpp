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

    PatchUserTagRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchUserTagRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchUserTagRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PatchUserTagRequest Json::Value::as<traQ::PatchUserTagRequest>() const;

#endif
