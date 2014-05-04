/* Generated by Coconut2D C++ Compiler from file DeviceTouches.jspp */

#ifndef __DEVICETOUCHES_HPP__
#define __DEVICETOUCHES_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Coconut2D.hpp"
#include "IEventTarget.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Touch
{
public:
	int identifier;
	int screenX;
	int screenY;
	int clientX;
	int clientY;
	int pageX;
	int pageY;
	IEventTarget* target;
	Touch();
	virtual ~Touch();
	void initTouch(int identifier, IEventTarget* target, int screenX, int screenY, int clientX, int clientY, int pageX, int pageY);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class TouchList : public Array<Touch*>
{
public:
	int length;
	TouchList();
	Touch* item(int index);
};

#endif // __DEVICETOUCHES_HPP__