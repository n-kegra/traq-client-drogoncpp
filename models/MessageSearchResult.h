#ifndef _MessageSearchResult_H
#define _MessageSearchResult_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Message.h"
#include <vector>

namespace traQAPI {

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

    Json::Value toJson() const;
    MessageSearchResult& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::MessageSearchResult Json::Value::as<traQAPI::MessageSearchResult>() const;

#endif
