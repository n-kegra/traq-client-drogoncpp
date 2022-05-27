#include "MessageStamp.h"

namespace traQAPI {

Json::Value MessageStamp::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["stampId"] = (stampId);
    _json["count"] = (count);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    return _json;
}
MessageStamp& MessageStamp::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    stampId = _json["stampId"].as<std::string>();
    count = _json["count"].as<int32_t>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    return *this;
}

}
template <> traQAPI::MessageStamp Json::Value::as<traQAPI::MessageStamp>() const {
    return traQAPI::MessageStamp(*this);
}
