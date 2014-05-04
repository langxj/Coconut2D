/* Generated by Coconut2D C++ Compiler from file CocoEvents.jspp */

#ifndef __COCOEVENTS_HPP__
#define __COCOEVENTS_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Coconut2D.hpp"
#include "IEventTarget.hpp"
#include "DeviceTouches.hpp"
#include "IEventListener.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CocoEvent
{
public:
	String type;
	IEventTarget* target;
	IEventTarget* currentTarget;
	bool bubbles;
	bool cancelable;
	int timeStamp;
	bool stopPropagation;
	bool defaultPrevented;
	int detail;
	TouchList* touches;
	TouchList* targetTouches;
	TouchList* changedTouches;
	float scale;
	float rotation;
	int clientX;
	int clientY;
	int __clientX;
	int __clientY;
	CocoEvent(String type, bool cancelable, bool bubbles);
	virtual ~CocoEvent();
	bool is(CocoEvent* Event);
	void cancelBubble();
	void preventDefault();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CocoEventConnectionPoint
{
public:
	CocoEvent* Event;
	Function* Callback;
	IEventListener* Listener;
	CocoEventConnectionPoint(CocoEventSource* Source, CocoEvent* Event, IEventListener* Listener, Function* Callback);
	virtual ~CocoEventConnectionPoint();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CocoEventSource
{
public:
	Array<CocoEventConnectionPoint*>* __eventListeners;
	CocoEventSource();
	virtual ~CocoEventSource();
	virtual void addEventListener(CocoEvent* Event, IEventListener* Listener, Function* Callback);
	virtual bool removeEventListener(CocoEvent* Event, IEventListener* Listener, Function* Callback);
	virtual int dispatchEvent(CocoEvent* Event);
};

#endif // __COCOEVENTS_HPP__