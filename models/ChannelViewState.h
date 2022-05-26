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

    operator Json::Value() const {
        return this->toJson();
    }
    ChannelViewState(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    ChannelViewState& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
