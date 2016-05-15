//
//  SocketMgr.h
//  build
//
//  Created by Deflinhec on 2016/4/17.
//
//

#ifndef SocketMgr_h
#define SocketMgr_h

#include "network/WebSocket.h"
#include "protocols.h"

using namespace cocos2d::network;
using namespace cocos2d;

class CSocketMgr : public WebSocket::Delegate{
    static CSocketMgr* m_Instance;
public:
    static void Initialize();
    static CSocketMgr GetInstance();
    CSocketMgr();
    ~CSocketMgr();
    
    virtual void onOpen(WebSocket* ws);
    virtual void onMessage(WebSocket* ws, const WebSocket::Data& data);
    virtual void onClose(WebSocket* ws);
    virtual void onError(WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);
    

    void send(CCommand::RoomOperate _type, int roomid = 0);
    void send(CCommand::Connection _type);
    
    void recv(CEvent::Connection _type, const char* bData = 0);
    void recv(CEvent::RoomOperate _type, std::vector<int>& users, int roomid = 0);
private:
    bool isConnected();
    WebSocket* m_websocket;
};

#endif /* SocketMgr_h */
