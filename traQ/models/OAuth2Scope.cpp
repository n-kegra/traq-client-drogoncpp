#include <traQ/models/OAuth2Scope.h>

namespace traQApi {

OAuth2Scope::OAuth2Scope() { value = Value::Unknown; };
OAuth2Scope::operator Json::Value() const {
    return this->toJson();
}
OAuth2Scope::OAuth2Scope(const Json::Value& __value) {
    this->fromJson(__value);
}
OAuth2Scope::OAuth2Scope(const Value __value) : value(__value) {}

Json::Value OAuth2Scope::toJson() const {
    switch(this->value) {
    case Value::eRead:
        return Json::Value("read");
    case Value::eWrite:
        return Json::Value("write");
    case Value::eManage_bot:
        return Json::Value("manage_bot");
    default:
        return Json::Value(Json::nullValue);
    }
}
OAuth2Scope& OAuth2Scope::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "read") {
        this->value = Value::eRead;
    } else
    if (s == "write") {
        this->value = Value::eWrite;
    } else
    if (s == "manage_bot") {
        this->value = Value::eManage_bot;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQApi::OAuth2Scope Json::Value::as<traQApi::OAuth2Scope>() const {
    return traQApi::OAuth2Scope(*this);
};
