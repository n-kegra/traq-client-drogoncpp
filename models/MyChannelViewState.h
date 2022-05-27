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

    MyChannelViewState() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    MyChannelViewState(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    MyChannelViewState& fromJson(const Json::Value& _json);
};

}
template <> traQ::MyChannelViewState Json::Value::as<traQ::MyChannelViewState>() const;

#endif
