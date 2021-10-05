#include "Assignment1Test.h"
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
#include "Snow.h"
#include "Tablet.h"
#include "TabletComposite.h"
#include "CompositeLeft.h"



using namespace T3D;

bool Assignment1Test::init() {
	WinGLApplication::init();
	// more code to come...
	//light
	GameObject* lightObj = new GameObject(this);
	Light* light = new Light(Light::Type::DIRECTIONAL);

	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	lightObj->getTransform()->
		setLocalRotation(
			Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
	lightObj->getTransform()->setParent(root);

	//camera sweep
	GameObject* camObj = new GameObject(this);
	renderer->camera = new Camera(0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());


	Material* grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0.8, 0.8, 0.9, 1);
	
	Material* green = renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(0.3, 0.7, 0.6, 1);


	/*Snow* snow = new Snow(this);
	snow->getTransform()->setParent(root);
	snow->snows->setMaterial(white);
	*/


	GameObject* tablet = new GameObject(this);
	tablet->setMesh(new Tablet(Vector3(0.8, 0.05, 0.45), 0.08, 0.03, 0.01, 6));
	tablet->setMaterial(grey);
	tablet->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	tablet->getTransform()->setParent(root);
	tablet->getTransform()->name = "Tablet";

	//Task5
	/*TabletComposite* tabletComposite = new TabletComposite(this);
	tabletComposite->setMaterial(grey);
	tabletComposite->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	tabletComposite->getTransform()->setParent(root);

	tabletComposite->shelfLeft->setMaterial(green);
	tabletComposite->shelfRight->setMaterial(green);
	tabletComposite->spring1->setMaterial(green);
	tabletComposite->spring2->setMaterial(green);
	tabletComposite->backShelf->setMaterial(green);
	tabletComposite->link1->setMaterial(green);
	tabletComposite->arm1->setMaterial(green);
	tabletComposite->link2->setMaterial(green);
	tabletComposite->arm2->setMaterial(green);
	tabletComposite->base->setMaterial(green);

	
	tabletComposite->springJoint->getTransform();
	tabletComposite->backShelfJoint->getTransform();
	tabletComposite->armJoint1->getTransform()-> setLocalRotation(Quaternion(Vector3(0, -Math::PI / 4, 0)));
	tabletComposite->armJoint2->getTransform();
	tabletComposite->armJoint3->getTransform()->setLocalRotation(Quaternion(Vector3(0, -Math::PI / 4, 0)));
	tabletComposite->baseJoint->getTransform();*/
	return true;
}
