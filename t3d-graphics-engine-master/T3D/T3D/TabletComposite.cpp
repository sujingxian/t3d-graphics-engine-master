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
#include "Tablet.h"
#include "TabletComposite.h"
#include "CompositeLeft.h"
#include "CompositeRight.h"

namespace T3D {
	TabletComposite::TabletComposite(T3DApplication* app) :GameObject(app) {
		setMesh(new Tablet(Vector3(0.8, 0.05, 0.45), 0.08, 0.03, 0.01, 6));
		getTransform()->name = "tabletComposite";

	

		shelfLeft = new GameObject(app);
		shelfLeft->setMesh(new CompositeLeft(0.15, 0.03, 0.1));
		shelfLeft->getTransform()->setParent(getTransform()); // attaching this piece to the Lamp object's transform
		shelfLeft->getTransform()->setLocalPosition(Vector3(0.2, -0.05, -0.225));
		shelfLeft->getTransform()->name = "shelfLeft";

	

		shelfRight = new GameObject(app);
		shelfRight->setMesh(new CompositeLeft(0.15, 0.03, 0.1));
		shelfRight->getTransform()->setParent(getTransform()); // attaching this piece to the Lamp object's transform
		shelfRight->getTransform()->setLocalPosition(Vector3(0.2, -0.05, 0.255));
		shelfRight->getTransform()->name = "shelfRight";


		spring1 = new GameObject(app);
		spring1->setMesh(new Cylinder(0.005, 0.24, 20));
		spring1->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI/2, 0, 0)));
		spring1->getTransform()->setLocalPosition(Vector3(0.23, -0.045, -0.018));
		spring1->getTransform()->setParent(getTransform());
		//spring1->getTransform()->setParent(leftJoint->getTransform()); // attaching this piece to the Lamp object's transform
		spring1->getTransform()->name = "spring1";

		spring2 = new GameObject(app);
		spring2->setMesh(new Cylinder(0.005, 0.24, 20));
		spring2->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		spring2->getTransform()->setLocalPosition(Vector3(0.32, -0.045, -0.018));
		//spring2->getTransform()->setParent(rightJoint ->getTransform()); // attaching this piece to the Lamp object's transform
		spring2->getTransform()->setParent(getTransform());
		spring2->getTransform()->name = "spring2";


		springJoint = new GameObject(app);
		springJoint->getTransform()->setParent(spring1->getTransform());
		springJoint->getTransform()->name = "SpringJoint";

		backShelf = new GameObject(app);
		backShelf->setMesh(new CompositeLeft(0.13, 0.01, 0.2));
		backShelf->getTransform()->setParent(springJoint ->getTransform()); // attaching this piece to the Lamp object's transform
		backShelf->getTransform()->setLocalPosition(Vector3(-0.002,-0.1, 0.002));
		backShelf->getTransform()->name = "shelfRight";



		backShelfJoint = new GameObject(app);
		backShelfJoint->getTransform()->setParent(backShelf->getTransform());
		backShelfJoint->getTransform()->setLocalPosition(Vector3(0.32, -0.045, -0.018));
		backShelfJoint->getTransform()->name = "backShelfJoint";

		link1 = new GameObject(app); // note the use of 'app' not 'this' - you should understand why
		link1->setMesh(new Cylinder(.02, .04, 20));
		link1->getTransform()->setParent(backShelfJoint -> getTransform()); // attaching this piece to the Lamp object's transform
		link1->getTransform()->setLocalPosition(Vector3(-0.25, 0.15, 0.035));
		link1->getTransform()->name = "Base";

		armJoint1 = new GameObject(app);
		armJoint1->getTransform()->setParent(link1->getTransform());
		armJoint1->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		armJoint1->getTransform()->name = "armJoint1";

		arm1 = new GameObject(app);
		arm1->setMesh(new Cylinder(0.015, 0.4,20));
		arm1->getTransform()->setLocalPosition(Vector3(0, 0, 0.39));
		arm1->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		arm1->getTransform()->setParent(armJoint1->getTransform());
		arm1->getTransform()->name = "Arm1";

		armJoint2 = new GameObject(app);
		armJoint2->getTransform()->setParent(arm1->getTransform());
		armJoint2->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		armJoint2->getTransform()->name = "armJoint2";



		link2 = new GameObject(app); 
		link2->setMesh(new Cylinder(.02, .04, 20));
		link2->getTransform()->setParent(armJoint2->getTransform()); 
		link2->getTransform()->setLocalPosition(Vector3(0, 0.4, 0));
		link2->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		link2->getTransform()->name = "link2";

		armJoint3 = new GameObject(app);
		armJoint3->getTransform()->setParent(link2->getTransform());
		armJoint3->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		armJoint3->getTransform()->name = "armJoint3";


		arm2 = new GameObject(app);
		arm2->setMesh(new Cylinder(0.015, 0.4, 20));
		arm2->getTransform()->setLocalPosition(Vector3(0, 0, -0.4));
		arm2->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 2, 0, 0)));
		arm2->getTransform()->setParent(armJoint3->getTransform());
		arm2->getTransform()->name = "Arm2";
	
		baseJoint = new GameObject(app);
		baseJoint->getTransform()->setParent(arm2->getTransform());
		baseJoint->getTransform()->setLocalPosition(Vector3(0, 0, 0));
		baseJoint->getTransform()->name = "armJoint3";
		
		std::vector<Vector3> baseProfile;
		baseProfile.push_back(Vector3(0.0f, 0.0f, 0.0f));
		baseProfile.push_back(Vector3(0.0f, 0.2f, 0.0f));
		
		baseProfile.push_back(Vector3(0.03f, 0.2f, 0.0f));
		baseProfile.push_back(Vector3(0.03f, 0.17f, 0.0f));
		baseProfile.push_back(Vector3(0.1f, 0.008f, 0.0f));
		baseProfile.push_back(Vector3(0.4f, 0.0f, 0.0f));
		SweepPath basesp;
		Transform t;

		t.setLocalScale(Vector3(1, 1, 1));
		basesp.addTransform(t);

		t.setLocalRotation(Quaternion(Vector3(0, Math::PI / 2, 0)));
		basesp.addTransform(t);

		t.setLocalRotation(Quaternion(Vector3(0, Math::PI , 0)));
		basesp.addTransform(t);

		t.setLocalRotation(Quaternion(Vector3(0, Math::PI*1.5, 0)));
		basesp.addTransform(t);

		t.setLocalRotation(Quaternion(Vector3(0, Math::PI * 2, 0)));
		basesp.addTransform(t);

		base = new GameObject(app);
		base->setMesh(new Sweep(baseProfile, basesp, true));
		base->getTransform()->setLocalPosition(Vector3(0, -0.4, 0));
		base->getTransform()->setParent(baseJoint->getTransform());
		base->getTransform()->name = "base";


	
	}
}