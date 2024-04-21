#include <traQ/models/ChannelViewState.h>

namespace traQApi {

ChannelViewState::ChannelViewState() { value = Value::Unknown; };
ChannelViewState::operator Json::Value() const {
    return this->toJson();
}
ChannelViewState::ChannelViewState(const Json::Value& __value) {
    this->fromJson(__value);
}
ChannelViewState::ChannelViewState(const Value __value) : value(__value) {}

Json::Value ChannelViewState::toJson() const {
    switch(this->value) {
    case Value::eNone:
        return Json::Value("none");
    case Value::eMonitoring:
        return Json::Value("monitoring");
    case Value::eEditing:
        return Json::Value("editing");
    default:
        return Json::Value(Json::nullValue);
    }
}
ChannelViewState& ChannelViewState::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "none") {
        this->value = Value::eNone;
    } else
    if (s == "monitoring") {
        this->value = Value::eMonitoring;
    } else
    if (s == "editing") {
        this->value = Value::eEditing;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQApi::ChannelViewState Json::Value::as<traQApi::ChannelViewState>() const {
    return traQApi::ChannelViewState(*this);
};
