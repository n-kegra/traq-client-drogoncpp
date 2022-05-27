#include "ChannelList.h"

namespace traQAPI {

Json::Value ChannelList::toJson() const {
    Json::Value _json;
    _json["public"] = Helper::toJson(public);
    _json["dm"] = Helper::toJson(dm);
    return _json;
}
ChannelList& ChannelList::fromJson(const Json::Value& _json) {
    for (auto _it = _json["public"].begin(); _it != _json["public"].end(); _it++) {
        public.emplace_back((*_it));    
    }
    for (auto _it = _json["dm"].begin(); _it != _json["dm"].end(); _it++) {
        dm.emplace_back((*_it));    
    }
    return *this;
}

}
template <> traQAPI::ChannelList Json::Value::as<traQAPI::ChannelList>() const {
    return traQAPI::ChannelList(*this);
}
