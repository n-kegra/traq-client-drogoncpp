#include "PostBotActionLeaveRequest.h"

namespace traQAPI {

Json::Value PostBotActionLeaveRequest::toJson() const {
    Json::Value _json;
    _json["channelId"] = (channelId);
    return _json;
}
PostBotActionLeaveRequest& PostBotActionLeaveRequest::fromJson(const Json::Value& _json) {
    channelId = _json["channelId"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostBotActionLeaveRequest Json::Value::as<traQAPI::PostBotActionLeaveRequest>() const {
    return traQAPI::PostBotActionLeaveRequest(*this);
}
