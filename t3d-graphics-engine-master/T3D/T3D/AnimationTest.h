#pragma once
#include "Task.h"
#include "T3DApplication.h"

namespace T3D {
	class AnimationTest :

		public Task
	{
	public:
		//! \brief Creates a DrawTask that draws onto a Texture every frame.
		AnimationTest(T3DApplication* app);

		//! \brief Destroy DrawTask (trivially). 
		~AnimationTest(void) = default;
	};
	
}
