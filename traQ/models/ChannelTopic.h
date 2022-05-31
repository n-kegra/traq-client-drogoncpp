#ifndef TRAQ_ChannelTopic_H
#define TRAQ_ChannelTopic_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> inline traQApi::ChannelTopic Json::Value::as<traQApi::ChannelTopic>() const {
    return traQApi::ChannelTopic(*this);
};

#endif
