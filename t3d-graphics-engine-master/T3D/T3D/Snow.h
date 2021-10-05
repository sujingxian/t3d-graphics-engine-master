#pragma once
#include "gameobject.h"

namespace T3D {
	class Snow : public GameObject
	{
	public:
		Snow(T3DApplication* app);
		~Snow(void);


		GameObject* snows;

		
	};
}

