#pragma once
#include "gameobject.h"

namespace T3D {
	class TabletComposite : public GameObject
	{
	public:
		TabletComposite(T3DApplication* app);
		~TabletComposite(void);
		
		
		GameObject* shelfLeft;
		GameObject* shelfRight;
		GameObject* spring1;
		GameObject* spring2;
		GameObject* backShelf;
		GameObject* link1;
		GameObject* arm1;
		GameObject* arm2;
		GameObject* link2;
		GameObject* base;



		
		GameObject* springJoint;
		GameObject* backShelfJoint;
		GameObject* armJoint1;
		GameObject* armJoint2;
		GameObject* armJoint3;
		GameObject* baseJoint;
		
	};
}

