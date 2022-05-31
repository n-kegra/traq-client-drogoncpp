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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eNone:
            return Json::Value("none");
        case Value::eMonitoring:
            return Json::Value("monitoring");
        case Value::eEditing:
            return Json::Value("editing");
        default:
            return Json::Value(Json::nullValue);
        }
    }
    ChannelViewState& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "none") {
            this->value = Value::eNone;
        } else
        if (s == "monitoring") {
            this->value = Value::eMonitoring;
        } else
        if (s == "editing") {
            this->value = Value::eEditing;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> inline traQApi::ChannelViewState Json::Value::as<traQApi::ChannelViewState>() const {
    return traQApi::ChannelViewState(*this);
};

#endif
