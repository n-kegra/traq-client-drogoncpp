#ifndef TRAQ_PostChannelRequest_H
#define TRAQ_PostChannelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// チャンネル作成リクエスト
struct PostChannelRequest {
    std::string name;
    std::string parent;

    PostChannelRequest() = default;
    operator Json::Value() const;
    PostChannelRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostChannelRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostChannelRequest Json::Value::as<traQApi::PostChannelRequest>() const;

#endif
