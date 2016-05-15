//
//  procotols.h
//  build
//
//  Created by Deflinhec on 2016/4/17.
//
//

#ifndef eventType_h
#define eventType_h

class CEvent{
public:
    enum Connection{
        eUpdateMainAttr,
        eUpdatePlayerAttr
    };
    enum RoomOperate{
        eOnGameStart,
        eOnGameEnd,
        eOnUserLeave,
        eOnUserDisconnect
    };
};

class CCommand{
public:
    enum Connection{
        eEnterNode,
        eExitNode
    };
    
    enum RoomOperate{
        eJoin,
        eLeave
    };
};




#endif /* eventType_h */
