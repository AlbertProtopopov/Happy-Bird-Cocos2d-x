#ifndef __PIPE_H__
#define __PIPE_H__

#include "cocos2d.h"

class Pipe 
{
public:
	Pipe();

	void SpawnPipe(cocos2d::Layer *layer);

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	cocos2d::Sprite* topPipe;
	cocos2d::Sprite* bottomPipe;

};

#endif // __PIPE_H__
