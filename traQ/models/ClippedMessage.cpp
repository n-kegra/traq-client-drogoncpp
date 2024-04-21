#include <traQ/models/ClippedMessage.h>

namespace traQApi {

ClippedMessage::operator Json::Value() const {
    return this->toJson();
}
ClippedMessage::ClippedMessage(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value ClippedMessage::toJson() const {
    Json::Value _json;
    _json["message"] = (message.toJson());
    _json["clippedAt"] = (clippedAt);
    return _json;
}
ClippedMessage& ClippedMessage::fromJson(const Json::Value& _json) {
    message.fromJson(_json["message"]);
    clippedAt = _json["clippedAt"].as<std::string>();
    return *this;
}

}
template <> traQApi::ClippedMessage Json::Value::as<traQApi::ClippedMessage>() const {
    return traQApi::ClippedMessage(*this);
};
