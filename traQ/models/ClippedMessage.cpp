#include <traQ/models/ClippedMessage.h>

namespace traQApi {

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
}
