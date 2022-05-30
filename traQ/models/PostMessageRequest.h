#ifndef TRAQ_PostMessageRequest_H
#define TRAQ_PostMessageRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> traQApi::PostMessageRequest Json::Value::as<traQApi::PostMessageRequest>() const;

#endif
