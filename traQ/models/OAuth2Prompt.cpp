#include <traQ/models/OAuth2Prompt.h>

namespace traQApi {

Json::Value OAuth2Prompt::toJson() const {
    switch(this->value) {
    case Value::eNone:
        return Json::Value("none");
    default:
        return Json::Value(Json::nullValue);
    }
}
OAuth2Prompt& OAuth2Prompt::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "none") {
        this->value = Value::eNone;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQApi::OAuth2Prompt Json::Value::as<traQApi::OAuth2Prompt>() const {
    return traQApi::OAuth2Prompt(*this);
}
