#ifndef _Version_H
#define _Version_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/VersionFlags.h"

namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["revision"] = (revision);
        _json["version"] = (version);
        _json["flags"] = (flags.toJson());
        return _json;
    }
    Version& fromJson(const Json::Value& _json) {
        revision = _json["revision"].as<std::string>();
        version = _json["version"].as<std::string>();
        flags.fromJson(_json["flags"]);
        return *this;
    }
};

}
template <> traQ::Version Json::Value::as<traQ::Version>() const { return traQ::Version(*this); }

#endif
