//
//  NetBridge.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/15.
//
//

#ifndef NetBridge_h
#define NetBridge_h

#include <stdio.h>
#include <cocos2d.h>
#include "network/websocket.h"

class CNetBridge{
public:
    
    
    /**
     * @brief Server notify Model to create main char data, usually in the first begin of the game.
     * @param Websocket::Data
     */
    virtual void CreateMainCharData(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to update main char data
     * @param Websocket::Data
     */
    virtual void UpdateMainCharAttr(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to add Character Data
     * @param Websocket::Data
     */
    virtual void AddCharData(cocos2d::network::WebSocket::Data& _data) = 0;

    /**
     * @brief Server notify Model to add Loby Data
     * @param Websocket::Data
     */
    virtual void AddLobyData(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to add Game Data
     * @param Websocket::Data
     */
    virtual void AddGameData(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to delete a specific Loby Data
     * @param Websocket::Data
     */
    virtual void DelLobyData(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to delete a specific Game Data
     * @param Websocket::Data
     */
    virtual void DelGameData(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to delete a specific Character Data
     * @param Websocket::Data
     */
    virtual void DelCharData(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to update a specific Character attribute
     * @param Websocket::Data
     */
    virtual void UpdateCharAttr(cocos2d::network::WebSocket::Data& _data) = 0;

    /**
     * @brief Server notify Model to update a specific Game attribute
     * @param Websocket::Data
     */
    virtual void UpdateGameAttr(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to update a specific Loby attribute
     * @param Websocket::Data
     */
    virtual void UpdateLobyAttr(cocos2d::network::WebSocket::Data& _data) = 0;
    
};
#endif /* NetBridge_h */
