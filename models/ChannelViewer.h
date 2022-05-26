#ifndef _ChannelViewer_H
#define _ChannelViewer_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChannelViewState.h"

namespace traQ {

// チャンネル閲覧者情報
struct ChannelViewer {
    std::string userId;
    ChannelViewState state;
    std::string updatedAt;

    operator Json::Value() const {
        return this->toJson();
    }
    ChannelViewer(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["state"] = (state);
        _json["updatedAt"] = (updatedAt);
        return _json;
    }
    ChannelViewer& fromJson(const Json::Value& _json) {
        Json::Value _json;
        userId = _json["userId"].as<std::string>();
        state = _json["state"].as<ChannelViewState>();
        updatedAt = _json["updatedAt"].as<std::string>();
        return *this;
    }
};

}

#endif
