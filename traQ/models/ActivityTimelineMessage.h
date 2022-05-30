#ifndef TRAQ_ActivityTimelineMessage_H
#define TRAQ_ActivityTimelineMessage_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


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
    operator Json::Value() const {
        return this->toJson();
    }
    ActivityTimelineMessage(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ActivityTimelineMessage& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ActivityTimelineMessage Json::Value::as<traQApi::ActivityTimelineMessage>() const;

#endif
