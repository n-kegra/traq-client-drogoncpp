#ifndef TRAQ_Version_H
#define TRAQ_Version_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/VersionFlags.h>

namespace traQApi {

// バージョン・サーバーフラグ情報
struct Version {
    std::string revision;
    std::string version;
    VersionFlags flags;

    Version() = default;
    operator Json::Value() const;
    Version(const Json::Value& __value);

    Json::Value toJson() const;
    Version& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Version Json::Value::as<traQApi::Version>() const;

#endif
