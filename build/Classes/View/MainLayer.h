//
//  MainLayer.h
//  build
//
//  Created by Deflinhec on 2016/5/15.
//
//

#ifndef MainLayer_h
#define MainLayer_h

#include "UIFrame.h"

class CMainLayer : public IUIFrame<CMainLayer>{
public:
    
    CMainLayer(){};
    
    virtual ~CMainLayer(){};
    
    /**
     * @brief call on create function.
     */
    void init(cocos2d::Node* _node);
    
public:
    cocos2d::ui::Button* m_pkFacebookBtn;
    cocos2d::ui::Button* m_pkLocalBtn;
};

#endif /* MainLayer_h */
