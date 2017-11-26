#include "PlayingScene.h"

#include "Transform.h"
#include "Sprite.h"
#include "PlayerControllable.h"
#include "Velocity.h"

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
	// just bingding data

	InputManager::getInstance()->onKeyDown = std::bind(&PlayingScene::onkeyDown, this, std::placeholders::_1);

	InputManager::getInstance()->onKeyUp = std::bind(&PlayingScene::onkeyUp, this, std::placeholders::_1);

	// system
	world->addSystem<RenderingSystem>(renderSystem);
	world->addSystem<InputSystem>(inputSystem);
	world->addSystem<MovementSystem>(movementSystem);

	// entity:
	 Entity* Samus = world->create_Entity("Samus");

	 auto transform=Samus->addComponent<Transform>("transform 1");
	 auto sprite = Samus->addComponent<Sprite>("resources/charactor/samus_aran.bmp", "sprite 1");
	 auto velocity= Samus->addComponent<Velocity>("velocity 1");
	 auto playerControl = Samus->addComponent<PlayerControllable>("player controllable 1");

	 velocity->initVelocity(Vector2f(0, 0), Vector2f(0, 0));
	 transform->initTransform(Vector2f(100, 200), Vector2f(0, 0), Vector2f(1, 1), 0);

	 world->refresh();
}

void PlayingScene::render()
{
	renderSystem.render();
}

void PlayingScene::onkeyUp(int key)
{

}

void PlayingScene::onkeyDown(int key)
{

}
