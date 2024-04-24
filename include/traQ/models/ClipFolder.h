#ifndef TRAQ_ClipFolder_H
#define TRAQ_ClipFolder_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// クリップフォルダ情報
struct ClipFolder {
    std::string id;
    std::string name;
    std::string createdAt;
    std::string ownerId;
    std::string description;

    ClipFolder() = default;
    operator Json::Value() const;
    ClipFolder(const Json::Value& __value);

    Json::Value toJson() const;
    ClipFolder& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ClipFolder Json::Value::as<traQApi::ClipFolder>() const;

#endif
