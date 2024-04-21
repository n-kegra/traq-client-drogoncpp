#ifndef TRAQ_GroupApi_H
#define TRAQ_GroupApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/PatchGroupMemberRequest.h>
#include <traQ/models/PatchUserGroupRequest.h>
#include <traQ/models/PostUserGroupAdminRequest.h>
#include <traQ/models/PostUserGroupRequest.h>
#include <traQ/models/UserGroup.h>
#include <traQ/models/UserGroupMember.h>


namespace traQApi {

class GroupApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    GroupApi(std::string _baseurl_host, std::string _baseurl_path);
    
    GroupApi& setBearerToken(std::string _token);
    GroupApi& setBasicAuth(std::string _username, std::string _password);
    GroupApi& setApikey(std::string _apikey);


    // グループ管理者を追加
    void
    addUserGroupAdmin(
        const std::string& _groupId, 
        const std::optional<PostUserGroupAdminRequest>& _postUserGroupAdminRequest
    );

    // グループメンバーを追加
    void
    addUserGroupMember(
        const std::string& _groupId, 
        const std::optional<UserGroupMember>& _userGroupMember
    );

    // ユーザーグループのアイコンを変更
    void
    changeUserGroupIcon(
        const std::string& _groupId, 
        const drogon::UploadFile& _file
    );

    // ユーザーグループを作成
    UserGroup
    createUserGroup(
        const std::optional<PostUserGroupRequest>& _postUserGroupRequest
    );

    // ユーザーグループを削除
    void
    deleteUserGroup(
        const std::string& _groupId
    );

    // ユーザーグループを編集
    void
    editUserGroup(
        const std::string& _groupId, 
        const std::optional<PatchUserGroupRequest>& _patchUserGroupRequest
    );

    // グループメンバーを編集
    void
    editUserGroupMember(
        const std::string& _groupId, 
        const std::string& _userId, 
        const std::optional<PatchGroupMemberRequest>& _patchGroupMemberRequest
    );

    // ユーザーグループを取得
    UserGroup
    getUserGroup(
        const std::string& _groupId
    );

    // グループ管理者を取得
    std::vector<std::string>
    getUserGroupAdmins(
        const std::string& _groupId
    );

    // グループメンバーを取得
    std::vector<UserGroupMember>
    getUserGroupMembers(
        const std::string& _groupId
    );

    // ユーザーグループのリストを取得
    std::vector<UserGroup>
    getUserGroups(
    );

    // グループ管理者を削除
    void
    removeUserGroupAdmin(
        const std::string& _groupId, 
        const std::string& _userId
    );

    // グループメンバーを削除
    void
    removeUserGroupMember(
        const std::string& _groupId, 
        const std::string& _userId
    );

};

}

#endif
