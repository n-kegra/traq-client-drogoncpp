#include <traQ/models/ThumbnailType.h>

namespace traQApi {

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
template <> traQApi::ThumbnailType Json::Value::as<traQApi::ThumbnailType>() const {
    return traQApi::ThumbnailType(*this);
}
