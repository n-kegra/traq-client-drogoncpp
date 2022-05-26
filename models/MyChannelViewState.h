#ifndef _MyChannelViewState_H
#define _MyChannelViewState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChannelViewState.h"

namespace traQ {

// 自身のチャンネル閲覧状態
struct MyChannelViewState {
    std::string key;
    std::string channelId;
    ChannelViewState state;

    operator Json::Value() const {
        return this->toJson();
    }
    MyChannelViewState(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["key"] = (key);
        _json["channelId"] = (channelId);
        _json["state"] = (state);
        return _json;
    }
    MyChannelViewState& fromJson(const Json::Value& _json) {
        Json::Value _json;
        key = _json["key"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        state = _json["state"].as<ChannelViewState>();
        return *this;
    }
};

}

#endif
