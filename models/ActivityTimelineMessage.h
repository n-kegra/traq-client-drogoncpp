#ifndef _ActivityTimelineMessage_H
#define _ActivityTimelineMessage_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["userId"] = (userId);
        _json["channelId"] = (channelId);
        _json["content"] = (content);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        return _json;
    }
    ActivityTimelineMessage& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        userId = _json["userId"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        content = _json["content"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::ActivityTimelineMessage Json::Value::as<traQ::ActivityTimelineMessage>() const { return traQ::ActivityTimelineMessage(*this); }

#endif
