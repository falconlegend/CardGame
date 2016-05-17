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
    
    /***************************
    *    Common       action   *
    ****************************/    
    
    /**
     * @brief Calls when main player peek on a specific char or specific are in the same area with main character.
     * @param Websocket::Data
     */
    virtual void UpdateCharAttr(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /***************************
    *    Server Lobby action   *
    ****************************/
    
    /**
     * @brief Server notify model to update a complete loby object. 
     *        If the lobby have already exist then update the attribute, otherwise create a new one.
     *        Calls when main player join into a loby.
     * @param Websocket:Data < CLoby >
     * @return void
     */
    virtual void UpdateLoby(coocs2d::network::WebSocket::Data& _data) = 0;
    
     /**
     * @brief Server notify Model to update a specific Loby attribute e.g Double exp, Double coin, bonus, lock and unlock
     * @param Websocket::Data < update type, data >
     * @return void
     */
    virtual void UpdateLobyAttr(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Server notify Model to update a entire room list of Loby. Calls when player first join into a Loby, and call like every 1 min.
     * @param Websocket::Data < update type, data >
     * @return void
     */
    virtual void UpdateRoomList(cocos2d::network::WebSocket::Data& _data) = 0;
    
     /**
     * @brief While otehr player create room in main player's lobby, notify model to update room list in CLoby object.
     * @param Websocket::Data < CRoom >
     * @return void
     */
    virtual void AddRoom(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief While other player create room in main player's lobby, notify model to update room list in CLoby object.
     * @param Websocket::Data < Int >
     * @return void
     */
    virtual void RemoveRoom(cocos2d::networkd::WebSocket::Data& _data) = 0;
    
     /**
     * @brief Server notify Model to update a entire character list of Loby. Calls when player first join into a Loby, and call like every 1 min.
     * @param Websocket::Data < update type, data >
     * @return void
     */
    virtual void UpdateLobbyCharacterList(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief While otehr player join main player's lobby, notify model to update character list in CLoby object.
     * @param Websocket::Data < CCharacter >
     * @return void
     */
    virtual void CharJoinLobby(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief While other player join main player's lobby, notify model to update character list in CLoby object.
     * @param Websocket::Data < int >
     * @return void
     */
    virtual void CharLeaveLobby(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /***************************
    *    Server Room action    *
    ****************************/
    
    /**
     * @brief Server notify model to update a complete room object. 
     *        If the room have already exist then update the attribute, otherwise create a new one.
     *        Calls this function while main character have join into a room.
     * @param Websocket:Data < CRoom >
     * @return void
     */
    virtual void UpdateRoom(coocs2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief Calls when room state have change. e.g lock,unlock, name change, owner change, state change.
     * @param Websocket::Data <update type, data>
     * @return void
     */
    virtual void UpdateRoomAttr(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief While main player is in specific room, server will notify user that a new user have just join in same room.
     * @param Websocket::Data
     */
    virtual void CharJoinRoom(cocos2d::network::WebSocket::Data& _data) = 0;
    
    /**
     * @brief While otehr player leave a room which same as main player's room, server notify CRoom object to update character list.
     * @param Websocket::Data < int >
     */
    virtual void CharLeaveRoom(cocos2d::network::WebSocket::Data& _data) = 0;
     
    /***************************
     *    Server Game action   *
     ***************************/
     
     /**
      * @brief While a round have end, notify player the match result of this round
      * @param Websocket::Data <int , int>
      * @return void
      */
    virtual void NotifyRoundResult(cocos2d::network::WebSocket::Data& _data) = 0;
     
     /**
      * @brief While main player is in game, notify state of this game. e.g ready, game start, round start, round end, game end.
      * @param Websocket::Data
      */
    virtual void UpdateGameState(cocos2d::network::WebSocket::Data& _data) = 0; 
     
     /**
      * @brief While game comes to an end notify state of this game. e.g rewards
      * @param Websocket::Data
      */
    virtual void NotifyGameResult(cocos2d::network::WebScoket::Data& _data) = 0;
     
     /**
      * @brief Calls when the otehr user have lost connection
      * @param Websocket::Data < string >
      * @return void
      */
    virtual void NotifyDisconnection(cocos2d::network::WebSocket::Data& _data) = 0;
};

#endif /* NetBridge_h */
