#include <traQ/models/ThumbnailType.h>
#include "../Helper.h"

namespace traQApi {

ThumbnailType::ThumbnailType() { value = Value::Unknown; };
ThumbnailType::operator Json::Value() const {
    return this->toJson();
}
ThumbnailType::ThumbnailType(const Json::Value& __value) {
    this->fromJson(__value);
}
ThumbnailType::ThumbnailType(const Value __value) : value(__value) {}

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
};
