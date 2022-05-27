#ifndef _UserTagApi_H
#define _UserTagApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/PatchUserTagRequest.h"
#include "../models/PostUserTagRequest.h"
#include "../models/Tag.h"
#include "../models/UserTag.h"


namespace traQ {

class UserTagApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    UserTagApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    UserTagApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    UserTagApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    UserTagApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // 自分にタグを追加
    auto addMyUserTag(
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    );


    // ユーザーにタグを追加
    auto addUserTag(
        const std::string& _userId, 
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    );


    // 自分のタグを編集
    auto editMyUserTag(
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    );


    // ユーザーのタグを編集
    auto editUserTag(
        const std::string& _userId, 
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    );


    // 自分のタグリストを取得
    auto getMyUserTags(
    );


    // タグ情報を取得
    auto getTag(
        const std::string& _tagId
    );


    // ユーザーのタグリストを取得
    auto getUserTags(
        const std::string& _userId
    );


    // 自分からタグを削除します
    auto removeMyUserTag(
        const std::string& _tagId
    );


    // ユーザーからタグを削除します
    auto removeUserTag(
        const std::string& _userId, 
        const std::string& _tagId
    );


};

}

#endif
