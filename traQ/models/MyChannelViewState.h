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

    Json::Value toJson() const {
        Json::Value _json;
        _json["key"] = (key);
        _json["channelId"] = (channelId);
        _json["state"] = (state);
        return _json;
    }
    MyChannelViewState& fromJson(const Json::Value& _json) {
        key = _json["key"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        state = _json["state"].as<ChannelViewState>();
        return *this;
    }
};

}
template <> inline traQApi::MyChannelViewState Json::Value::as<traQApi::MyChannelViewState>() const {
    return traQApi::MyChannelViewState(*this);
};

#endif
