#include "MessageSearchResult.h"

namespace traQAPI {

Json::Value MessageSearchResult::toJson() const {
    Json::Value _json;
    _json["totalHits"] = (totalHits);
    _json["hits"] = Helper::toJson(hits);
    return _json;
}
MessageSearchResult& MessageSearchResult::fromJson(const Json::Value& _json) {
    totalHits = _json["totalHits"].as<int64_t>();
    for (auto _it = _json["hits"].begin(); _it != _json["hits"].end(); _it++) {
        hits.emplace_back((*_it));    
    }
    return *this;
}

}
template <> traQAPI::MessageSearchResult Json::Value::as<traQAPI::MessageSearchResult>() const {
    return traQAPI::MessageSearchResult(*this);
}
