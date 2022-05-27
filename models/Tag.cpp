#include "Tag.h"

namespace traQAPI {

Json::Value Tag::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["tag"] = (tag);
    _json["users"] = Helper::toJson(users);
    return _json;
}
Tag& Tag::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    tag = _json["tag"].as<std::string>();
    for (auto _it = _json["users"].begin(); _it != _json["users"].end(); _it++) {
        users.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQAPI::Tag Json::Value::as<traQAPI::Tag>() const {
    return traQAPI::Tag(*this);
}
