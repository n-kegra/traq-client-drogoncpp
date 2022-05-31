#ifndef TRAQ_PutChannelSubscribeLevelRequest_H
#define TRAQ_PutChannelSubscribeLevelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ChannelSubscribeLevel.h>

namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["level"] = (level);
        return _json;
    }
    PutChannelSubscribeLevelRequest& fromJson(const Json::Value& _json) {
        level = _json["level"].as<ChannelSubscribeLevel>();
        return *this;
    }
};

}
template <> inline traQApi::PutChannelSubscribeLevelRequest Json::Value::as<traQApi::PutChannelSubscribeLevelRequest>() const {
    return traQApi::PutChannelSubscribeLevelRequest(*this);
};

#endif
