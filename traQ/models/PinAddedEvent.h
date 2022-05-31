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
    operator Json::Value() const {
        return this->toJson();
    }
    PinAddedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["messageId"] = (messageId);
        return _json;
    }
    PinAddedEvent& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        messageId = _json["messageId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PinAddedEvent Json::Value::as<traQApi::PinAddedEvent>() const {
    return traQApi::PinAddedEvent(*this);
};

#endif
