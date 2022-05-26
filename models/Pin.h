#ifndef _Pin_H
#define _Pin_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Message.h"

namespace traQ {

// ピン情報(メッセージ本体付き)
struct Pin {
    std::string userId;
    std::string pinnedAt;
    Message message;

    operator Json::Value() const {
        return this->toJson();
    }
    Pin(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["pinnedAt"] = (pinnedAt);
        _json["message"] = (message.toJson());
        return _json;
    }
    Pin& fromJson(const Json::Value& _json) {
        Json::Value _json;
        userId = _json["userId"].as<std::string>();
        pinnedAt = _json["pinnedAt"].as<std::string>();
        message = _json["message"].as<Message>();
        return *this;
    }
};

}

#endif
