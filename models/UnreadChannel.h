#ifndef _UnreadChannel_H
#define _UnreadChannel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// 未読チャンネル情報
struct UnreadChannel {
    std::string channelId;
    int32_t count;
    bool noticeable;
    std::string since;
    std::string updatedAt;

    UnreadChannel() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UnreadChannel(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    UnreadChannel& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::UnreadChannel Json::Value::as<traQAPI::UnreadChannel>() const;

#endif
