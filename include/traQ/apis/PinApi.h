#ifndef TRAQ_PinApi_H
#define TRAQ_PinApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/MessagePin.h>
#include <traQ/models/Pin.h>


namespace traQApi {

class PinApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    PinApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    PinApi& setBearerToken(std::string _token);
    PinApi& setBasicAuth(std::string _username, std::string _password);
    PinApi& setApikey(std::string _apikey);


    // ピン留めする
    MessagePin
    createPin(
        const std::string& _messageId
    );

    // チャンネルピンのリストを取得
    std::vector<Pin>
    getChannelPins(
        const std::string& _channelId
    );

    // ピン留めを取得
    MessagePin
    getPin(
        const std::string& _messageId
    );

    // ピン留めを外す
    void
    removePin(
        const std::string& _messageId
    );

};

}

#endif
