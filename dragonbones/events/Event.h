﻿#ifndef __EVENT_H__
#define __EVENT_H__

#include "utils/preDB.h"
#include "cocoa/CCObject.h"
#include <functional>


namespace dragonBones
{
    class Event
    {
        String _type;
    public:
        Event(const String &type)
        : _type(type)
        {};
        virtual ~Event(){};

        const String &getType()const
        {
            return _type;
        }
    };

    class EventDispatcher
    {
    public:
        //typedef std::function<void(Event*)> Function;
        typedef void (cocos2d::CCObject::*Function)(Event *);
        // 使用 EventDispatcher 对象注册事件侦听器对象，以使侦听器能够接收事件通知，key是这个回调的唯一标示，用来removeEventListener反注册用的
        void addEventListener(const String &type, cocos2d::CCObject* pTarget, Function listener , const std::string &key);

        // 将事件调度到事件流中。
        void dispatchEvent(Event *event);

        // 检查 EventDispatcher 对象是否为特定事件类型注册了任何侦听器。  
        bool hasEventListener(const String &type)const;

        // 从 EventDispatcher 对象中删除侦听器。 
        void removeEventListener(const String &type, const std::string &key);
    protected:

        typedef std::pair<Function , std::string> Callback;
        typedef std::list<Callback> Listeners;
        typedef std::map<String , Listeners> EventListeners;
        // 保存所有侦听器列表
        EventListeners mEventListeners;
        
        //
        cocos2d::CCObject*     mpEventTarget;
    };
}
#endif // __EVENT_H__
