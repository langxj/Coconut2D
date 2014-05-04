/* Generated by Coconut2D C++ Compiler from file CocoUIView.jspp */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "CocoUIView.hpp"
#include "CocoClip.hpp"
#include "WebGLRenderingContext.hpp"
#include "CocoScene.hpp"
#include "HTMLCanvasElement.hpp"
#include "HTMLDocument.hpp"
#include "CanvasRenderingContext2D.hpp"
#include "HTMLCanvasContext.hpp"
#include "CocoImage.hpp"
#include "HTMLImageElement.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoUIView::CocoUIView()
{
	__textureIsInvalid = true;
	__enabled = true;
	__visible = true;
	__x = 0;
	__y = 0;
	__width = 320;
	__height = 480;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoUIView::~CocoUIView()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
String CocoUIView::__get_Name()
{
	return __instanceName;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::__set_Name(String v)
{
	__instanceName = v;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool CocoUIView::__get_Enabled()
{
	return __enabled;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::__set_Enabled(bool v)
{
	__enabled = v;
	invalidate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CocoUIView::__get_Width()
{
	return __width;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::__set_Width(float v)
{
	__width = v;
	invalidate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CocoUIView::__get_Height()
{
	return __height;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::__set_Height(float v)
{
	__height = v;
	invalidate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CocoUIView::__get_Left()
{
	return __x;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::__set_Left(float v)
{
	__x = v;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CocoUIView::__get_Top()
{
	return __y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::__set_Top(float v)
{
	__y = v;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool CocoUIView::__get_Visible()
{
	return __visible;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::__set_Visible(bool v)
{
	__visible = v;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::move(float x, float y, float width, float height)
{
	__x = x;
	__y = y;
	__width = width;
	__height = height;
	invalidate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::invalidate()
{
	__textureIsInvalid = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::paint(WebGLRenderingContext* gl, CocoScene* scene, CocoClip* parentClip, bool calcBoundingBox, int level)
{
	if(!__visible || !parentClip || !scene || !gl)
	{
		return;
	}
	if(__textureIsInvalid)
	{
		HTMLCanvasElement* canvas = document->createElement(String("canvas"));
		canvas->width = pow(2, ceil((float)(log(__width)) / (float)(log(2))));
		canvas->height = pow(2, ceil((float)(log(__height)) / (float)(log(2))));
		CanvasRenderingContext2D* ctx = ((CanvasRenderingContext2D*)canvas->getContext(String("2d")));
		repaint(scene, parentClip, ctx);
		if(__image)
		{
			__image = (delete __image, nullptr);
		}
		__image = new CocoImage();
		__image->image = new Image();
		String url = canvas->toDataURL();
		__image->image->load(url);
		__image->textureCellWidth = ((float)__width);
		__image->textureCellHeight = ((float)__height);
		__image->textureGrid = new Float32Array((new Array<float> ())->push(0)->push(0));
		__image->prepare(scene, gl);
		ctx = nullptr;
		if(canvas)
		{
			canvas = (delete canvas, nullptr);
		}
		__textureIsInvalid = false;
	}
	CocoClip::paint(gl, scene, parentClip, calcBoundingBox, level);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoUIView::repaint(CocoScene* scene, CocoClip* parentClip, CanvasRenderingContext2D* ctx)
{
}