#include "OgpApi.h"

namespace traQ {

auto OgpApi::getOgp(
    const std::string& _url
){
    auto req = drogon::HttpRequest::newHttpRequest();
    req->setMethod(drogon::HttpMethod::Get);

    std::string endpoint_path = "/ogp";
    std::vector<std::string> query_strs;
    if (this->bearer_token.has_value()) {
        req->addHeader("Authorization", "Bearer " + this->bearer_token.value());
    }
    
    {
        Json::Value jsonobj = (_url);
        constexpr auto style = Helper::SerializeStyle::form;
        auto serialized_list = Helper::serialize_explode(style, "url", jsonobj);
        query_strs.assign(serialized_list.begin(), serialized_list.end());
    }
    
    req->setPath(baseurl_path + endpoint_path + Helper::serialize_collect(Helper::SerializeStyle::form, query_strs));

    auto [result, response] = this->client->sendRequest(req);

    auto response_json = response->getJsonObject();
    std::optional<Ogp> response_object;

    if(response_json) {
        response_object.emplace(*response_json);
    }

    return std::forward_as_tuple(result, response, response_object);
}


}
