#ifndef TRAQ_SubscribersChangedEvent_H
#define TRAQ_SubscribersChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <vector>

namespace traQApi {

// 購読者変更イベント
struct SubscribersChangedEvent {
    std::string userId;
    std::vector<std::string> on;
    std::vector<std::string> off;

    SubscribersChangedEvent() = default;
    operator Json::Value() const;
    SubscribersChangedEvent(const Json::Value& __value);

    Json::Value toJson() const;
    SubscribersChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::SubscribersChangedEvent Json::Value::as<traQApi::SubscribersChangedEvent>() const;

#endif
