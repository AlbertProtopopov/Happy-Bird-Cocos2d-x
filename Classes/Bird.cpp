#include "Bird.h"
#include "Param.h"

USING_NS_CC;

Bird::Bird(cocos2d::Layer *layer)
{
	origin = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();

	happyBird = Sprite::create("bluebird-midflap.png");
	happyBird->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	auto happyBody = PhysicsBody::createBox(happyBird->getContentSize());
	happyBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
	happyBody->setContactTestBitmask(true);
	happyBird->setPhysicsBody(happyBody);

	layer->addChild(happyBird, 100);

	isFalling = true;

}

void Bird::Fall()
{
	if (true == isFalling)
	{
		happyBird->setPositionX(visibleSize.width / 2 + origin.x);
		happyBird->setPositionY(happyBird->getPositionY() - (BIRD_FALLING_SPEED * visibleSize.height));
	}
	else
	{
		happyBird->setPositionX(visibleSize.width / 2 + origin.x);
		happyBird->setPositionY(happyBird->getPositionY() + (BIRD_FLYING_SPEED * visibleSize.height));
	}
}

void Bird::BirdAnimate()
{
	Vector <SpriteFrame *> frames;
	frames.reserve(3);
	frames.pushBack(SpriteFrame::create("bluebird-upflap.png", Rect(0, 0, 34, 24)));
	frames.pushBack(SpriteFrame::create("bluebird-downflap.png", Rect(0, 0, 34, 24)));
	frames.pushBack(SpriteFrame::create("bluebird-midflap.png", Rect(0, 0, 34, 24)));

	auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
	auto animate = Animate::create(animation);

	happyBird->runAction(Repeat::create(animate, 2));
}

void Bird::BirdRotate() {

	if ((happyBird->getRotation()) < (-45))
	{
		happyBird->setRotation(-45);
	}
	if ((happyBird->getRotation()) > (90))
	{
		happyBird->setRotation(90);
	}

	if (true == isFalling)
	{

		happyBird->setRotation(happyBird->getRotation() + 2);

	}
	else

	{
		happyBird->setRotation(happyBird->getRotation() - 3);
	}
}

void Bird::BirdFalling() {
	auto moveBy = MoveBy::create(0.25, Vec2(0, 100));
	while (happyBird->getPositionY() > Director::getInstance()->getVisibleSize().height -
		Sprite::create("Background.png")->getContentSize().height)
		
		{
			happyBird->runAction(moveBy);
		}
}

void Bird::Pause()
{
	happyBird->pause();
}