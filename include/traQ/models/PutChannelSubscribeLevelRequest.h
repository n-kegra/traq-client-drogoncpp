#ifndef TRAQ_PutChannelSubscribeLevelRequest_H
#define TRAQ_PutChannelSubscribeLevelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <traQ/models/ChannelSubscribeLevel.h>

namespace traQApi {

// チャンネル購読レベル変更リクエスト
struct PutChannelSubscribeLevelRequest {
    ChannelSubscribeLevel level;

    PutChannelSubscribeLevelRequest() = default;
    operator Json::Value() const;
    PutChannelSubscribeLevelRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PutChannelSubscribeLevelRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PutChannelSubscribeLevelRequest Json::Value::as<traQApi::PutChannelSubscribeLevelRequest>() const;

#endif
