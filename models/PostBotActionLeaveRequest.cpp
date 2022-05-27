#include "PostBotActionLeaveRequest.h"

namespace traQ {

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
template <> traQ::PostBotActionLeaveRequest Json::Value::as<traQ::PostBotActionLeaveRequest>() const {
    return traQ::PostBotActionLeaveRequest(*this);
}
