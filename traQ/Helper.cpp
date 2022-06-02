#include <traQ/Helper.h>

namespace traQApi {

namespace __Helper {
    std::string serialize(SerializeStyle style, const std::string name, const Json::Value& value) {
        std::string str;
        char delimiter;
        switch (style) {
        case SerializeStyle::spaceDelimited:
            delimiter = ' ';
            break;
        case SerializeStyle::pipeDelimited:
            delimiter = '|';
            break;
        default:
            delimiter = ',';
            break;
        }

        switch(style) {
        case SerializeStyle::form:
        case SerializeStyle::matrix:
            str += name;
            str += "=";
            break;
        default:
            break;
        }

        if(value.isArray()){
            bool first = true;
            for(const auto& item : value) {
                if (first) {
                    first = false;
                } else {
                    str += delimiter;
                }
                str += item.asString();
            }
        } else if(value.isObject()) {
            bool first = true;
            for (auto it = value.begin(); it != value.end(); it++) {
                if(first){
                    first = false;
                } else {
                    str += delimiter;
                }
                str += it.name();
                str += delimiter;
                str += (*it).asString();
            }
        } else {
            str = value.asString();
        }
        return str;
    }
    std::vector<std::string> serialize_explode(SerializeStyle style, const std::string name, const Json::Value& value) {
        std::vector<std::string> strs;

        if(value.isArray()){
            bool first = true;
            for(const auto& item : value) {
                Json::Value tmpvalue;
                tmpvalue.append(item);
                strs.push_back(serialize(style, name, tmpvalue));
            }
        } else if(value.isObject()) {
            for (auto it = value.begin(); it != value.end(); it++) {
                Json::Value tmpvalue;
                tmpvalue[it.name()] = *it;
                strs.push_back(serialize(style, name, tmpvalue));
            }
        } else {
            strs.push_back(value.asString());
        }
        return strs;
    }
    std::string serialize_collect(SerializeStyle style, const std::vector<std::string>& strs) {
        std::string str_collect;
        bool first = true;
        const char* firstPrefix;
        const char* normalPrefix;

        switch (style) {
        case SerializeStyle::simple:
            firstPrefix = "";
            normalPrefix = ",";
            break;
        case SerializeStyle::label:
            firstPrefix = normalPrefix = ".";
            break;
        case SerializeStyle::matrix:
            firstPrefix = normalPrefix = ";";
            break;
        case SerializeStyle::form:
        case SerializeStyle::pipeDelimited:
        case SerializeStyle::spaceDelimited:
            firstPrefix = "?";
            normalPrefix = "&";
            break;
        }

        for(const auto& str : strs) {
            if(first) {
                str_collect += firstPrefix;
                first = false;
            } else {
                str_collect += normalPrefix;
            }
            str_collect += str;
        }

        return str_collect;
    }
};

}
