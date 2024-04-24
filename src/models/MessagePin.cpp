#include <traQ/models/MessagePin.h>
#include "../Helper.h"

namespace traQApi {

MessagePin::operator Json::Value() const {
    return this->toJson();
}
MessagePin::MessagePin(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value MessagePin::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["pinnedAt"] = (pinnedAt);
    return _json;
}
MessagePin& MessagePin::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    pinnedAt = _json["pinnedAt"].as<std::string>();
    return *this;
}

}
template <> traQApi::MessagePin Json::Value::as<traQApi::MessagePin>() const {
    return traQApi::MessagePin(*this);
};
