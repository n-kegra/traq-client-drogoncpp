#include <traQ/models/ChannelStats.h>

namespace traQApi {

ChannelStats::operator Json::Value() const {
    return this->toJson();
}
ChannelStats::ChannelStats(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value ChannelStats::toJson() const {
    Json::Value _json;
    _json["totalMessageCount"] = (totalMessageCount);
    _json["stamps"] = __Helper::toJson(stamps);
    _json["users"] = __Helper::toJson(users);
    _json["datetime"] = (datetime);
    return _json;
}
ChannelStats& ChannelStats::fromJson(const Json::Value& _json) {
    totalMessageCount = _json["totalMessageCount"].as<int64_t>();
    for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
        stamps.emplace_back((*_it));    
    }
    for (auto _it = _json["users"].begin(); _it != _json["users"].end(); _it++) {
        users.emplace_back((*_it));    
    }
    datetime = _json["datetime"].as<std::string>();
    return *this;
}

}
template <> traQApi::ChannelStats Json::Value::as<traQApi::ChannelStats>() const {
    return traQApi::ChannelStats(*this);
};
