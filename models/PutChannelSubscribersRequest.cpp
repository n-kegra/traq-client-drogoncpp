#include "PutChannelSubscribersRequest.h"

namespace traQ {

Json::Value PutChannelSubscribersRequest::toJson() const {
    Json::Value _json;
    _json["on"] = Helper::toJson(on);
    return _json;
}
PutChannelSubscribersRequest& PutChannelSubscribersRequest::fromJson(const Json::Value& _json) {
    for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
        on.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQ::PutChannelSubscribersRequest Json::Value::as<traQ::PutChannelSubscribersRequest>() const {
    return traQ::PutChannelSubscribersRequest(*this);
}
