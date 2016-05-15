//
//  LobbyLayer.h
//  build
//
//  Created by Deflinhec on 2016/5/15.
//
//

#ifndef LobbyLayer_h
#define LobbyLayer_h

#include "UIFrame.h"

class CLobbyLayer : public IUIFrame<CLobbyLayer>{
public:
    
    CLobbyLayer(){};
    
    /**
     * @brief call on create function.
     */
    void init(cocos2d::Node* _node);
};

#endif /* LobbyLayer_h */
