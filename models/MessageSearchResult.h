#ifndef _MessageSearchResult_H
#define _MessageSearchResult_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Message.h"
#include <vector>

namespace traQ {

// メッセージ検索結果
struct MessageSearchResult {
    int64_t totalHits;
    std::vector<Message> hits;

    MessageSearchResult() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    MessageSearchResult(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["totalHits"] = (totalHits);
        _json["hits"] = Helper::toJson(hits);
        return _json;
    }
    MessageSearchResult& fromJson(const Json::Value& _json) {
        totalHits = _json["totalHits"].as<int64_t>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            hits.emplace_back((*_it));    
        }
        return *this;
    }
};

}
template <> traQ::MessageSearchResult Json::Value::as<traQ::MessageSearchResult>() const { return traQ::MessageSearchResult(*this); }

#endif
