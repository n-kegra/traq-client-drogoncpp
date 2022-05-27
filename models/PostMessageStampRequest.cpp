#include "PostMessageStampRequest.h"

namespace traQ {

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
template <> traQ::PostMessageStampRequest Json::Value::as<traQ::PostMessageStampRequest>() const {
    return traQ::PostMessageStampRequest(*this);
}
