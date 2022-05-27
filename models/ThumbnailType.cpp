#include "ThumbnailType.h"

namespace traQ {

Json::Value ThumbnailType::toJson() const {
    switch(this->value) {
    case Value::eimage:
        return Json::Value("image");
    case Value::ewaveform:
        return Json::Value("waveform");
    case Value::Unknown:
        return Json::Value(Json::nullValue);
    }
}
ThumbnailType& ThumbnailType::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "image") {
        this->value = Value::eimage;
    } else
    if (s == "waveform") {
        this->value = Value::ewaveform;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQ::ThumbnailType Json::Value::as<traQ::ThumbnailType>() const {
    return traQ::ThumbnailType(*this);
}
