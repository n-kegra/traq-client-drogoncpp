#include "PostMessageStampRequest.h"

namespace traQAPI {

Json::Value PostMessageStampRequest::toJson() const {
    Json::Value _json;
    _json["count"] = (count);
    return _json;
}
PostMessageStampRequest& PostMessageStampRequest::fromJson(const Json::Value& _json) {
    count = _json["count"].as<int32_t>();
    return *this;
}

}
template <> traQAPI::PostMessageStampRequest Json::Value::as<traQAPI::PostMessageStampRequest>() const {
    return traQAPI::PostMessageStampRequest(*this);
}
