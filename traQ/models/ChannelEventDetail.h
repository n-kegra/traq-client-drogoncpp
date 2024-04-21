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
    operator Json::Value() const;
    ChannelEventDetail(const Json::Value& __value);

    Json::Value toJson() const;
    ChannelEventDetail& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelEventDetail Json::Value::as<traQApi::ChannelEventDetail>() const;

#endif
