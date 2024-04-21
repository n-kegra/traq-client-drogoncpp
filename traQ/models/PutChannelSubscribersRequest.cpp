#include <traQ/models/PutChannelSubscribersRequest.h>

namespace traQApi {

PutChannelSubscribersRequest::operator Json::Value() const {
    return this->toJson();
}
PutChannelSubscribersRequest::PutChannelSubscribersRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PutChannelSubscribersRequest::toJson() const {
    Json::Value _json;
    _json["on"] = __Helper::toJson(on);
    return _json;
}
PutChannelSubscribersRequest& PutChannelSubscribersRequest::fromJson(const Json::Value& _json) {
    for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
        on.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQApi::PutChannelSubscribersRequest Json::Value::as<traQApi::PutChannelSubscribersRequest>() const {
    return traQApi::PutChannelSubscribersRequest(*this);
};
