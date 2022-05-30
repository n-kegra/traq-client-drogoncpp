#include <traQ/models/OAuth2ResponseType.h>

namespace traQApi {

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
template <> traQApi::OAuth2ResponseType Json::Value::as<traQApi::OAuth2ResponseType>() const {
    return traQApi::OAuth2ResponseType(*this);
}
