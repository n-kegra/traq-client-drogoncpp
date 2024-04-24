#include <traQ/models/SubscribersChangedEvent.h>
#include "../Helper.h"

namespace traQApi {

SubscribersChangedEvent::operator Json::Value() const {
    return this->toJson();
}
SubscribersChangedEvent::SubscribersChangedEvent(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value SubscribersChangedEvent::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["on"] = __Helper::toJson(on);
    _json["off"] = __Helper::toJson(off);
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
template <> traQApi::SubscribersChangedEvent Json::Value::as<traQApi::SubscribersChangedEvent>() const {
    return traQApi::SubscribersChangedEvent(*this);
};
