#ifndef _WebhookApi_H
#define _WebhookApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Message.h"
#include "../models/PatchWebhookRequest.h"
#include "../models/PostWebhookRequest.h"
#include "../models/Webhook.h"


namespace traQ {

class WebhookApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    WebhookApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    WebhookApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    WebhookApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    WebhookApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // Webhookのアイコンを変更
    auto changeWebhookIcon(
        const std::string& _webhookId, 
        const drogon::UploadFile& _file
    );


    // Webhookを新規作成
    auto createWebhook(
        const std::optional<PostWebhookRequest>& _postWebhookRequest
    );


    // Webhookを削除
    auto deleteWebhook(
        const std::string& _webhookId
    );


    // Webhook情報を変更
    auto editWebhook(
        const std::string& _webhookId, 
        const std::optional<PatchWebhookRequest>& _patchWebhookRequest
    );


    // Webhook情報を取得
    auto getWebhook(
        const std::string& _webhookId
    );


    // Webhookのアイコンを取得
    auto getWebhookIcon(
        const std::string& _webhookId
    );


    // Webhookの投稿メッセージのリストを取得
    auto getWebhookMessages(
        const std::string& _webhookId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );


    // Webhook情報のリストを取得します
    auto getWebhooks(
        const std::optional<bool>& _all
    );


    // Webhookを送信
    auto postWebhook(
        const std::string& _webhookId, 
        const std::optional<std::string>& _xTRAQSignature, 
        const std::optional<std::string>& _xTRAQChannelId, 
        const std::optional<int32_t>& _embed, 
        const std::optional<std::string>& _body
    );


};

}

#endif
