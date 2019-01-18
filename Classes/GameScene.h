#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Pipe.h"
#include "Bird.h"


class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

	void PauseBirdG();

    bool init();

    CREATE_FUNC(GameScene);

private:

	unsigned int score;

	void setPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; };
	
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	void StopFlying(float dt);

	void update(float dt);

	void BaseMovingController();
	
	void flapEffect();

	void pointEffect();

	void hitEffect();
	
	void SpawnPipe(float dt);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	
	bool onContactBegin(cocos2d::PhysicsContact &contact);

	Pipe pipe;
	Bird *bird;
	
	cocos2d::PhysicsWorld *sceneWorld;

	cocos2d::Size visibleSize;

	cocos2d::Sprite *Base;
	cocos2d::Label *getReady;

	cocos2d::Label *scoreLabel;
	cocos2d::Label *instructionLabel;

};

#endif // __GAME_SCENE_H__
