#ifndef _ChildCreatedEvent_H
#define _ChildCreatedEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// 子チャンネル作成イベント
struct ChildCreatedEvent {
    std::string userId;
    std::string channelId;

    ChildCreatedEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChildCreatedEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ChildCreatedEvent& fromJson(const Json::Value& _json);
};

}
template <> traQ::ChildCreatedEvent Json::Value::as<traQ::ChildCreatedEvent>() const;

#endif
