#ifndef TRAQ_ChannelViewState_H
#define TRAQ_ChannelViewState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// 閲覧状態
struct ChannelViewState {
    enum class Value {
        eNone,
        eMonitoring,
        eEditing,
        Unknown,
    } value;
    ChannelViewState();
    operator Json::Value() const;
    ChannelViewState(const Json::Value& __value);
    ChannelViewState(const Value __value);

    Json::Value toJson() const;
    ChannelViewState& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelViewState Json::Value::as<traQApi::ChannelViewState>() const;

#endif
