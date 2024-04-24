#ifndef TRAQ_ChildCreatedEvent_H
#define TRAQ_ChildCreatedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// 子チャンネル作成イベント
struct ChildCreatedEvent {
    std::string userId;
    std::string channelId;

    ChildCreatedEvent() = default;
    operator Json::Value() const;
    ChildCreatedEvent(const Json::Value& __value);

    Json::Value toJson() const;
    ChildCreatedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChildCreatedEvent Json::Value::as<traQApi::ChildCreatedEvent>() const;

#endif
