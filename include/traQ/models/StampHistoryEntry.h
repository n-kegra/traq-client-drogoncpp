#ifndef TRAQ_StampHistoryEntry_H
#define TRAQ_StampHistoryEntry_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// スタンプ履歴の1項目
struct StampHistoryEntry {
    std::string stampId;
    std::string datetime;

    StampHistoryEntry() = default;
    operator Json::Value() const;
    StampHistoryEntry(const Json::Value& __value);

    Json::Value toJson() const;
    StampHistoryEntry& fromJson(const Json::Value& _json);
};

}
template <> traQApi::StampHistoryEntry Json::Value::as<traQApi::StampHistoryEntry>() const;

#endif
