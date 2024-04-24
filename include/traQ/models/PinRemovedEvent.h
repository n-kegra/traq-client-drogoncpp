#ifndef TRAQ_PinRemovedEvent_H
#define TRAQ_PinRemovedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// ピン削除イベント
struct PinRemovedEvent {
    std::string userId;
    std::string messageId;

    PinRemovedEvent() = default;
    operator Json::Value() const;
    PinRemovedEvent(const Json::Value& __value);

    Json::Value toJson() const;
    PinRemovedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PinRemovedEvent Json::Value::as<traQApi::PinRemovedEvent>() const;

#endif
