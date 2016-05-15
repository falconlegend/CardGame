//
//  GameLayer.h
//  build
//
//  Created by Deflinhec on 2016/5/15.
//
//

#ifndef GameLayer_h
#define GameLayer_h

#include "UIFrame.h"

class CGameLayer : public IUIFrame<CGameLayer>{
public:
    
    CGameLayer(){};
    
    /**
     * @brief call on create function.
     */
    void init(cocos2d::Node* _node);
};

#endif /* GameLayer_h */
