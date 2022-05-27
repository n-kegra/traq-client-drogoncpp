#include "ChannelViewer.h"

namespace traQ {

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
template <> traQ::ChannelViewer Json::Value::as<traQ::ChannelViewer>() const {
    return traQ::ChannelViewer(*this);
}
