#include <traQ/models/OAuth2ResponseType.h>

namespace traQApi {

OAuth2ResponseType::OAuth2ResponseType() { value = Value::Unknown; };
OAuth2ResponseType::operator Json::Value() const {
    return this->toJson();
}
OAuth2ResponseType::OAuth2ResponseType(const Json::Value& __value) {
    this->fromJson(__value);
}
OAuth2ResponseType::OAuth2ResponseType(const Value __value) : value(__value) {}

Json::Value OAuth2ResponseType::toJson() const {
    switch(this->value) {
    case Value::eCode:
        return Json::Value("code");
    case Value::eToken:
        return Json::Value("token");
    case Value::eNone:
        return Json::Value("none");
    default:
        return Json::Value(Json::nullValue);
    }
}
OAuth2ResponseType& OAuth2ResponseType::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "code") {
        this->value = Value::eCode;
    } else
    if (s == "token") {
        this->value = Value::eToken;
    } else
    if (s == "none") {
        this->value = Value::eNone;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQApi::OAuth2ResponseType Json::Value::as<traQApi::OAuth2ResponseType>() const {
    return traQApi::OAuth2ResponseType(*this);
};
