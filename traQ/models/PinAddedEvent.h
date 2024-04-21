#ifndef TRAQ_PinAddedEvent_H
#define TRAQ_PinAddedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ピン追加イベント
struct PinAddedEvent {
    std::string userId;
    std::string messageId;

    PinAddedEvent() = default;
    operator Json::Value() const;
    PinAddedEvent(const Json::Value& __value);

    Json::Value toJson() const;
    PinAddedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PinAddedEvent Json::Value::as<traQApi::PinAddedEvent>() const;

#endif
