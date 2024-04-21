#ifndef TRAQ_ChannelEvent_H
#define TRAQ_ChannelEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ChannelEventDetail.h>

namespace traQApi {

// チャンネルイベント
struct ChannelEvent {
    std::string type;
    std::string datetime;
    ChannelEventDetail detail;

    ChannelEvent() = default;
    operator Json::Value() const;
    ChannelEvent(const Json::Value& __value);

    Json::Value toJson() const;
    ChannelEvent& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelEvent Json::Value::as<traQApi::ChannelEvent>() const;

#endif
