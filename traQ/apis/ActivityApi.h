#ifndef TRAQ_ActivityApi_H
#define TRAQ_ActivityApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ActivityTimelineMessage.h>


namespace traQApi {

class ActivityApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    ActivityApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    ActivityApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    ActivityApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    ActivityApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // アクテビティタイムラインを取得
    auto getActivityTimeline(
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

        auto response_json = response->getJsonObject();
        std::optional<std::vector<ActivityTimelineMessage>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<ActivityTimelineMessage> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<ActivityTimelineMessage>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


    // オンラインユーザーリストを取得
    auto getOnlineUsers(
    ){
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setMethod(drogon::HttpMethod::Get);

        std::string endpoint_path = "/activity/onlines";
        
        if (this->bearer_token.has_value()) {
            req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
        }
        
        req->setPath(baseurl_path + endpoint_path);

        auto [result, response] = this->client->sendRequest(req);

        auto response_json = response->getJsonObject();
        std::optional<std::vector<std::string>> response_object;

        if (result == drogon::ReqResult::Ok &&
            200 <= response->getStatusCode() &&
            300 > response->getStatusCode() &&
            response_json) {
            std::vector<std::string> tmp;
            for (const auto& item : *response_json) {
                tmp.emplace_back(item.as<std::string>());    
            }
            response_object.emplace(std::move(tmp));
        }

        return std::forward_as_tuple(result, response, response_object);
    }


};

}

#endif
