#ifndef _PinApi_H
#define _PinApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/MessagePin.h"
#include "../models/Pin.h"


namespace traQ {

class PinApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    PinApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    PinApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    PinApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    PinApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // ピン留めする
    auto createPin(
        const std::string& _messageId
    );


    // チャンネルピンのリストを取得
    auto getChannelPins(
        const std::string& _channelId
    );


    // ピン留めを取得
    auto getPin(
        const std::string& _messageId
    );


    // ピン留めを外す
    auto removePin(
        const std::string& _messageId
    );


};

}

#endif
