//
//  definitions.h
//  MindCard
//
//  Created by Deflinhec on 2016/5/7.
//
//

#ifndef definitions_h
#define definitions_h

namespace DDef {
    typedef std::map<int, cocos2d::Ref*>  RefMap;
    typedef std::map<int, cocos2d::Node*> NodeMap;
};

template <class T>
class Singleton
{
public:
    static T* Instance() {
        if (m_instance == NULL) {
            m_instance = new T();
            m_instance->init();
        }
        return m_instance;
    }
    
    virtual void init() = 0;
protected:
    typedef std::function<void (cocos2d::EventCustom*)> FInvoke;
    typedef std::map<const char*,FInvoke> FMap;
    
    FMap InvokeMap;
    
private:
    static T* m_instance;

};

template<class T>
T* Singleton<T>::m_instance = NULL;

namespace InvokeParam {
    static const char* LFSMainPlayerData = "LFSMainPlayerData";
    static const char* LFSAllCharData = "LFSAllCharData";
    static const char* LFSAllGameData = "LFSAllGameData";
    static const char* LFSAllLobyData = "LFSAllLobyData";
}
#endif /* definitions_h */
