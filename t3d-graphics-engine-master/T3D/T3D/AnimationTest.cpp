#include "AnimationTest.h"
#include "WinGLApplication.h"
#include "GLRenderer.h"
#include "Camera.h"
#include "Transform.h"
#include "GameObject.h"
#include "KeyboardController.h"
#include "Renderer.h"
#include "Cube.h"
#include "Math.h"
#include "Light.h"
#include "Component.h"
#include "Vector3.h"
#include "Mesh.h"
#include "Material.h"
#include "Colour.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "Lamp.h"
#include "Animation.h"

float elapsedTime;

//namespace T3D {
//	AnimationTest::AnimationTest(T3DApplication* app) : Task(app)
//	{
//		elapsedTime = 0;
//		
//		lamp = NULL;
//
//	}
//	void AnimationTest::update(float dt) {
//		elapsedTime += dt;
//		lamp->setLocalPosition(Vector3::lerp(Vector3(0, 0, 0), Vector3(1, 0, 0), elapsedTime / 10.0));
//	}
//}
		