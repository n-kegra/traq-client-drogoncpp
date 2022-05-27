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

    ForcedNotificationChangedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ForcedNotificationChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ForcedNotificationChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQ::ForcedNotificationChangedEvent Json::Value::as<traQ::ForcedNotificationChangedEvent>() const;

#endif
