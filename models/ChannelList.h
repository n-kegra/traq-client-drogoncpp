#ifndef _ChannelList_H
#define _ChannelList_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Channel.h"
#include "../models/DMChannel.h"
#include <vector>

namespace traQ {

// GET /channelsレスポンス
struct ChannelList {
    std::vector<Channel> public;
    std::vector<DMChannel> dm;

    operator Json::Value() const {
        return this->toJson();
    }
    ChannelList(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["public"] = Helper::toJson(public);
        _json["dm"] = Helper::toJson(dm);
        return _json;
    }
    ChannelList& fromJson(const Json::Value& _json) {
        Json::Value _json;
        public = _json["public"].as<std::vector<Channel>>();
        dm = _json["dm"].as<std::vector<DMChannel>>();
        return *this;
    }
};

}

#endif
