#ifndef _PinAddedEvent_H
#define _PinAddedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// ピン追加イベント
struct PinAddedEvent {
    std::string userId;
    std::string messageId;

    PinAddedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PinAddedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PinAddedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PinAddedEvent Json::Value::as<traQAPI::PinAddedEvent>() const;

#endif
