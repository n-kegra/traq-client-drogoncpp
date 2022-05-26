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
        Json::Value _json;
        message = _json["message"].as<Message>();
        clippedAt = _json["clippedAt"].as<std::string>();
        return *this;
    }
};

}

#endif
