#ifndef _PinRemovedEvent_H
#define _PinRemovedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// ピン削除イベント
struct PinRemovedEvent {
    std::string userId;
    std::string messageId;

    PinRemovedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PinRemovedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PinRemovedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PinRemovedEvent Json::Value::as<traQAPI::PinRemovedEvent>() const;

#endif
