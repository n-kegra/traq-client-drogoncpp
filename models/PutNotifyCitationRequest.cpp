#include "PutNotifyCitationRequest.h"

namespace traQ {

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
template <> traQ::PutNotifyCitationRequest Json::Value::as<traQ::PutNotifyCitationRequest>() const {
    return traQ::PutNotifyCitationRequest(*this);
}
