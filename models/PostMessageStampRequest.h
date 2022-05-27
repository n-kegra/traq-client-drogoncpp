#ifndef _PostMessageStampRequest_H
#define _PostMessageStampRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// スタンプを押すリクエスト
struct PostMessageStampRequest {
    int32_t count;

    PostMessageStampRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostMessageStampRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostMessageStampRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostMessageStampRequest Json::Value::as<traQAPI::PostMessageStampRequest>() const;

#endif
