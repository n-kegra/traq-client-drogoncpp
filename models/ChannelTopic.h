#ifndef _ChannelTopic_H
#define _ChannelTopic_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["topic"] = (topic);
        return _json;
    }
    ChannelTopic& fromJson(const Json::Value& _json) {
        topic = _json["topic"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::ChannelTopic Json::Value::as<traQ::ChannelTopic>() const { return traQ::ChannelTopic(*this); }

#endif
