﻿#include "GameEngine.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
GameEngine::GameEngine()
{
	setNextState(STATE_GAME);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
GameEngine::~GameEngine()
{
}

//=======================================================
// State: STATE_GAME
//=======================================================

////////////////////////////////////////////////////////////////////////////////////////////////////
void GameEngine::STATE_GAME::enter()
{
	self->scene = new NewAnimation();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GameEngine::STATE_GAME::exit()
{
	if(self->scene)
	{
		self->scene = (delete self->scene, nullptr);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GameEngine::STATE_GAME::tick(float time)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void GameEngine::STATE_GAME::paint(WebGLRenderingContext* gl, Time time)
{
	self->scene->paint(gl, time);
}
