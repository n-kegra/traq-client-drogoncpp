#ifndef _VisibilityChangedEvent_H
#define _VisibilityChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// チャンネル可視状態変更イベント
struct VisibilityChangedEvent {
    std::string userId;
    bool visibility;

    VisibilityChangedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    VisibilityChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    VisibilityChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::VisibilityChangedEvent Json::Value::as<traQAPI::VisibilityChangedEvent>() const;

#endif
