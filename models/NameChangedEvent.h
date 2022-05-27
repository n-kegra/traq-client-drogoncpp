#ifndef _NameChangedEvent_H
#define _NameChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// チャンネル名変更イベント
struct NameChangedEvent {
    std::string userId;
    std::string before;
    std::string after;

    NameChangedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    NameChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    NameChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::NameChangedEvent Json::Value::as<traQAPI::NameChangedEvent>() const;

#endif
