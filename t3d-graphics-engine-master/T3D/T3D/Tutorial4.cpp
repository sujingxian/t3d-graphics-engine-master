
#include "Tutorial4.h"
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

using namespace T3D;



bool Tutorial4::init() {
	WinGLApplication::init();
	// more code to come...
	//light
	GameObject* lightObj = new GameObject(this);
	Light* light = new Light(Light::Type::DIRECTIONAL);
	renderer->ambient[0] = 0.3;
	renderer->ambient[1] = 0.3;
	renderer->ambient[2] = 0.3;
	light->setAmbient(1, 1, 1);
	light->setDiffuse(1, 1, 1);
	light->setSpecular(1, 1, 1);
	lightObj->setLight(light);
	lightObj->getTransform()->
		setLocalRotation(
			Vector3(-45 * Math::DEG2RAD, 70 * Math::DEG2RAD, 0));
	lightObj->getTransform()->setParent(root);
	
	//camera
	/*GameObject* camObj = new GameObject(this);
	renderer->camera = new Camera(0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0, 20));
	camObj->getTransform()->setLocalRotation(Vector3(0, 0, 0));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());*/
	//camera sweep
	GameObject* camObj = new GameObject(this);
	renderer->camera = new Camera(0.1, 500.0, 45.0, 1.6);
	camObj->getTransform()->setLocalPosition(Vector3(0, 0.5, 3));
	camObj->setCamera(renderer->camera);
	camObj->getTransform()->setParent(root);
	camObj->addComponent(new KeyboardController());

	Material* grey = renderer->createMaterial(Renderer::PR_OPAQUE);
	grey->setDiffuse(0.8, 0.8, 0.9, 1);
	Lamp* lamp = new Lamp(this);
	lamp->setMaterial(grey);
	lamp->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	lamp->getTransform()->setParent(root);

	lamp->base->setMaterial(grey);

	lamp->arm1->setMaterial(grey);

	lamp->arm2->setMaterial(grey);

	lamp->baseJoint->getTransform()->setLocalRotation(Quaternion(Vector3(-Math::PI / 10, Math::PI / 4, 0)));
	lamp->elbowJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));
	lamp->shadeJoint->getTransform()->setLocalRotation(Quaternion(Vector3(Math::PI / 4, 0, 0)));

	lamp->lampShade->setMaterial(grey);

	//material
	/*Material* green =
		renderer->createMaterial(Renderer::PR_OPAQUE);
	green->setDiffuse(255, 255, 0, 255);*/

	//cube mesh
	/*GameObject* cube = new GameObject(this);
	cube->setMesh(new Cube(1));
	cube->setMaterial(grey);
	cube->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	cube->getTransform()->setParent(root);
	cube->getTransform()->name = "Cube";*/

	//Pyramid mesh
	/*GameObject* pyramid = new GameObject(this);
	pyramid->setMesh(new Pyramid(1));
	pyramid->setMaterial(green);
	pyramid->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	pyramid->getTransform()->setParent(root);
	pyramid->getTransform()->name = "Pyramid";
*/
	/*GameObject* cylinder = new GameObject(this);
	cylinder->setMesh(new Cylinder(1));
	cylinder->setMaterial(green);
	cylinder->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	cylinder->getTransform()->setParent(root);
	cylinder->getTransform()->name = "Cylinder";*/

	/*GameObject* sphere = new GameObject(this);
	sphere->setMesh(new Sphere(1));
	sphere->setMaterial(green);
	sphere->getTransform()->setLocalPosition(Vector3(0, 0, 0));
	sphere->getTransform()->setParent(root);
	sphere->getTransform()->name = "Sphere";*/




	return true;
}
