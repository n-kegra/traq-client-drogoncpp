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

    Json::Value toJson() const {
        Json::Value _json;
        _json["public"] = __Helper::toJson(Public);
        _json["dm"] = __Helper::toJson(dm);
        return _json;
    }
    ChannelList& fromJson(const Json::Value& _json) {
        for (auto _it = _json["public"].begin(); _it != _json["public"].end(); _it++) {
            Public.emplace_back((*_it));    
        }
        for (auto _it = _json["dm"].begin(); _it != _json["dm"].end(); _it++) {
            dm.emplace_back((*_it));    
        }
        return *this;
    }
};

}
template <> inline traQApi::ChannelList Json::Value::as<traQApi::ChannelList>() const {
    return traQApi::ChannelList(*this);
};

#endif
