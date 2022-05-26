#ifndef _ForcedNotificationChangedEvent_H
#define _ForcedNotificationChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// チャンネル強制通知状態変更イベント
struct ForcedNotificationChangedEvent {
    std::string userId;
    bool force;

    operator Json::Value() const {
        return this->toJson();
    }
    ForcedNotificationChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["force"] = (force);
        return _json;
    }
    ForcedNotificationChangedEvent& fromJson(const Json::Value& _json) {
        Json::Value _json;
        userId = _json["userId"].as<std::string>();
        force = _json["force"].as<bool>();
        return *this;
    }
};

}

#endif
