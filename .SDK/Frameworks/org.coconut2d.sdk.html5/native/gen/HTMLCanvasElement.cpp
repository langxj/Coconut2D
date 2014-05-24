/* Generated by Coconut2D C++ Compiler from file HTMLCanvasElement.jspp */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "HTMLCanvasElement.hpp"
#include "ImageData.hpp"
#include "CanvasRenderingContext2D.hpp"
#include "WebGLRenderingContext.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
HTMLCanvasElement::HTMLCanvasElement()
{
	width = 0.0;
	height = 0.0;
	__imageData = nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
HTMLCanvasElement::~HTMLCanvasElement()
{
	if(__imageData)
	{
		__imageData = (delete __imageData, nullptr);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void* HTMLCanvasElement::getContext(String contextId)
{
	if(contextId == String("2d"))
	{
		return ((void*)new CanvasRenderingContext2D(this));
	}
	else
	{
		return ((void*)new WebGLRenderingContext(this));
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
String HTMLCanvasElement::toDataURL()
{
	return String("data:image/png;base64,") + (__imageData ? __imageData->data->buffer->encodeAsPNG(__imageData->width, __imageData->height)->encodeAsBase64() : String("iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAALUlEQVRYR+3QQREAAAABQfqXFsNnFTizzXk99+MAAQIECBAgQIAAAQIECBAgMBo/ACHo7lH9AAAAAElFTkSuQmCC"));
}