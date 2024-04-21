#include <traQ/models/GetNotifyCitation.h>

namespace traQApi {

GetNotifyCitation::operator Json::Value() const {
    return this->toJson();
}
GetNotifyCitation::GetNotifyCitation(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value GetNotifyCitation::toJson() const {
    Json::Value _json;
    _json["notifyCitation"] = (notifyCitation);
    return _json;
}
GetNotifyCitation& GetNotifyCitation::fromJson(const Json::Value& _json) {
    notifyCitation = _json["notifyCitation"].as<bool>();
    return *this;
}

}
template <> traQApi::GetNotifyCitation Json::Value::as<traQApi::GetNotifyCitation>() const {
    return traQApi::GetNotifyCitation(*this);
};
