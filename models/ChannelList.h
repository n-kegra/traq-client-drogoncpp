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

    ChannelList() = default;
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
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            public.emplace_back((*_it));    
        }
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            dm.emplace_back((*_it));    
        }
        return *this;
    }
};

}
template <> traQ::ChannelList Json::Value::as<traQ::ChannelList>() const { return traQ::ChannelList(*this); }

#endif
