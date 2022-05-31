#include <traQ/models/ThumbnailType.h>

namespace traQApi {

Json::Value ThumbnailType::toJson() const {
    switch(this->value) {
    case Value::eImage:
        return Json::Value("image");
    case Value::eWaveform:
        return Json::Value("waveform");
    default:
        return Json::Value(Json::nullValue);
    }
}
ThumbnailType& ThumbnailType::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "image") {
        this->value = Value::eImage;
    } else
    if (s == "waveform") {
        this->value = Value::eWaveform;
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
