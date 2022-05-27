#include "PutNotifyCitationRequest.h"

namespace traQAPI {

Json::Value PutNotifyCitationRequest::toJson() const {
    Json::Value _json;
    _json["notifyCitation"] = (notifyCitation);
    return _json;
}
PutNotifyCitationRequest& PutNotifyCitationRequest::fromJson(const Json::Value& _json) {
    notifyCitation = _json["notifyCitation"].as<bool>();
    return *this;
}

}
template <> traQAPI::PutNotifyCitationRequest Json::Value::as<traQAPI::PutNotifyCitationRequest>() const {
    return traQAPI::PutNotifyCitationRequest(*this);
}
