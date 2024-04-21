#include <traQ/models/ActivityTimelineMessage.h>

namespace traQApi {

ActivityTimelineMessage::operator Json::Value() const {
    return this->toJson();
}
ActivityTimelineMessage::ActivityTimelineMessage(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value ActivityTimelineMessage::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["userId"] = (userId);
    _json["channelId"] = (channelId);
    _json["content"] = (content);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    return _json;
}
ActivityTimelineMessage& ActivityTimelineMessage::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    userId = _json["userId"].as<std::string>();
    channelId = _json["channelId"].as<std::string>();
    content = _json["content"].as<std::string>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    return *this;
}

}
template <> traQApi::ActivityTimelineMessage Json::Value::as<traQApi::ActivityTimelineMessage>() const {
    return traQApi::ActivityTimelineMessage(*this);
};
