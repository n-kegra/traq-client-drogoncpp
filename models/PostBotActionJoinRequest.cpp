#include "PostBotActionJoinRequest.h"

namespace traQAPI {

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
template <> traQAPI::PostBotActionJoinRequest Json::Value::as<traQAPI::PostBotActionJoinRequest>() const {
    return traQAPI::PostBotActionJoinRequest(*this);
}
