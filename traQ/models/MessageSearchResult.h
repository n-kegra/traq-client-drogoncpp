#ifndef TRAQ_MessageSearchResult_H
#define TRAQ_MessageSearchResult_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Message.h>
#include <vector>

namespace traQApi {

// メッセージ検索結果
struct MessageSearchResult {
    int64_t totalHits;
    std::vector<Message> hits;

    MessageSearchResult() = default;
    operator Json::Value() const;
    MessageSearchResult(const Json::Value& __value);

    Json::Value toJson() const;
    MessageSearchResult& fromJson(const Json::Value& _json);
};

}
template <> traQApi::MessageSearchResult Json::Value::as<traQApi::MessageSearchResult>() const;

#endif
