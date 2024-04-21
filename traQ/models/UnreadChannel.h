#ifndef TRAQ_UnreadChannel_H
#define TRAQ_UnreadChannel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// 未読チャンネル情報
struct UnreadChannel {
    std::string channelId;
    int32_t count;
    bool noticeable;
    std::string since;
    std::string updatedAt;
    std::string oldestMessageId;

    UnreadChannel() = default;
    operator Json::Value() const;
    UnreadChannel(const Json::Value& __value);

    Json::Value toJson() const;
    UnreadChannel& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UnreadChannel Json::Value::as<traQApi::UnreadChannel>() const;

#endif
