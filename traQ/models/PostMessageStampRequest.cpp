#include <traQ/models/PostMessageStampRequest.h>

namespace traQApi {

PostMessageStampRequest::operator Json::Value() const {
    return this->toJson();
}
PostMessageStampRequest::PostMessageStampRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PostMessageStampRequest Json::Value::as<traQApi::PostMessageStampRequest>() const {
    return traQApi::PostMessageStampRequest(*this);
};
