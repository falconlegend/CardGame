//
//  MainLayer.cpp
//  build
//
//  Created by Deflinhec on 2016/5/15.
//
//

#include "MainLayer.h"

void CMainLayer::init(cocos2d::Node *_node){
    
    IGetBtn(m_pkFacebookBtn, "facebook");
    IGetBtn(m_pkLocalBtn   , "local"   );
    
}