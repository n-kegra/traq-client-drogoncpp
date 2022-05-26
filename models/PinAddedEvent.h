#ifndef _PinAddedEvent_H
#define _PinAddedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ピン追加イベント
struct PinAddedEvent {
    std::string userId;
    std::string messageId;

    operator Json::Value() const {
        return this->toJson();
    }
    PinAddedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["messageId"] = (messageId);
        return _json;
    }
    PinAddedEvent& fromJson(const Json::Value& _json) {
        Json::Value _json;
        userId = _json["userId"].as<std::string>();
        messageId = _json["messageId"].as<std::string>();
        return *this;
    }
};

}

#endif
