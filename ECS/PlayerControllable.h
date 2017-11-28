#ifndef PLAYERCONTROLLABLE_H_
#define PLAYERCONTROLLABLE_H_

#include "Component.h"

#include <dinput.h>

#include "State.h"
class PlayerControllable:public Component
{
	
public:

	SamusState state;

	struct KeyDirections
	{
		// default Key directions
		KeyDirections():up(DIK_UP),down(DIK_DOWN),left(DIK_LEFT),right(DIK_RIGHT) { }

		// change key directions
		KeyDirections(int u,int d,int l,int r):up(u),down(d),left(l),right(r) { }

		// all directions:
		int up, down, left, right;
	
	} directions ;

	struct KeyActions
	{
		// default KeyActions
		KeyActions():shooting(DIK_Z),jumping(DIK_X) { }

		// change key action
		KeyActions(int shoot,int jump):shooting(shoot),jumping(jump) { }

		// all actions
		int shooting, jumping;

	} actions ;

	PlayerControllable( string name);

	~PlayerControllable();
};


#endif // PLAYERCONTROLLABLE_H_


