#include "SubscribersChangedEvent.h"

namespace traQAPI {

Json::Value SubscribersChangedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["on"] = Helper::toJson(on);
    _json["off"] = Helper::toJson(off);
    return _json;
}
SubscribersChangedEvent& SubscribersChangedEvent::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
        on.emplace_back((*_it).as<std::string>());    
    }
    for (auto _it = _json["off"].begin(); _it != _json["off"].end(); _it++) {
        off.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQAPI::SubscribersChangedEvent Json::Value::as<traQAPI::SubscribersChangedEvent>() const {
    return traQAPI::SubscribersChangedEvent(*this);
}
