#ifndef _Ogp_H
#define _Ogp_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OgpMedia.h"
#include <vector>

namespace traQ {

// OGPの情報
struct Ogp {
    std::string type;
    std::string title;
    std::string url;
    std::vector<OgpMedia> images;
    std::string description;
    std::vector<OgpMedia> videos;

    operator Json::Value() const {
        return this->toJson();
    }
    Ogp(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["type"] = (type);
        _json["title"] = (title);
        _json["url"] = (url);
        _json["images"] = Helper::toJson(images);
        _json["description"] = (description);
        _json["videos"] = Helper::toJson(videos);
        return _json;
    }
    Ogp& fromJson(const Json::Value& _json) {
        Json::Value _json;
        type = _json["type"].as<std::string>();
        title = _json["title"].as<std::string>();
        url = _json["url"].as<std::string>();
        images = _json["images"].as<std::vector<OgpMedia>>();
        description = _json["description"].as<std::string>();
        videos = _json["videos"].as<std::vector<OgpMedia>>();
        return *this;
    }
};

}

#endif
