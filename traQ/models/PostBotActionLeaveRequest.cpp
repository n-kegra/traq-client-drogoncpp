#include <traQ/models/PostBotActionLeaveRequest.h>

namespace traQApi {

PostBotActionLeaveRequest::operator Json::Value() const {
    return this->toJson();
}
PostBotActionLeaveRequest::PostBotActionLeaveRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PostBotActionLeaveRequest Json::Value::as<traQApi::PostBotActionLeaveRequest>() const {
    return traQApi::PostBotActionLeaveRequest(*this);
};
