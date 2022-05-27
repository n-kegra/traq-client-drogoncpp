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

    Json::Value toJson() const;
    ChannelList& fromJson(const Json::Value& _json);
};

}
template <> traQ::ChannelList Json::Value::as<traQ::ChannelList>() const;

#endif
