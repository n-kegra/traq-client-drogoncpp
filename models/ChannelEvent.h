#ifndef _ChannelEvent_H
#define _ChannelEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChannelEventDetail.h"

namespace traQAPI {

// チャンネルイベント
struct ChannelEvent {
    std::string type;
    std::string datetime;
    ChannelEventDetail detail;

    ChannelEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ChannelEvent& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::ChannelEvent Json::Value::as<traQAPI::ChannelEvent>() const;

#endif
