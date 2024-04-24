#ifndef TRAQ_ChannelTopic_H
#define TRAQ_ChannelTopic_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// チャンネルトピック
struct ChannelTopic {
    std::string topic;

    ChannelTopic() = default;
    operator Json::Value() const;
    ChannelTopic(const Json::Value& __value);

    Json::Value toJson() const;
    ChannelTopic& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelTopic Json::Value::as<traQApi::ChannelTopic>() const;

#endif
