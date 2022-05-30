#ifndef TRAQ_MyChannelViewState_H
#define TRAQ_MyChannelViewState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ChannelViewState.h>

namespace traQApi {

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
template <> traQApi::MyChannelViewState Json::Value::as<traQApi::MyChannelViewState>() const;

#endif
