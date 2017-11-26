#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_
#include "Singleton.h"
#include <vector>

class Scene;

class SceneManager :public Singleton<SceneManager>
{
private:
	std::vector<Scene*> scenes;
public:

	SceneManager();

	~SceneManager();

	void addScene(Scene* s);

	void removeScene();

	void clear();

	Scene* getCurrentScene();

	void replaceScene(Scene* s);

	void update(float dt);

	void init();

	void render();

	void release();
};

#endif
