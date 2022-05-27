#ifndef _ActivityTimelineMessage_H
#define _ActivityTimelineMessage_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

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
template <> traQAPI::ActivityTimelineMessage Json::Value::as<traQAPI::ActivityTimelineMessage>() const;

#endif
