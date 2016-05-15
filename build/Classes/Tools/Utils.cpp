//
//  Utils.cpp
//  build
//
//  Created by Deflinhec on 2016/4/27.
//
//

#include "Utils.h"

CUtils::CharData CUtils::ToCharData(int _id, char* _givenName, int _recordWin, int _recordLost){
    
    CharData* data = new CharData();
    
    data->Id            = _id;
    data->GivenName     = _givenName;
    data->RecordWin     = _recordWin;
    data->RecordLost    = _recordLost;
    
    return *data;
}

CUtils::RoomData CUtils::ToRoomData(int _id, char *_roomName, int _maxPlayers, int _curPlayers){
    
    RoomData* data = new RoomData();
    
    data->Id = _id;
    data->RoomName = _roomName;
    data->MaxPlayers = _maxPlayers;
    data->CurPlayers = _curPlayers;
    
    return *data;
}