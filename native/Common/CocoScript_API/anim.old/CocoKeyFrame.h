/* ***** BEGIN LICENSE BLOCK *****
 *
 * Copyright (C) 2013 www.coconut2D.org
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef __CocoKeyFrame__
#define __CocoKeyFrame__

#include "Coconut2D.h"
#include "CocoMatrix.h"
//#include "WebGLRenderingContext.h"

// ==================================================================================================================================
//	   ______                 __ __           ______
//	  / ____/___  _________  / //_/__  __  __/ ____/________ _____ ___  ___
//	 / /   / __ \/ ___/ __ \/ ,< / _ \/ / / / /_  / ___/ __ `/ __ `__ \/ _ \
//	/ /___/ /_/ / /__/ /_/ / /| /  __/ /_/ / __/ / /  / /_/ / / / / / /  __/
//	\____/\____/\___/\____/_/ |_\___/\__, /_/   /_/   \__,_/_/ /_/ /_/\___/
//	                                /____/
// ==================================================================================================================================

class CocoKeyFrame
{
public:

    Number frameIndex;
    COCO_KEYFRAME_INTERPOLATION_ENUM frameInterpolation;
    Boolean handleEvents;
    Boolean calcBoundingBox;
    Number alpha;
    Boolean visible;
    Number x;
    Number y;
    Number pivotX;
    Number pivotY;
    Number scaleX;
    Number scaleY;
    Number rotation;
    Function action;
    Number __lastActionExecutionTime;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CocoKeyFrame()
    {
        frameIndex                  = 0;
        frameInterpolation          = COCO_KEYFRAME_INTERPOLATION_ENUM::KEYFRAME_INTERPOLATION_MOTION_TWEEN;
        handleEvents                = false;
        alpha                       = 1.0;
        visible                     = true;
        x                           = 0.0;
        y                           = 0.0;
        pivotX                      = 0.0;
        pivotY                      = 0.0;
        scaleX                      = 1.0;
        scaleY                      = 1.0;
        rotation                    = 0.0;
        action                      = nullptr;
        __lastActionExecutionTime   = 0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CocoKeyFrame* clone()
    {
        CocoKeyFrame* c = new CocoKeyFrame();
        c->alpha					= alpha;
        c->frameIndex            	= frameIndex;
        c->frameInterpolation    	= frameInterpolation;
        c->handleEvents          	= handleEvents;
        c->pivotX                	= pivotX;
        c->pivotY                	= pivotY;
        c->rotation              	= rotation;
        c->scaleX                	= scaleX;
        c->scaleY                	= scaleY;
        c->visible               	= visible;
        c->x                     	= x;
        c->y                     	= y;
        c->action					= action;
        c->calcBoundingBox			= calcBoundingBox;
        return c;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void reset()
    {
        __lastActionExecutionTime = 0.0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void execute(WebGLRenderingContext* gl, Number currentTime, Number loopTime, CocoScene* scene, CocoClip* clip)
    {
        if(currentTime - __lastActionExecutionTime > clip->__timeline->__singleFrameDurationTime)
        {
            __lastActionExecutionTime = currentTime;
            if(action)
            {
				((FPAction)action)(gl, currentTime, loopTime, clip, this);
                //var args:Array = [gl, currentTime, loopTime, clip, this];
                //action.apply(scene, args);
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void interpolate(CocoKeyFrame* F1, CocoKeyFrame* F2, Number s)
    {
        alpha = F1->alpha + s * (F2->alpha - F1->alpha);
        x = F1->x + s * (F2->x - F1->x);
        y = F1->y + s * (F2->y - F1->y);
        scaleX = F1->scaleX + s * (F2->scaleX - F1->scaleX);
        scaleY = F1->scaleY + s * (F2->scaleY - F1->scaleY);
        rotation = F1->rotation + s * (F2->rotation - F1->rotation);
        pivotX = F1->pivotX + s * (F2->pivotX - F1->pivotX);
        pivotY = F1->pivotY + s * (F2->pivotY - F1->pivotY);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void combine(CocoKeyFrame* Frame)
    {
        if(!Frame) return;
        alpha = alpha * Frame->alpha;
        visible = visible & Frame->visible;
        handleEvents = handleEvents & Frame->handleEvents;
        calcBoundingBox = calcBoundingBox & Frame->calcBoundingBox;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void apply(CocoMatrix* matrix)
    {
        if(x!=0 || y!=0) 			matrix->translate(x, y);
        if(rotation!=0)  			matrix->rotateZ(rotation * M_PI / 180.0 );
        if(scaleX!=1 ||scaleY!=1) 	matrix->scale(scaleX, scaleY);
        if(pivotX!=0 || pivotY!=0)	matrix->translate(-pivotX, -pivotY);
    }
}

#endif