#ifndef _ClipFolder_H
#define _ClipFolder_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// クリップフォルダ情報
struct ClipFolder {
    std::string id;
    std::string name;
    std::string createdAt;
    std::string ownerId;
    std::string description;

    ClipFolder() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ClipFolder(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ClipFolder& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::ClipFolder Json::Value::as<traQAPI::ClipFolder>() const;

#endif
