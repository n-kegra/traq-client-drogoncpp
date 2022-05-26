#ifndef _StampHistoryEntry_H
#define _StampHistoryEntry_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// スタンプ履歴の1項目
struct StampHistoryEntry {
    drogon::UploadFile stampId;
    std::string datetime;

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
        Json::Value _json;
        stampId = _json["stampId"].as<drogon::UploadFile>();
        datetime = _json["datetime"].as<std::string>();
        return *this;
    }
};

}

#endif
