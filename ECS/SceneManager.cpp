#include "SceneManager.h"
#include "Scene.h"


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::addScene(Scene * s)
{
	scenes.emplace_back(s);

	scenes.back()->init();
}

void SceneManager::removeScene()
{
	if (scenes.empty()!=NULL)
	{
		delete scenes.back();

		scenes.pop_back();
	}
}

void SceneManager::clear()
{
	if (!scenes.empty())
		scenes.clear();
}

Scene * SceneManager::getCurrentScene()
{
	return scenes.empty() != NULL ? scenes.back() : NULL;
}

void SceneManager::replaceScene(Scene * s)
{
	removeScene();

	addScene(s);
}

void SceneManager::update(float dt)
{
	if (!scenes.empty())
		scenes.back()->update(dt);
}

void SceneManager::init()
{
	if (!scenes.empty())
		scenes.back()->init();
}

void SceneManager::render()
{
	if (!scenes.empty())
		scenes.back()->render();
}

void SceneManager::release()
{
	for (auto scene :scenes)
	{
		scene->release();
	}

	clear();
}
