#include "CocoAudio.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoAudio::CocoAudio(String url, bool autoplay, int loops)
{
	src = url;
	audio = new Audio(url);
	audio->autoplay = false;
	audio->loop = false;
	this->autoplay = autoplay;
	this->loops = loops;
	__firstPlayed = false;
	__loopCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
CocoAudio::~CocoAudio()
{
	if(audio)
	{
		audio = (delete audio, NULL);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoAudio::tick()
{
	if(!audio || !audio->src)
	{
		return;
	}
	if(!__firstPlayed && autoplay)
	{
		__firstPlayed = true;
		play();
	}
	trace(src + " : " + String(getCurrentTime()));
	if(loops >= 0 && audio->ended)
	{
		__loopCount++;
		if(loops == 0 || (loops > 0 || __loopCount < loops))
		{
			play();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoAudio::play()
{
	if(audio)
	{
		audio->play();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoAudio::pause()
{
	if(audio)
	{
		audio->pause();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoAudio::stop()
{
	__loopCount = 0;
	__firstPlayed = true;
	if(audio)
	{
		audio->pause();
	}
	setCurrentTime(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CocoAudio::duration()
{
	return audio ? audio->duration : 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool CocoAudio::paused()
{
	return audio ? audio->paused : true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool CocoAudio::ended()
{
	return audio ? audio->ended : true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float CocoAudio::getCurrentTime()
{
	return audio ? audio->currentTime : 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void CocoAudio::setCurrentTime(float t)
{
	if(audio)
	{
		audio->currentTime = t;
	}
}