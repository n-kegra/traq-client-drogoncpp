#ifndef _StampHistoryEntry_H
#define _StampHistoryEntry_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// スタンプ履歴の1項目
struct StampHistoryEntry {
    drogon::UploadFile stampId;
    std::string datetime;

    StampHistoryEntry() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    StampHistoryEntry(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    StampHistoryEntry& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::StampHistoryEntry Json::Value::as<traQAPI::StampHistoryEntry>() const;

#endif
