#include <traQ/models/OAuth2Prompt.h>
#include "../Helper.h"

namespace traQApi {

OAuth2Prompt::OAuth2Prompt() { value = Value::Unknown; };
OAuth2Prompt::operator Json::Value() const {
    return this->toJson();
}
OAuth2Prompt::OAuth2Prompt(const Json::Value& __value) {
    this->fromJson(__value);
}
OAuth2Prompt::OAuth2Prompt(const Value __value) : value(__value) {}

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
};
