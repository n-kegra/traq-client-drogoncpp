#include <traQ/models/StampHistoryEntry.h>

namespace traQApi {

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
template <> traQApi::StampHistoryEntry Json::Value::as<traQApi::StampHistoryEntry>() const {
    return traQApi::StampHistoryEntry(*this);
}
