#ifndef TRAQ_Message_H
#define TRAQ_Message_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/MessageStamp.h>
#include <vector>

namespace traQApi {

// メッセージ
struct Message {
    std::string id;
    std::string userId;
    std::string channelId;
    std::string content;
    std::string createdAt;
    std::string updatedAt;
    bool pinned;
    std::vector<MessageStamp> stamps;
    std::string threadId;

    Message() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Message(const Json::Value& __value) {
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
        _json["pinned"] = (pinned);
        _json["stamps"] = __Helper::toJson(stamps);
        _json["threadId"] = (threadId);
        return _json;
    }
    Message& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        userId = _json["userId"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        content = _json["content"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        pinned = _json["pinned"].as<bool>();
        for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
            stamps.emplace_back((*_it));    
        }
        threadId = _json["threadId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::Message Json::Value::as<traQApi::Message>() const {
    return traQApi::Message(*this);
};

#endif
