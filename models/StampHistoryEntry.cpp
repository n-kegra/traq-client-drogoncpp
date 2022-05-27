#include "StampHistoryEntry.h"

namespace traQ {

Json::Value StampHistoryEntry::toJson() const {
    Json::Value _json;
    _json["stampId"] = (stampId);
    _json["datetime"] = (datetime);
    return _json;
}
StampHistoryEntry& StampHistoryEntry::fromJson(const Json::Value& _json) {
    stampId = _json["stampId"].as<drogon::UploadFile>();
    datetime = _json["datetime"].as<std::string>();
    return *this;
}

}
template <> traQ::StampHistoryEntry Json::Value::as<traQ::StampHistoryEntry>() const {
    return traQ::StampHistoryEntry(*this);
}
