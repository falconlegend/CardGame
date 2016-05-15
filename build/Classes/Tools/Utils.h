//
//  Utils.h
//  build
//
//  Created by Deflinhec on 2016/4/27.
//
//

#ifndef Utils_h
#define Utils_h

#define USERDB cocos2d::UserDefault::getInstance()
#define GET_CUR_TIME CUtils::GetCurTime()

class CUtils{
public:
    
    struct CharData{
        int Id;
        char* GivenName;
        int RecordWin;
        int RecordLost;
        CharData(){
            Id = 0;
            GivenName = 0;
            RecordWin = 0;
            RecordLost = 0;
        }
    };
    
    struct RoomData{
        int Id;
        char* RoomName;
        int MaxPlayers;
        int CurPlayers;
        RoomData(){
            Id = 0;
            RoomName = 0;
            MaxPlayers = 0;
            CurPlayers = 0;
        }
    };
    

    static inline float GetCurTime(){
        tm* st;
        time_t t = time(NULL);
        st = gmtime(&t);
        t = timelocal(st);
        return t;
    }
        

    
public:
    
    static CharData ToCharData(int _id, char* _givenName, int _recordWin, int _recordLost);
    
    static RoomData ToRoomData(int _id, char* _roomName, int _maxPlayers, int _curPlayers);
};

#endif /* Utils_h */
