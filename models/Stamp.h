#ifndef _Stamp_H
#define _Stamp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::Stamp Json::Value::as<traQ::Stamp>() const;

#endif
