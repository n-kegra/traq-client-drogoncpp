#include "OAuth2Scope.h"

namespace traQ {

Json::Value OAuth2Scope::toJson() const {
    switch(this->value) {
    case Value::eread:
        return Json::Value("read");
    case Value::ewrite:
        return Json::Value("write");
    case Value::emanage_bot:
        return Json::Value("manage_bot");
    case Value::Unknown:
        return Json::Value(Json::nullValue);
    }
}
OAuth2Scope& OAuth2Scope::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "read") {
        this->value = Value::eread;
    } else
    if (s == "write") {
        this->value = Value::ewrite;
    } else
    if (s == "manage_bot") {
        this->value = Value::emanage_bot;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQ::OAuth2Scope Json::Value::as<traQ::OAuth2Scope>() const {
    return traQ::OAuth2Scope(*this);
}
