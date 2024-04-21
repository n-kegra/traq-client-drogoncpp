#include <traQ/models/Tag.h>

namespace traQApi {

Tag::operator Json::Value() const {
    return this->toJson();
}
Tag::Tag(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value Tag::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["tag"] = (tag);
    _json["users"] = __Helper::toJson(users);
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
template <> traQApi::Tag Json::Value::as<traQApi::Tag>() const {
    return traQApi::Tag(*this);
};
