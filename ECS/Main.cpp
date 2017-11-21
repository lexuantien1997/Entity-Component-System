#include <iostream>
#include "Component.h"
#include "Entity.h"
#include "System.h"
#include "Base.h"

#include "GameWorld.h"

class GameWorld;

using namespace std;


// ====================================================== Component =============================================
class Component;
class Sprite :public Component
{
private:

public:
	string spriteLocation; // giả sử đây là nơi lưu bức hình
	void loadImage()
	{
		// do sth to load image
	}
	Sprite(string loc, string name) :Component(name), spriteLocation(loc)
	{

	}
};

class Transform :public Component
{

public:
	int x, y;
	Transform(string name) :Component(name)
	{

	}
};

class Animation :public Component
{
	int nstate; // số trạng thái samus có
public:
	Animation(int state, string name) :Component(name)
	{

	}
};

class Camera :public Component
{
public:
	Camera(int a, int b, string name) :Component(name)
	{

	}
};

class Collision :public Component
{
private:

public:
	int ca, cb;
	Collision(string name) :Component(name)
	{

	}
};

// ==============================================================================================================

// ==================================================== System ==================================================

using namespace FILTER;

class RenderSystem : public Base, public System<Require<Transform, Sprite>, Exclude<>>
{
public:

	void draw(int x, int y, string image)
	{

	}
	RenderSystem()
	{

	}

	void init() { }
	// Update the game
	void update(float dt) { }
	void render()
	{
		for (auto entity : getEntities())
		{
			int x, y;

			// Lấy vị trí của các entity trong GameWorld
			x = entity->getComponent<Transform>("Position")->x;
			y = entity->getComponent<Transform>("Position")->y;

			// lấy bức hình (giả sử nó là hình đi)
			string image = entity->getComponent<Sprite>("Image")->spriteLocation;

			draw(x, y, image); // vẽ hình ra (giả sử nó là hàm vẽ đi cho lẹ)
		}
	}

	void loadResource() { }

};

class CollisionSystem :public Base, public System<Require<Transform, Collision>, Exclude<Camera>>
{
public:
	CollisionSystem()
	{

	}

	void _collision(int a, int b, int c, int d)
	{
		// code cái gì đó trong đây
	}

	void init()
	{

	}

	// Update the game
	void update(float dt)
	{
		for (auto entity : getEntities())
		{
			int x, y, cx, cy;

			// Lấy vị trí của các entity trong GameWorld
			x = entity->getComponent<Transform>("Position")->x;
			y = entity->getComponent<Transform>("Position")->y;

			// Lấy vị trí va chạm
			cx = entity->getComponent<Collision>("Collision")->ca;
			cy = entity->getComponent<Collision>("Collision")->cb;

			_collision(x, y, cx, cy); // gọi hàm va chạm ra dùng
		}
	}

	void render() { } // có thì code ko có thì để đó

	void loadResource() { }
};

class MovementSystem : public Base, public System <Require<Transform, Transform>, Exclude<>>
{
public:
	MovementSystem()
	{

	}

	void _collision(int a, int b, int c, int d)
	{
		// code cái gì đó trong đây
	}

	void init()
	{

	}

	// Update the game
	void update(float dt)
	{

	}

	void render() 
	{
		for (auto entity : getEntities())
		{
			int x, y, cx, cy;

			// Lấy vị trí của các entity trong GameWorld
			x = entity->getComponent<Transform>("Position")->x;
			y = entity->getComponent<Transform>("Position")->y;

			// Lấy vị trí va chạm
			cx = entity->getComponent<Collision>("Collision")->ca;
			cy = entity->getComponent<Collision>("Collision")->cb;

			_collision(x, y, cx, cy); // gọi hàm va chạm ra dùng
		}
	} // có thì code ko có thì để đó

	void loadResource() { }
};

// ==============================================================================================================

class Ground :public Entity
{
public:
	Ground(string name, GameWorld* s) :Entity{ name,s } { }
	void initialize()
	{
		addComponent<Sprite>("Resource/Ground.png", "Image");
		addComponent<Camera>(1, 2, "Camera");
	}
};

class Enemy :public Entity
{
public:
	Enemy(string name, GameWorld* s) :Entity{ name,s } { }
	void initialize()
	{
		// Ví dụ samus có các component như: 
		// + Movement
		// + Sprite		
		addComponent<Transform>("Position");
		addComponent<Sprite>("Resource/Enemy.png", "Image");
		addComponent<Collision>("Collision");
	}
};

class Samus :public Entity
{
public:

	Samus(string name, GameWorld* s) :Entity{ name,s } { }

	void initialize()
	{
		// Ví dụ samus có các component như: 
		// + Velocity 1
		// + Velocity 2
		// + Movement
		// + Animation
		// + Sprite

		addComponent<Transform>("Velocity 1");
		addComponent<Transform>("Velocity 2");
		addComponent<Transform>("Movement");
		addComponent<Transform>("Position");
		addComponent<Collision>("Collision");
		addComponent<Sprite>("Resource/Samus.png", "Image");
		addComponent<Animation>(20, "Image");
	}
};

class Game :public Base
{
private:

	GameWorld* s=new GameWorld();
	// Tạo các entity (xài tạm cái này, tại chưa tạo cái hàm tìm kiếm entity trong `GameWorld` theo id hoặc name)
	Enemy* enemy;
	Samus* samus;
	Ground* ground;

	MovementSystem movementSystem;
	CollisionSystem colisionSystem;
	RenderSystem renderSystem;
	
public:

	void update(float dt)
	{
		colisionSystem.update(dt);
		renderSystem.update(dt);
	}

	void render()
	{
		movementSystem.render();
		renderSystem.render();
		colisionSystem.render();
	}

	void init()
	{

		//======================== Entity ================================

		samus = s->createEntity<Samus>("Samus 1");
		enemy = s->createEntity<Enemy>("Enemy 1");
		ground = s->createEntity<Ground>("Ground");

		//======================== init entity ==============================

		samus->initialize();
		enemy->initialize();
		ground->initialize();

		// ================= Các System có trong demo GameWorld ==================

		s->addSystem(movementSystem);

		s->addSystem(colisionSystem);

		s->addSystem(renderSystem);

		// ========================= Refresh game =============================
		//  Gọi refresh để nó add các `Entity` và `System` nếu được
		s->refresh();
	}

	void loadResource()
	{
		// Tìm Entity theo tên hoặc id , sau đó gọi các hàm load resource (chưa làm)

		// load image của Entity samus
		samus->getComponent<Sprite>("Image")->loadImage();
		// load image của Entity enemy
		enemy->getComponent<Sprite>("Image")->loadImage();
		// load image của Entity enemy
		ground->getComponent<Sprite>("Image")->loadImage();
	}

};

void main()
{
	
	Game *demoGameWorld=new Game();


	// Giả sử đây là vòng loop game

	demoGameWorld->init(); // khởi tạo dữ liệu
	demoGameWorld->loadResource(); // Load resource cho mỗi GameWorld


	bool isRunning = true;
	float dt = 0.05, maxdelta = 0.15;
	while (isRunning)
	{

		// if (/*press esc*/ 1) isRunning = false;

		// Tính toán delta time
		if (dt < maxdelta)
		{
			// update
			demoGameWorld->update(0.01);
			dt += 0.05;
		}
		dt = 0.05;
		// update xong thì vẽ
		demoGameWorld->render();

	}

	system("pause");
}