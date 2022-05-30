#include <traQ/models/PostBotActionJoinRequest.h>

namespace traQApi {

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
template <> traQApi::PostBotActionJoinRequest Json::Value::as<traQApi::PostBotActionJoinRequest>() const {
    return traQApi::PostBotActionJoinRequest(*this);
}
