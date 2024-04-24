#ifndef TRAQ_Message_H
#define TRAQ_Message_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

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
    operator Json::Value() const;
    Message(const Json::Value& __value);

    Json::Value toJson() const;
    Message& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Message Json::Value::as<traQApi::Message>() const;

#endif
