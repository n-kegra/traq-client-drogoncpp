#ifndef _ChannelEvent_H
#define _ChannelEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChannelEventDetail.h"

namespace traQ {

// チャンネルイベント
struct ChannelEvent {
    std::string type;
    std::string datetime;
    ChannelEventDetail detail;

    operator Json::Value() const {
        return this->toJson();
    }
    ChannelEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["type"] = (type);
        _json["datetime"] = (datetime);
        _json["detail"] = (detail.toJson());
        return _json;
    }
    ChannelEvent& fromJson(const Json::Value& _json) {
        Json::Value _json;
        type = _json["type"].as<std::string>();
        datetime = _json["datetime"].as<std::string>();
        detail = _json["detail"].as<ChannelEventDetail>();
        return *this;
    }
};

}

#endif
