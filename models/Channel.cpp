#include "Channel.h"

namespace traQAPI {

Json::Value Channel::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["parentId"] = (parentId);
    _json["archived"] = (archived);
    _json["force"] = (force);
    _json["topic"] = (topic);
    _json["name"] = (name);
    _json["children"] = Helper::toJson(children);
    return _json;
}
Channel& Channel::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    parentId = _json["parentId"].as<std::string>();
    archived = _json["archived"].as<bool>();
    force = _json["force"].as<bool>();
    topic = _json["topic"].as<std::string>();
    name = _json["name"].as<std::string>();
    for (auto _it = _json["children"].begin(); _it != _json["children"].end(); _it++) {
        children.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQAPI::Channel Json::Value::as<traQAPI::Channel>() const {
    return traQAPI::Channel(*this);
}
