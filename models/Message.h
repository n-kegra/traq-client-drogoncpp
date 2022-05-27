#ifndef _Message_H
#define _Message_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/MessageStamp.h"
#include <vector>

namespace traQ {

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

    Json::Value toJson() const;
    Message& fromJson(const Json::Value& _json);
};

}
template <> traQ::Message Json::Value::as<traQ::Message>() const;

#endif
