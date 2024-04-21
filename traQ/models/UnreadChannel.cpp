#include <traQ/models/UnreadChannel.h>

namespace traQApi {

UnreadChannel::operator Json::Value() const {
    return this->toJson();
}
UnreadChannel::UnreadChannel(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value UnreadChannel::toJson() const {
    Json::Value _json;
    _json["channelId"] = (channelId);
    _json["count"] = (count);
    _json["noticeable"] = (noticeable);
    _json["since"] = (since);
    _json["updatedAt"] = (updatedAt);
    _json["oldestMessageId"] = (oldestMessageId);
    return _json;
}
UnreadChannel& UnreadChannel::fromJson(const Json::Value& _json) {
    channelId = _json["channelId"].as<std::string>();
    count = _json["count"].as<int32_t>();
    noticeable = _json["noticeable"].as<bool>();
    since = _json["since"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    oldestMessageId = _json["oldestMessageId"].as<std::string>();
    return *this;
}

}
template <> traQApi::UnreadChannel Json::Value::as<traQApi::UnreadChannel>() const {
    return traQApi::UnreadChannel(*this);
};
