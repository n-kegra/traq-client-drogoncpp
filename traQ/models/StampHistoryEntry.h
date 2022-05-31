#ifndef TRAQ_StampHistoryEntry_H
#define TRAQ_StampHistoryEntry_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// スタンプ履歴の1項目
struct StampHistoryEntry {
    std::string stampId;
    std::string datetime;

    StampHistoryEntry() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    StampHistoryEntry(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["stampId"] = (stampId);
        _json["datetime"] = (datetime);
        return _json;
    }
    StampHistoryEntry& fromJson(const Json::Value& _json) {
        stampId = _json["stampId"].as<std::string>();
        datetime = _json["datetime"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::StampHistoryEntry Json::Value::as<traQApi::StampHistoryEntry>() const {
    return traQApi::StampHistoryEntry(*this);
};

#endif
