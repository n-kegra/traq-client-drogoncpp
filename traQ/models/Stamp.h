#ifndef TRAQ_Stamp_H
#define TRAQ_Stamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// スタンプ情報
struct Stamp {
    std::string id;
    std::string name;
    std::string creatorId;
    std::string createdAt;
    std::string updatedAt;
    std::string fileId;
    bool isUnicode;

    Stamp() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Stamp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    Stamp& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Stamp Json::Value::as<traQApi::Stamp>() const;

#endif
