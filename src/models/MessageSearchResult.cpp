#include <traQ/models/MessageSearchResult.h>
#include "../Helper.h"

namespace traQApi {

MessageSearchResult::operator Json::Value() const {
    return this->toJson();
}
MessageSearchResult::MessageSearchResult(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value MessageSearchResult::toJson() const {
    Json::Value _json;
    _json["totalHits"] = (totalHits);
    _json["hits"] = __Helper::toJson(hits);
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
template <> traQApi::MessageSearchResult Json::Value::as<traQApi::MessageSearchResult>() const {
    return traQApi::MessageSearchResult(*this);
};
