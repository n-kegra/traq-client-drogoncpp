#ifndef TRAQ_ForcedNotificationChangedEvent_H
#define TRAQ_ForcedNotificationChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// チャンネル強制通知状態変更イベント
struct ForcedNotificationChangedEvent {
    std::string userId;
    bool force;

    ForcedNotificationChangedEvent() = default;
    operator Json::Value() const;
    ForcedNotificationChangedEvent(const Json::Value& __value);

    Json::Value toJson() const;
    ForcedNotificationChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ForcedNotificationChangedEvent Json::Value::as<traQApi::ForcedNotificationChangedEvent>() const;

#endif
