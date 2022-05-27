#ifndef _PostMessageRequest_H
#define _PostMessageRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// メッセージ投稿リクエスト
struct PostMessageRequest {
    std::string content;
    bool embed;

    PostMessageRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostMessageRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostMessageRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostMessageRequest Json::Value::as<traQAPI::PostMessageRequest>() const;

#endif
