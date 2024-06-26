#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include "../Helper.h"
#include <traQ/apis/ActivityApi.h>

#include <traQ/models/ActivityTimelineMessage.h>


namespace traQApi {

ActivityApi::ActivityApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, m, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("ActivityApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

ActivityApi& ActivityApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
ActivityApi& ActivityApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
ActivityApi& ActivityApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


std::vector<ActivityTimelineMessage>
ActivityApi::getActivityTimeline(
    const std::optional<int32_t>& _limit, 
    const std::optional<bool>& _all, 
    const std::optional<bool>& _perChannel
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/activity/timeline";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    if(_limit.has_value()) {
        Json::Value jsonobj = (_limit.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "limit", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_all.has_value()) {
        Json::Value jsonobj = (_all.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "all", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    if(_perChannel.has_value()) {
        Json::Value jsonobj = (_perChannel.value());
        constexpr auto style = __Helper::SerializeStyle::form;
        auto serialized_list = __Helper::serialize_explode(style, "perChannel", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + __Helper::serialize_collect(__Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<ActivityTimelineMessage> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<ActivityTimelineMessage>());    
        }
        return tmp;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


std::vector<std::string>
ActivityApi::getOnlineUsers(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/activity/onlines";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<std::string> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<std::string>());    
        }
        return tmp;
    } else {
        std::ostringstream oss;
        oss << "result:" << result;
        if(!response) {
            oss << ", response invalid";
        } else {
            oss << ", code=" << response->getStatusCode() << ", response=\"" << response->getBody() << "\"";
        }
        oss << std::flush;
        throw std::runtime_error(oss.str());
    }
}


}
