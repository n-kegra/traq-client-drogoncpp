#ifndef TRAQ_ChannelEventDetail_H
#define TRAQ_ChannelEventDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ChildCreatedEvent.h>
#include <traQ/models/ForcedNotificationChangedEvent.h>
#include <traQ/models/NameChangedEvent.h>
#include <traQ/models/ParentChangedEvent.h>
#include <traQ/models/PinAddedEvent.h>
#include <traQ/models/PinRemovedEvent.h>
#include <traQ/models/SubscribersChangedEvent.h>
#include <traQ/models/TopicChangedEvent.h>
#include <traQ/models/VisibilityChangedEvent.h>
#include <vector>

namespace traQApi {

// イベント内容
struct ChannelEventDetail {
    std::string userId;
    std::string before;
    std::string after;
    std::vector<std::string> on;
    std::vector<std::string> off;
    std::string messageId;
    bool visibility;
    bool force;
    std::string channelId;

    ChannelEventDetail() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelEventDetail(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["before"] = (before);
        _json["after"] = (after);
        _json["on"] = __Helper::toJson(on);
        _json["off"] = __Helper::toJson(off);
        _json["messageId"] = (messageId);
        _json["visibility"] = (visibility);
        _json["force"] = (force);
        _json["channelId"] = (channelId);
        return _json;
    }
    ChannelEventDetail& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        before = _json["before"].as<std::string>();
        after = _json["after"].as<std::string>();
        for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
            on.emplace_back((*_it).as<std::string>());    
        }
        for (auto _it = _json["off"].begin(); _it != _json["off"].end(); _it++) {
            off.emplace_back((*_it).as<std::string>());    
        }
        messageId = _json["messageId"].as<std::string>();
        visibility = _json["visibility"].as<bool>();
        force = _json["force"].as<bool>();
        channelId = _json["channelId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::ChannelEventDetail Json::Value::as<traQApi::ChannelEventDetail>() const {
    return traQApi::ChannelEventDetail(*this);
};

#endif
