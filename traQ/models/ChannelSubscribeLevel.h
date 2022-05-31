#ifndef TRAQ_ChannelSubscribeLevel_H
#define TRAQ_ChannelSubscribeLevel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// チャンネル購読レベル 0：無し 1：未読管理 2：未読管理+通知
struct ChannelSubscribeLevel {
    enum class Value {
        e0,
        e1,
        e2,
        Unknown,
    } value;
    ChannelSubscribeLevel() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelSubscribeLevel(const Json::Value& __value) {
        this->fromJson(__value);
    }
    ChannelSubscribeLevel(const Value __value) : value(__value) {}

    Json::Value toJson() const {
        switch(this->value) {
        case Value::e0:
            return Json::Value(0);
        case Value::e1:
            return Json::Value(1);
        case Value::e2:
            return Json::Value(2);
        default:
            return Json::Value(Json::nullValue);
        }
    }
    ChannelSubscribeLevel& fromJson(const Json::Value& _json) {
        auto s = _json.asLargestInt();
        if (s == 0) {
            this->value = Value::e0;
        } else
        if (s == 1) {
            this->value = Value::e1;
        } else
        if (s == 2) {
            this->value = Value::e2;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> inline traQApi::ChannelSubscribeLevel Json::Value::as<traQApi::ChannelSubscribeLevel>() const {
    return traQApi::ChannelSubscribeLevel(*this);
};

#endif
