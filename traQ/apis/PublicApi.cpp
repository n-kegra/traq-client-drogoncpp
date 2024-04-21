#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <traQ/Helper.h>
#include "PublicApi.h"

#include <traQ/models/Version.h>


namespace traQApi {

PublicApi::PublicApi(std::string _baseurl_host, std::string _baseurl_path) :
    baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}

PublicApi& PublicApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
PublicApi& PublicApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
PublicApi& PublicApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


drogon::HttpResponsePtr
PublicApi::getPublicUserIcon(
    const std::string& _username
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/public/icon/{username}";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_username);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "username", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "username" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        return response;
    } else {
        throw std::runtime_error("error");
    }
}


Version
PublicApi::getServerVersion(
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/version";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return Version(*response_json);
    } else {
        throw std::runtime_error("error");
    }
}


}
