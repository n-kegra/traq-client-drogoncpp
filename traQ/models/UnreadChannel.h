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

    UnreadChannel() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UnreadChannel(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["channelId"] = (channelId);
        _json["count"] = (count);
        _json["noticeable"] = (noticeable);
        _json["since"] = (since);
        _json["updatedAt"] = (updatedAt);
        return _json;
    }
    UnreadChannel& fromJson(const Json::Value& _json) {
        channelId = _json["channelId"].as<std::string>();
        count = _json["count"].as<int32_t>();
        noticeable = _json["noticeable"].as<bool>();
        since = _json["since"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::UnreadChannel Json::Value::as<traQApi::UnreadChannel>() const {
    return traQApi::UnreadChannel(*this);
};

#endif
