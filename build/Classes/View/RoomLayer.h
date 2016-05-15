//
//  RoomLayer.h
//  build
//
//  Created by Deflinhec on 2016/5/16.
//
//

#ifndef RoomLayer_h
#define RoomLayer_h

#include "UIFrame.h"

class CRoomLayer : public IUIFrame<CRoomLayer>{
public:
    
    CRoomLayer(){};
    
    virtual ~CRoomLayer(){};
    
    /**
     * @brief call on create function.
     */
    void init(cocos2d::Node* _node);
};

#endif /* RoomLayer_h */
