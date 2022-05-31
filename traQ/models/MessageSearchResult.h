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
    operator Json::Value() const {
        return this->toJson();
    }
    MessageSearchResult(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["totalHits"] = (totalHits);
        _json["hits"] = __Helper::toJson(hits);
        return _json;
    }
    MessageSearchResult& fromJson(const Json::Value& _json) {
        totalHits = _json["totalHits"].as<int64_t>();
        for (auto _it = _json["hits"].begin(); _it != _json["hits"].end(); _it++) {
            hits.emplace_back((*_it));    
        }
        return *this;
    }
};

}
template <> inline traQApi::MessageSearchResult Json::Value::as<traQApi::MessageSearchResult>() const {
    return traQApi::MessageSearchResult(*this);
};

#endif
