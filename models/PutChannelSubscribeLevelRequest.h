#ifndef _PutChannelSubscribeLevelRequest_H
#define _PutChannelSubscribeLevelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChannelSubscribeLevel.h"

namespace traQAPI {

// チャンネル購読レベル変更リクエスト
struct PutChannelSubscribeLevelRequest {
    ChannelSubscribeLevel level;

    PutChannelSubscribeLevelRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PutChannelSubscribeLevelRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PutChannelSubscribeLevelRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PutChannelSubscribeLevelRequest Json::Value::as<traQAPI::PutChannelSubscribeLevelRequest>() const;

#endif
