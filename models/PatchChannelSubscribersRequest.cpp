#include "PatchChannelSubscribersRequest.h"

namespace traQAPI {

Json::Value PatchChannelSubscribersRequest::toJson() const {
    Json::Value _json;
    _json["on"] = Helper::toJson(on);
    _json["off"] = Helper::toJson(off);
    return _json;
}
PatchChannelSubscribersRequest& PatchChannelSubscribersRequest::fromJson(const Json::Value& _json) {
    for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
        on.emplace_back((*_it).as<std::string>());    
    }
    for (auto _it = _json["off"].begin(); _it != _json["off"].end(); _it++) {
        off.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQAPI::PatchChannelSubscribersRequest Json::Value::as<traQAPI::PatchChannelSubscribersRequest>() const {
    return traQAPI::PatchChannelSubscribersRequest(*this);
}
