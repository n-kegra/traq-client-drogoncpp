#ifndef _SubscribersChangedEvent_H
#define _SubscribersChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

// 購読者変更イベント
struct SubscribersChangedEvent {
    std::string userId;
    std::vector<std::string> on;
    std::vector<std::string> off;

    operator Json::Value() const {
        return this->toJson();
    }
    SubscribersChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["on"] = Helper::toJson(on);
        _json["off"] = Helper::toJson(off);
        return _json;
    }
    SubscribersChangedEvent& fromJson(const Json::Value& _json) {
        Json::Value _json;
        userId = _json["userId"].as<std::string>();
        on = _json["on"].as<std::vector<std::string>>();
        off = _json["off"].as<std::vector<std::string>>();
        return *this;
    }
};

}

#endif