#ifndef TRAQ_ChannelList_H
#define TRAQ_ChannelList_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Channel.h>
#include <traQ/models/DMChannel.h>
#include <vector>

namespace traQApi {

// GET /channelsレスポンス
struct ChannelList {
    std::vector<Channel> Public;
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
template <> traQApi::ChannelList Json::Value::as<traQApi::ChannelList>() const;

#endif
