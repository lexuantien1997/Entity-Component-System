#include <iostream>
#include "Component.h"
#include "Entity.h"
#include "System.h"
#include "Scene.h"
#include "BaseObject.h"
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

class RenderSystem : public BaseObject,public System<Require<Transform, Sprite>, Exclude<>>
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

			// Lấy vị trí của các entity trong scene
			x = entity->getComponent<Transform>("Position")->x;
			y = entity->getComponent<Transform>("Position")->y;

			// lấy bức hình (giả sử nó là hình đi)
			string image = entity->getComponent<Sprite>("Image")->spriteLocation;

			draw(x, y, image); // vẽ hình ra (giả sử nó là hàm vẽ đi cho lẹ)
		}
	}

	void loadResource() { }

};

class CollisionSystem :public BaseObject,public System<Require<Transform, Collision>, Exclude<Camera>>
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

			// Lấy vị trí của các entity trong scene
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

// ==============================================================================================================

class Ground :public Entity
{
public:
	Ground(string name, Scene* s) :Entity{ name,s } { }
	void initialize()
	{
		addComponent<Sprite>("Resource/Ground.png", "Image");
		addComponent<Camera>(1, 2, "Camera");
	}
};

class Enemy :public Entity
{
public:
	Enemy(string name, Scene* s) :Entity{ name,s } { }
	void initialize()
	{
		// Ví dụ samus có các component như: 
		// + Movement
		// + Sprite		
		addComponent<Transform>("position");
		addComponent<Sprite>("Resource/Enemy.png", "Image");
		addComponent<Collision>("Collision");
	}
};

class Samus :public Entity
{
public:

	Samus(string name, Scene* s) :Entity{ name,s } { }

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


class DemoScene :public Scene
{
private:
	// Tạo các entity (xài tạm cái này, tại chưa tạo cái hàm tìm kiếm entity trong `Scene` theo id hoặc name)
	Enemy* enemy;
	Samus* samus;
	Ground* ground;

	CollisionSystem colisionSystem;
	RenderSystem renderSystem;
public:
	DemoScene(string name):Scene(name){ }

	void update(float dt)
	{
		
		colisionSystem.update(dt);
		renderSystem.update(dt);

	}

	// Khởi tạo mọi giá trị trong đây
	void init()
	{
		// ================= Các System có trong demo scene ==================

		addSystem(colisionSystem);
		addSystem(renderSystem);

		//======================== Entity ================================

		 samus =createEntity<Samus>("Samus 1");
		 enemy = createEntity<Enemy>("Enemy 1");
		 ground = createEntity<Ground>("Ground");

		//======================== init entity ==============================
		
		 samus->initialize();
		 enemy->initialize();
		 ground->initialize();

		// ========================= Refresh game =============================
		//  Gọi refresh để nó add các `Entity` và `System` nếu được
		refresh();
	}

	void loadResource()// load resource game
	{
		 // Tìm Entity theo tên hoặc id , sau đó gọi các hàm load resource (chưa làm)

		// load image của Entity samus
		samus->getComponent<Sprite>("Image")->loadImage();
		// load image của Entity enemy
		enemy->getComponent<Sprite>("Image")->loadImage();
		// load image của Entity enemy
		ground->getComponent<Sprite>("Image")->loadImage();
	}

	// Hàm vẽ
	void render()
	{
		renderSystem.render();
		colisionSystem.render();
		
	}
};


void main()
{
	DemoScene* demoScene = new DemoScene("Demo sence");

	
	// Giả sử đây là vòng loop game

	demoScene->init(); // khởi tạo dữ liệu
	demoScene->loadResource(); // Load resource cho mỗi scene


	bool isRunning = true;
	int dt=0.05, maxdelta=0.15;
	while (isRunning)
	{

		if (/*press esc*/ 1) isRunning = false;

		// Tính toán delta time
		if (dt < maxdelta)		
		{
			// update
			demoScene->update(0.01);
			dt += 0.05;
		}
		dt = 0.05;
		// update xong thì vẽ
		demoScene->render();

	}
	

	/*Scene* s=new Scene();
	Thing bb;
	s->addSystem(bb);
	bb.setScene(NULL);
	s->addSystem(bb);*/

	/*Entity *samus = new Entity("Nothing");
	int a = 5, b = 7;
	samus->addComponent<Collision>("collision1");
	samus->addComponent<Sprite>(a, b, "Sprite1");
	samus->addComponent<Sprite>(a, b, "Sprite2");*/
	
	//samus->addComponent<Collision>("collision2.png");
	//samus->addComponent<Collision>("collision3");
	//samus->addComponent<Camera>(a, b, "Sprite1");


	/*Entity *enemy = new Entity("Nothing 2");
	enemy->addComponent<Collision>("collision1");
	enemy->addComponent<Animation>(a, b, "Animation1");*/

	system("pause");
}
