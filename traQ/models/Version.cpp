#include <traQ/models/Version.h>

namespace traQApi {

Version::operator Json::Value() const {
    return this->toJson();
}
Version::Version(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value Version::toJson() const {
    Json::Value _json;
    _json["revision"] = (revision);
    _json["version"] = (version);
    _json["flags"] = (flags.toJson());
    return _json;
}
Version& Version::fromJson(const Json::Value& _json) {
    revision = _json["revision"].as<std::string>();
    version = _json["version"].as<std::string>();
    flags.fromJson(_json["flags"]);
    return *this;
}

}
template <> traQApi::Version Json::Value::as<traQApi::Version>() const {
    return traQApi::Version(*this);
};
