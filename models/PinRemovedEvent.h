#ifndef _PinRemovedEvent_H
#define _PinRemovedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ピン削除イベント
struct PinRemovedEvent {
    std::string userId;
    std::string messageId;

    operator Json::Value() const {
        return this->toJson();
    }
    PinRemovedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["messageId"] = (messageId);
        return _json;
    }
    PinRemovedEvent& fromJson(const Json::Value& _json) {
        Json::Value _json;
        userId = _json["userId"].as<std::string>();
        messageId = _json["messageId"].as<std::string>();
        return *this;
    }
};

}

#endif
