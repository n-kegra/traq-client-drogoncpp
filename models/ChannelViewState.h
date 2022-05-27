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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::enone:
            return Json::Value("none");
        case Value::emonitoring:
            return Json::Value("monitoring");
        case Value::eediting:
            return Json::Value("editing");
        case Value::Unknown:
            return Json::Value(Json::nullValue);
        }
    }
    ChannelViewState& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "none") {
            this->value = Value::enone;
        } else
        if (s == "monitoring") {
            this->value = Value::emonitoring;
        } else
        if (s == "editing") {
            this->value = Value::eediting;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> traQ::ChannelViewState Json::Value::as<traQ::ChannelViewState>() const { return traQ::ChannelViewState(*this); }

#endif
