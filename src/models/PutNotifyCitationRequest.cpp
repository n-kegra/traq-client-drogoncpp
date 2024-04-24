#include <traQ/models/PutNotifyCitationRequest.h>
#include "../Helper.h"

namespace traQApi {

PutNotifyCitationRequest::operator Json::Value() const {
    return this->toJson();
}
PutNotifyCitationRequest::PutNotifyCitationRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PutNotifyCitationRequest Json::Value::as<traQApi::PutNotifyCitationRequest>() const {
    return traQApi::PutNotifyCitationRequest(*this);
};
