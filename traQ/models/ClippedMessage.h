#ifndef TRAQ_ClippedMessage_H
#define TRAQ_ClippedMessage_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Message.h>

namespace traQApi {

// クリップされたメッセージ
struct ClippedMessage {
    Message message;
    std::string clippedAt;

    ClippedMessage() = default;
    operator Json::Value() const;
    ClippedMessage(const Json::Value& __value);

    Json::Value toJson() const;
    ClippedMessage& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ClippedMessage Json::Value::as<traQApi::ClippedMessage>() const;

#endif
