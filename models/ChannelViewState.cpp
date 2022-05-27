#include "ChannelViewState.h"

namespace traQ {

Json::Value ChannelViewState::toJson() const {
    switch(this->value) {
    case Value::enone:
        return Json::Value("none");
    case Value::emonitoring:
        return Json::Value("monitoring");
    case Value::eediting:
        return Json::Value("editing");
    case Value::Unknown:
        return Json::Value(Json::nullValue);
    }
}
ChannelViewState& ChannelViewState::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "none") {
        this->value = Value::enone;
    } else
    if (s == "monitoring") {
        this->value = Value::emonitoring;
    } else
    if (s == "editing") {
        this->value = Value::eediting;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQ::ChannelViewState Json::Value::as<traQ::ChannelViewState>() const {
    return traQ::ChannelViewState(*this);
}