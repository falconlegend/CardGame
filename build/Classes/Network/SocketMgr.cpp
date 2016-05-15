//
//  SocketMgr.cpp
//  build
//
//  Created by Deflinhec on 2016/4/17.
//
//

#include "SocketMgr.h"
#include "Logger.h"
#include "cJSON.h"
#include <stdio.h>

#define SocketMgr CSocketMgr::GetInstance()

CSocketMgr* CSocketMgr::m_Instance = 0;

void CSocketMgr::Initialize(){
    if (m_Instance)
        return;
    m_Instance = new CSocketMgr();
}

CSocketMgr::CSocketMgr(){
    std::vector<std::string> protocols;
    protocols.push_back(std::string("echo-protocol"));
    m_websocket = new network::WebSocket();
    m_websocket->init(*this, "123.194.154.177:8888", &protocols);
    NETWORKLOG("init code:[%d]", m_websocket->getReadyState());
}

CSocketMgr::~CSocketMgr(){
    delete m_websocket;
}

void CSocketMgr::onOpen(cocos2d::network::WebSocket *ws) {
    m_websocket = ws;
    NETWORKLOG("Open code:[%d]", ws->getReadyState());
}

void CSocketMgr::onMessage(cocos2d::network::WebSocket *ws, const WebSocket::Data &data){
    if (!data.isBinary)
        return;
    m_websocket = ws;
    NETWORKLOG("Recieve byte:[%s], len [%d]", data.bytes, data.len);
}

void CSocketMgr::onClose(cocos2d::network::WebSocket *ws){
    NETWORKLOG("Close code:[%d]", ws->getReadyState());
}

void CSocketMgr::onError(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::ErrorCode &error){
    NETWORKLOG("Error code:[%d]", error);
}

void CSocketMgr::send(CCommand::Connection _type){
    if (!isConnected())
        return;
    
    cJSON jsonObj;
    cJSON_AddNumberToObject(&jsonObj, "SESSION", (short)_type);
    m_websocket->send(std::string(cJSON_Print(&jsonObj)));
}

void CSocketMgr::send(CCommand::RoomOperate _type, int roomid){
    if (!isConnected())
        return;
    
    cJSON jsonObj;
    cJSON_AddTrueToObject(&jsonObj, "ESTABLISHED");
    m_websocket->send(std::string(cJSON_Print(&jsonObj)));
}

bool CSocketMgr::isConnected(){
    if (!m_websocket)
        return false;
    if (m_websocket->getReadyState() != WebSocket::State::OPEN)
        return false;
    return true;
}