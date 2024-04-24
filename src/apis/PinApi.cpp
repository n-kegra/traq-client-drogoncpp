#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include "../Helper.h"
#include <traQ/apis/PinApi.h>

#include <traQ/models/MessagePin.h>
#include <traQ/models/Pin.h>


namespace traQApi {

PinApi::PinApi(std::string baseurl)
{
    std::smatch m;
    if(!std::regex_match(baseurl, m, std::regex(R"((\w+://[a-zA-Z0-9-\.]+)(.+))"))) {
        throw std::runtime_error("PinApi : invalid baseurl");
    }
    client = drogon::HttpClient::newHttpClient(m[1].str());
    baseurl_path = m[2].str();
}

PinApi& PinApi::setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
PinApi& PinApi::setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
PinApi& PinApi::setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


MessagePin
PinApi::createPin(
    const std::string& _messageId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Post);

    std::string endpoint_path = "/messages/{messageId}/pin";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_messageId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "messageId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return MessagePin(*response_json);
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


std::vector<Pin>
PinApi::getChannelPins(
    const std::string& _channelId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/channels/{channelId}/pins";
    
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

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        std::vector<Pin> tmp;
        for (const auto& item : *response_json) {
            tmp.emplace_back(item.as<Pin>());    
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


MessagePin
PinApi::getPin(
    const std::string& _messageId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/messages/{messageId}/pin";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_messageId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "messageId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

    if (result == drogon::ReqResult::Ok && response &&
        200 <= response->getStatusCode() && response->getStatusCode() < 300) {
        auto response_json = response->getJsonObject();
        return MessagePin(*response_json);
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


void
PinApi::removePin(
    const std::string& _messageId
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Delete);

    std::string endpoint_path = "/messages/{messageId}/pin";
    
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_messageId);
        constexpr auto style = __Helper::SerializeStyle::simple;
        auto serialized = __Helper::serialize(style, "messageId", jsonobj);
        endpoint_path = std::regex_replace(endpoint_path, std::regex("\\{" "messageId" "\\}"), serialized);
    }
    
    req->setPath(baseurl_path + endpoint_path);

    auto [result, response] = this->client->sendRequest(req);

}


}
