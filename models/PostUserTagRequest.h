#ifndef _PostUserTagRequest_H
#define _PostUserTagRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// ユーザータグ追加リクエスト
struct PostUserTagRequest {
    std::string tag;

    PostUserTagRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostUserTagRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostUserTagRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostUserTagRequest Json::Value::as<traQAPI::PostUserTagRequest>() const;

#endif
