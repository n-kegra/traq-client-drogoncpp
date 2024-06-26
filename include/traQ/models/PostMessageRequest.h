#ifndef TRAQ_PostMessageRequest_H
#define TRAQ_PostMessageRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// メッセージ投稿リクエスト
struct PostMessageRequest {
    std::string content;
    bool embed;

    PostMessageRequest() = default;
    operator Json::Value() const;
    PostMessageRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostMessageRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostMessageRequest Json::Value::as<traQApi::PostMessageRequest>() const;

#endif
