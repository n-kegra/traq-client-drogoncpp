#ifndef _ChannelEventDetail_H
#define _ChannelEventDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChildCreatedEvent.h"
#include "../models/ForcedNotificationChangedEvent.h"
#include "../models/NameChangedEvent.h"
#include "../models/ParentChangedEvent.h"
#include "../models/PinAddedEvent.h"
#include "../models/PinRemovedEvent.h"
#include "../models/SubscribersChangedEvent.h"
#include "../models/TopicChangedEvent.h"
#include "../models/VisibilityChangedEvent.h"
#include <vector>

namespace traQ {

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
        _json["on"] = Helper::toJson(on);
        _json["off"] = Helper::toJson(off);
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
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            on.emplace_back((*_it).as<std::string>());    
        }
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
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
template <> traQ::ChannelEventDetail Json::Value::as<traQ::ChannelEventDetail>() const { return traQ::ChannelEventDetail(*this); }

#endif
