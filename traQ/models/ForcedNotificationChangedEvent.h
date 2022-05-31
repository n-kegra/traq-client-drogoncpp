#ifndef TRAQ_ForcedNotificationChangedEvent_H
#define TRAQ_ForcedNotificationChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["force"] = (force);
        return _json;
    }
    ForcedNotificationChangedEvent& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        force = _json["force"].as<bool>();
        return *this;
    }
};

}
template <> inline traQApi::ForcedNotificationChangedEvent Json::Value::as<traQApi::ForcedNotificationChangedEvent>() const {
    return traQApi::ForcedNotificationChangedEvent(*this);
};

#endif
