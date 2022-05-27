#include "OAuth2Prompt.h"

namespace traQ {

Json::Value OAuth2Prompt::toJson() const {
    switch(this->value) {
    case Value::enone:
        return Json::Value("none");
    case Value::Unknown:
        return Json::Value(Json::nullValue);
    }
}
OAuth2Prompt& OAuth2Prompt::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "none") {
        this->value = Value::enone;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQ::OAuth2Prompt Json::Value::as<traQ::OAuth2Prompt>() const {
    return traQ::OAuth2Prompt(*this);
}
