//
//  NetController.cpp
//  MindCard
//
//  Created by Deflinhec on 2016/5/8.
//
//
#include "NetController.h"
#include "Logger.h"

using namespace cocos2d::network;

CNetController::CNetController(){
    InvokeMap.clear();
}

CNetController::~CNetController(){
    InvokeMap.clear();
}

void CNetController::init(){
    
    std::vector<std::string> protocols;
    protocols.push_back(std::string("echo-protocol"));
    m_pkWebsocket = new cocos2d::network::WebSocket();
    m_pkWebsocket->init(*this, "123.194.154.177:8888", &protocols);
    NETWORKLOG("init code:[%d]", m_pkWebsocket->getReadyState());
    
    RegisterEvent();
}

void CNetController::RegisterEvent(){
    
    // 監聽 facebook 網路事件
    sdkbox::PluginFacebook::setListener(this);

}
#pragma mark - facebook 
/****************************
 * Listening facebook event *
 ****************************/
 
void CNetController::onLogin(bool isLogin, const std::string& msg){
    
    if (!isLogin)
        return;
    
    CCLOGINFO("Facebook onLogin with msg[%s]", msg.c_str());
}

void CNetController::onSharedSuccess(const std::string& message){
    
}

void CNetController::onSharedFailed(const std::string& message){
    
}

void CNetController::onSharedCancel(){
    
}

void CNetController::onAPI(const std::string& key, const std::string& jsonData){
    
}

void CNetController::onPermission(bool isLogin, const std::string& msg){
    
}

void CNetController::onFetchFriends(bool ok, const std::string& msg){
    
}

void CNetController::onRequestInvitableFriends( const sdkbox::FBInvitableFriendsInfo& friends ){
    
}

void CNetController::onInviteFriendsWithInviteIdsResult( bool result, const std::string& msg ){
    
}

void CNetController::onInviteFriendsResult( bool result, const std::string& msg ){
    
}

void CNetController::onGetUserInfo( const sdkbox::FBGraphUser& userInfo ){
    
}

#pragma mark - websocket
/*****************************
 * Listening websocket event *
 *****************************/

void CNetController::onOpen(WebSocket* ws){
    
    CCLOGINFO("Websocket [%p]", ws);
    
}

void CNetController::onMessage(WebSocket *ws, const WebSocket::Data &data){
    
    CCLOGINFO("Websocket [%p]", ws);
}

void CNetController::onClose(WebSocket *ws){
    
    CCLOGINFO("Websocket [%p]", ws);
}

void CNetController::onError(WebSocket *ws, const WebSocket::ErrorCode &error){
    
    CCLOGINFO("Websocket [%p]", ws);
}
