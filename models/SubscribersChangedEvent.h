#ifndef _SubscribersChangedEvent_H
#define _SubscribersChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQAPI {

// 購読者変更イベント
struct SubscribersChangedEvent {
    std::string userId;
    std::vector<std::string> on;
    std::vector<std::string> off;

    SubscribersChangedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    SubscribersChangedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    SubscribersChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::SubscribersChangedEvent Json::Value::as<traQAPI::SubscribersChangedEvent>() const;

#endif
