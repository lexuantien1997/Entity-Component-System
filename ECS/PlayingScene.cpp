﻿#include "PlayingScene.h"

#include "Transform.h"
#include "Sprite.h"
#include "PlayerControllable.h"
#include "Velocity.h"
#include "Animation.h"
#include "EventManager.h"


PlayingScene::PlayingScene():Scene("Playing scene")
{

}


PlayingScene::~PlayingScene()
{

}

void PlayingScene::update(float dt)
{

	inputSystem.update(dt);
	movementSystem.update(dt);
	renderSystem.update(dt);

}

void PlayingScene::init()
{
	SpriteManager::getInstance()->loadResource("resources/charactor/samus_states.xml", WorldID::Samus);

	

	// system
	world->addSystem<RenderingSystem>(renderSystem);
	world->addSystem<InputSystem>(inputSystem);
	world->addSystem<MovementSystem>(movementSystem);
	world->addSystem<AnimationSystem>(animationSystem);

	// Đăng ký sự kiện qua trái:
	EventManager::getInstance()->registerEvent(EventId::MOVE_LEFT);

	// Gắn cái sự kiện qua trái đó vào `Animation System`
	EventManager::getInstance()->attachEvent(EventId::MOVE_LEFT, &animationSystem);

	// entity:
	 Entity* Samus = world->create_Entity("Samus");

	 auto transform=Samus->addComponent<Transform>("transform 1");
	 auto sprite = Samus->addComponent<Sprite>("resources/charactor/samus_aran.bmp", "sprite 1");
	 auto velocity= Samus->addComponent<Velocity>("velocity 1");
	 auto playerControl = Samus->addComponent<PlayerControllable>("player controllable 1");
	 auto animation = Samus->addComponent<Animation>("aniamtion 1");

	 velocity->initVelocity(Vector2f(0, 0), Vector2f(0, 0));
	 transform->initTransform(Vector2f(100, 200), Vector2f(0, 0), Vector2f(1, 1), 0);
	 animation->loadAnimation(WorldID::Samus);

	 world->refresh();
}

void PlayingScene::render()
{
	renderSystem.render();
}


