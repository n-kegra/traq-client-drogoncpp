#ifndef _ClippedMessage_H
#define _ClippedMessage_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Message.h"

namespace traQAPI {

// クリップされたメッセージ
struct ClippedMessage {
    Message message;
    std::string clippedAt;

    ClippedMessage() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ClippedMessage(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ClippedMessage& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::ClippedMessage Json::Value::as<traQAPI::ClippedMessage>() const;

#endif
