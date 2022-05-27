#ifndef _ChannelViewState_H
#define _ChannelViewState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// 閲覧状態
struct ChannelViewState {
    enum class Value {
        enone,
        emonitoring,
        eediting,
        Unknown,
    } value;
    ChannelViewState() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelViewState(const Json::Value& __value) {
        this->fromJson(__value);
    }
    ChannelViewState(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    ChannelViewState& fromJson(const Json::Value& _json);
};

}
template <> traQ::ChannelViewState Json::Value::as<traQ::ChannelViewState>() const;

#endif
