#include <traQ/models/StampHistoryEntry.h>
#include "../Helper.h"

namespace traQApi {

StampHistoryEntry::operator Json::Value() const {
    return this->toJson();
}
StampHistoryEntry::StampHistoryEntry(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value StampHistoryEntry::toJson() const {
    Json::Value _json;
    _json["stampId"] = (stampId);
    _json["datetime"] = (datetime);
    return _json;
}
StampHistoryEntry& StampHistoryEntry::fromJson(const Json::Value& _json) {
    stampId = _json["stampId"].as<std::string>();
    datetime = _json["datetime"].as<std::string>();
    return *this;
}

}
template <> traQApi::StampHistoryEntry Json::Value::as<traQApi::StampHistoryEntry>() const {
    return traQApi::StampHistoryEntry(*this);
};
