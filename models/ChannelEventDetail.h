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

namespace traQAPI {

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

    Json::Value toJson() const;
    ChannelEventDetail& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::ChannelEventDetail Json::Value::as<traQAPI::ChannelEventDetail>() const;

#endif
