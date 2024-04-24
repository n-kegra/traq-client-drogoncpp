#ifndef TRAQ_ActivityTimelineMessage_H
#define TRAQ_ActivityTimelineMessage_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// Timelineアクテビティ用メッセージ
struct ActivityTimelineMessage {
    std::string id;
    std::string userId;
    std::string channelId;
    std::string content;
    std::string createdAt;
    std::string updatedAt;

    ActivityTimelineMessage() = default;
    operator Json::Value() const;
    ActivityTimelineMessage(const Json::Value& __value);

    Json::Value toJson() const;
    ActivityTimelineMessage& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ActivityTimelineMessage Json::Value::as<traQApi::ActivityTimelineMessage>() const;

#endif
