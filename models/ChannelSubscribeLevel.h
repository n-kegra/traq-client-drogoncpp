#ifndef _ChannelSubscribeLevel_H
#define _ChannelSubscribeLevel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// チャンネル購読レベル 0：無し 1：未読管理 2：未読管理+通知
struct ChannelSubscribeLevel {

    operator Json::Value() const {
        return this->toJson();
    }
    ChannelSubscribeLevel(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    ChannelSubscribeLevel& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
