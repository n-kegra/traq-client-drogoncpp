#include "PostBotActionJoinRequest.h"

namespace traQ {

Json::Value PostBotActionJoinRequest::toJson() const {
    Json::Value _json;
    _json["channelId"] = (channelId);
    return _json;
}
PostBotActionJoinRequest& PostBotActionJoinRequest::fromJson(const Json::Value& _json) {
    channelId = _json["channelId"].as<std::string>();
    return *this;
}

}
template <> traQ::PostBotActionJoinRequest Json::Value::as<traQ::PostBotActionJoinRequest>() const {
    return traQ::PostBotActionJoinRequest(*this);
}
