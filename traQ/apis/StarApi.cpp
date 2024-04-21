#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <traQ/Helper.h>
#include "StarApi.h"

#include <traQ/models/PostStarRequest.h>


namespace traQApi {

StarApi::StarApi(std::string baseurl)
{
    std::smatch m;
    std::regex_match(baseurl, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"));
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

StarApi& StarApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
StarApi& StarApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
StarApi& StarApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


void
StarApi::addMyStar(
    const std::optional<PostStarRequest>& _postStarRequest
){
    Json::Value json;
    if(_postStarRequest.has_value()) {
        json = (_postStarRequest.value());
    }
    auto req = drogon::HttpRequest::newHttpJsonRequest(json);
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/users/me/stars";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


std::vector<std::string>
StarApi::getMyStars(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/users/me/stars";
    
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
        throw std::runtime_error("error");
    }
}


void
StarApi::removeMyStar(
    const std::string& _channelId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/users/me/stars/{channelId}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_channelId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "channelId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "channelId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


}
