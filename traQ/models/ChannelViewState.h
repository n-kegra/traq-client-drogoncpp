#ifndef TRAQ_ChannelViewState_H
#define TRAQ_ChannelViewState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// 閲覧状態
struct ChannelViewState {
    enum class Value {
        eNone,
        eMonitoring,
        eEditing,
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
template <> traQApi::ChannelViewState Json::Value::as<traQApi::ChannelViewState>() const;

#endif
