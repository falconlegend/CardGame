//
//  GameMarco.h
//  build
//
//  Created by Deflinhec on 2016/4/22.
//
//

#ifndef GameMarco_h
#define GameMarco_h

#define REGISTEREVENT(function) \
    cocos2d::Director::getInstance()-> \
    getEventDispatcher()->addCustomEventListener \
    (std::string("##function"), CC_CALLBACK_1(function,this));

#define DISPATCHEVENT(function, data) \
    cocos2d::Director::getInstance()-> \
    getEventDispatcher()-> \
    dispatchCustomEvent(std::string("##function"), data);

#endif /* GameMarco_h */
