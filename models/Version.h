#ifndef _Version_H
#define _Version_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/VersionFlags.h"

namespace traQAPI {

// バージョン・サーバーフラグ情報
struct Version {
    std::string revision;
    std::string version;
    VersionFlags flags;

    Version() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Version(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    Version& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::Version Json::Value::as<traQAPI::Version>() const;

#endif
