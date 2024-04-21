#include <traQ/models/Message.h>

namespace traQApi {

Message::operator Json::Value() const {
    return this->toJson();
}
Message::Message(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value Message::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["userId"] = (userId);
    _json["channelId"] = (channelId);
    _json["content"] = (content);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    _json["pinned"] = (pinned);
    _json["stamps"] = __Helper::toJson(stamps);
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
template <> traQApi::Message Json::Value::as<traQApi::Message>() const {
    return traQApi::Message(*this);
};
