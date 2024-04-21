#ifndef TRAQ_PostMessageStampRequest_H
#define TRAQ_PostMessageStampRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// スタンプを押すリクエスト
struct PostMessageStampRequest {
    int32_t count;

    PostMessageStampRequest() = default;
    operator Json::Value() const;
    PostMessageStampRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostMessageStampRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostMessageStampRequest Json::Value::as<traQApi::PostMessageStampRequest>() const;

#endif
