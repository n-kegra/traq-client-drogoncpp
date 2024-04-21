#include <traQ/models/ChannelViewer.h>

namespace traQApi {

ChannelViewer::operator Json::Value() const {
    return this->toJson();
}
ChannelViewer::ChannelViewer(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value ChannelViewer::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["state"] = (state);
    _json["updatedAt"] = (updatedAt);
    return _json;
}
ChannelViewer& ChannelViewer::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    state = _json["state"].as<ChannelViewState>();
    updatedAt = _json["updatedAt"].as<std::string>();
    return *this;
}

}
template <> traQApi::ChannelViewer Json::Value::as<traQApi::ChannelViewer>() const {
    return traQApi::ChannelViewer(*this);
};
