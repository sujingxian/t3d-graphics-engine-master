#include "Snow.h"
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
#include "Transform.h"
#include "SweepPath.h"
#include "Sweep.h"

namespace T3D {
	Snow::Snow(T3DApplication* app) :GameObject(app) {
		getTransform()->name = "Snow";

		std::vector<Vector3> snowProfile;
		


	    snowProfile.push_back(Vector3(0.38f, -0.08f, 0.0f));
		snowProfile.push_back(Vector3(0.4f, -0.05f, 0.0f));
		snowProfile.push_back(Vector3(0.4f, 0.15f, 0.0f));
		snowProfile.push_back(Vector3(0.38f, 0.17f, 0.0f));
		snowProfile.push_back(Vector3(0.32f, 0.08f, 0.0f));
		snowProfile.push_back(Vector3(0.1f, 0.07f, 0.0f));
		snowProfile.push_back(Vector3(0.07f, 0.18f, 0.0f));
		snowProfile.push_back(Vector3(-0.29f, 0.12f, 0.0f));
		snowProfile.push_back(Vector3(-0.3f, 0.13f, 0.0f));
		snowProfile.push_back(Vector3(-0.5f, 0.08f, 0.0f));
		snowProfile.push_back(Vector3(-0.5f, -0.05f, 0.0f));
		snowProfile.push_back(Vector3(-0.48f, -0.08f, 0.0f));

		SweepPath snowsp;

		Transform t;
		
		//set up 0,0
		t.setLocalPosition(Vector3(-0.01, 0, 0));
		t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
		t.setLocalScale(Vector3(0, 0, 1.0)); 
		snowsp.addTransform(t);

		//shoes outside
		t.setLocalScale(Vector3(1.0, 1.0, 1.0));
		snowsp.addTransform(t);

		//shoes inside
		t.setLocalPosition(Vector3(0.0002, 0, 0));
		t.setLocalScale(Vector3(0.9, 1.0, 1.0));
		snowsp.addTransform(t);



		




		/*t.setLocalScale(Vector3(0.9, 1, 1.0));
		snowsp.addTransform(t);
		snowsp.addTransform(t);*/


		

		snows = new GameObject(app);
		snows->setMesh(new Sweep(snowProfile, snowsp, false));
		snows->getTransform()->setParent(getTransform());
		snows->getTransform()->setLocalPosition(Vector3(0, 0.05, 0));
		snows->getTransform()->name = "snow";
		
	}

}
