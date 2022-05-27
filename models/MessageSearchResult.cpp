#include "MessageSearchResult.h"

namespace traQ {

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
template <> traQ::MessageSearchResult Json::Value::as<traQ::MessageSearchResult>() const {
    return traQ::MessageSearchResult(*this);
}
