#ifndef _ChannelTopic_H
#define _ChannelTopic_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// チャンネルトピック
struct ChannelTopic {
    std::string topic;

    ChannelTopic() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelTopic(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ChannelTopic& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::ChannelTopic Json::Value::as<traQAPI::ChannelTopic>() const;

#endif
