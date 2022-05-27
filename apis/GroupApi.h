#ifndef _GroupApi_H
#define _GroupApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/PatchGroupMemberRequest.h"
#include "../models/PatchUserGroupRequest.h"
#include "../models/PostUserGroupAdminRequest.h"
#include "../models/PostUserGroupRequest.h"
#include "../models/UserGroup.h"
#include "../models/UserGroupMember.h"


namespace traQ {

class GroupApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    GroupApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    GroupApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    GroupApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    GroupApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // グループ管理者を追加
    auto addUserGroupAdmin(
        const std::string& _groupId, 
        const std::optional<PostUserGroupAdminRequest>& _postUserGroupAdminRequest
    );


    // グループメンバーを追加
    auto addUserGroupMember(
        const std::string& _groupId, 
        const std::optional<UserGroupMember>& _userGroupMember
    );


    // ユーザーグループのアイコンを変更
    auto changeUserGroupIcon(
        const std::string& _groupId, 
        const drogon::UploadFile& _file
    );


    // ユーザーグループを作成
    auto createUserGroup(
        const std::optional<PostUserGroupRequest>& _postUserGroupRequest
    );


    // ユーザーグループを削除
    auto deleteUserGroup(
        const std::string& _groupId
    );


    // ユーザーグループを編集
    auto editUserGroup(
        const std::string& _groupId, 
        const std::optional<PatchUserGroupRequest>& _patchUserGroupRequest
    );


    // グループメンバーを編集
    auto editUserGroupMember(
        const std::string& _groupId, 
        const std::string& _userId, 
        const std::optional<PatchGroupMemberRequest>& _patchGroupMemberRequest
    );


    // ユーザーグループを取得
    auto getUserGroup(
        const std::string& _groupId
    );


    // グループ管理者を取得
    auto getUserGroupAdmins(
        const std::string& _groupId
    );


    // グループメンバーを取得
    auto getUserGroupMembers(
        const std::string& _groupId
    );


    // ユーザーグループのリストを取得
    auto getUserGroups(
    );


    // グループ管理者を削除
    auto removeUserGroupAdmin(
        const std::string& _groupId, 
        const std::string& _userId
    );


    // グループメンバーを削除
    auto removeUserGroupMember(
        const std::string& _groupId, 
        const std::string& _userId
    );


};

}

#endif
