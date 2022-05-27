#include "OAuth2ResponseType.h"

namespace traQ {

Json::Value OAuth2ResponseType::toJson() const {
    switch(this->value) {
    case Value::ecode:
        return Json::Value("code");
    case Value::etoken:
        return Json::Value("token");
    case Value::enone:
        return Json::Value("none");
    case Value::Unknown:
        return Json::Value(Json::nullValue);
    }
}
OAuth2ResponseType& OAuth2ResponseType::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "code") {
        this->value = Value::ecode;
    } else
    if (s == "token") {
        this->value = Value::etoken;
    } else
    if (s == "none") {
        this->value = Value::enone;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQ::OAuth2ResponseType Json::Value::as<traQ::OAuth2ResponseType>() const {
    return traQ::OAuth2ResponseType(*this);
}
