#ifndef TRAQ_ChannelEvent_H
#define TRAQ_ChannelEvent_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ChannelEventDetail.h>

namespace traQApi {

// チャンネルイベント
struct ChannelEvent {
    std::string type;
    std::string datetime;
    ChannelEventDetail detail;

    ChannelEvent() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelEvent(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["type"] = (type);
        _json["datetime"] = (datetime);
        _json["detail"] = (detail.toJson());
        return _json;
    }
    ChannelEvent& fromJson(const Json::Value& _json) {
        type = _json["type"].as<std::string>();
        datetime = _json["datetime"].as<std::string>();
        detail.fromJson(_json["detail"]);
        return *this;
    }
};

}
template <> inline traQApi::ChannelEvent Json::Value::as<traQApi::ChannelEvent>() const {
    return traQApi::ChannelEvent(*this);
};

#endif
