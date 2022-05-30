#include <traQ/models/ChannelList.h>

namespace traQApi {

Json::Value ChannelList::toJson() const {
    Json::Value _json;
    _json["public"] = __Helper::toJson(Public);
    _json["dm"] = __Helper::toJson(dm);
    return _json;
}
ChannelList& ChannelList::fromJson(const Json::Value& _json) {
    for (auto _it = _json["public"].begin(); _it != _json["public"].end(); _it++) {
        Public.emplace_back((*_it));    
    }
    for (auto _it = _json["dm"].begin(); _it != _json["dm"].end(); _it++) {
        dm.emplace_back((*_it));    
    }
    return *this;
}

}
template <> traQApi::ChannelList Json::Value::as<traQApi::ChannelList>() const {
    return traQApi::ChannelList(*this);
}
