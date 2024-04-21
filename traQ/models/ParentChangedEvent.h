#ifndef TRAQ_ParentChangedEvent_H
#define TRAQ_ParentChangedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// 親チャンネル変更イベント
struct ParentChangedEvent {
    std::string userId;
    std::string before;
    std::string after;

    ParentChangedEvent() = default;
    operator Json::Value() const;
    ParentChangedEvent(const Json::Value& __value);

    Json::Value toJson() const;
    ParentChangedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ParentChangedEvent Json::Value::as<traQApi::ParentChangedEvent>() const;

#endif
