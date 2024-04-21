#ifndef TRAQ_WebhookApi_H
#define TRAQ_WebhookApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Message.h>
#include <traQ/models/PatchWebhookRequest.h>
#include <traQ/models/PostWebhookRequest.h>
#include <traQ/models/Webhook.h>


namespace traQApi {

class WebhookApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    WebhookApi(std::string _baseurl_host, std::string _baseurl_path);
    
    WebhookApi& setBearerToken(std::string _token);
    WebhookApi& setBasicAuth(std::string _username, std::string _password);
    WebhookApi& setApikey(std::string _apikey);


    // Webhookのアイコンを変更
    void
    changeWebhookIcon(
        const std::string& _webhookId, 
        const drogon::UploadFile& _file
    );

    // Webhookを新規作成
    Webhook
    createWebhook(
        const std::optional<PostWebhookRequest>& _postWebhookRequest
    );

    // Webhookを削除
    void
    deleteWebhook(
        const std::string& _webhookId
    );

    // Webhook情報を変更
    void
    editWebhook(
        const std::string& _webhookId, 
        const std::optional<PatchWebhookRequest>& _patchWebhookRequest
    );

    // Webhook情報を取得
    Webhook
    getWebhook(
        const std::string& _webhookId
    );

    // Webhookのアイコンを取得
    drogon::HttpResponsePtr
    getWebhookIcon(
        const std::string& _webhookId
    );

    // Webhookの投稿メッセージのリストを取得
    std::vector<Message>
    getWebhookMessages(
        const std::string& _webhookId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );

    // Webhook情報のリストを取得します
    std::vector<Webhook>
    getWebhooks(
        const std::optional<bool>& _all
    );

    // Webhookを送信
    void
    postWebhook(
        const std::string& _webhookId, 
        const std::optional<std::string>& _xTRAQSignature, 
        const std::optional<std::string>& _xTRAQChannelId, 
        const std::optional<int32_t>& _embed, 
        const std::optional<std::string>& _body
    );

};

}

#endif
