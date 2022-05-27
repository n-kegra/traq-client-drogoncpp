#ifndef _ClippedMessage_H
#define _ClippedMessage_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Message.h"

namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["message"] = (message.toJson());
        _json["clippedAt"] = (clippedAt);
        return _json;
    }
    ClippedMessage& fromJson(const Json::Value& _json) {
        message.fromJson(_json["message"]);
        clippedAt = _json["clippedAt"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::ClippedMessage Json::Value::as<traQ::ClippedMessage>() const { return traQ::ClippedMessage(*this); }

#endif
