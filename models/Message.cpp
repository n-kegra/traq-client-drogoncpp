#include "Message.h"

namespace traQAPI {

Json::Value Message::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["userId"] = (userId);
    _json["channelId"] = (channelId);
    _json["content"] = (content);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    _json["pinned"] = (pinned);
    _json["stamps"] = Helper::toJson(stamps);
    _json["threadId"] = (threadId);
    return _json;
}
Message& Message::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    userId = _json["userId"].as<std::string>();
    channelId = _json["channelId"].as<std::string>();
    content = _json["content"].as<std::string>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    pinned = _json["pinned"].as<bool>();
    for (auto _it = _json["stamps"].begin(); _it != _json["stamps"].end(); _it++) {
        stamps.emplace_back((*_it));    
    }
    threadId = _json["threadId"].as<std::string>();
    return *this;
}

}
template <> traQAPI::Message Json::Value::as<traQAPI::Message>() const {
    return traQAPI::Message(*this);
}
