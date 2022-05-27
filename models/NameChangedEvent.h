#ifndef _NameChangedEvent_H
#define _NameChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["before"] = (before);
        _json["after"] = (after);
        return _json;
    }
    NameChangedEvent& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        before = _json["before"].as<std::string>();
        after = _json["after"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::NameChangedEvent Json::Value::as<traQ::NameChangedEvent>() const { return traQ::NameChangedEvent(*this); }

#endif
