// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// ShaderTest.cpp
//
// A simple application used for testing lighting shaders

#include "ShaderTest.h"
#include "Camera.h"
#include "Sphere.h"
#include "GLShader.h"
#include "GameObject.h"
#include "Material.h"
#include "Renderer.h"
#include "Transform.h"

namespace T3D{

	ShaderTest::ShaderTest(void)
	{
	}


	ShaderTest::~ShaderTest(void)	
	{
	}

	bool ShaderTest::init(){
		WinGLApplication::init();
		root->name = "Root";
		//test scene

		Material *shaderGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
		shaderGreen->setDiffuse(0,1,0,1);
		GLShader *specShader = new GLShader("Resources/vspecular.shader","Resources/frag.shader");
		specShader->compileShader();
		shaderGreen->setShader(specShader);

		Material *fixedGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
		fixedGreen->setDiffuse(0,0.6,0,1);
		fixedGreen->setShininess(20);

		Material* gouraudGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
		gouraudGreen->setDiffuse(0, 0.6, 0, 1);
		gouraudGreen->setShininess(20);
		GLShader* gouraudShader = new GLShader("Resources/vspecular.shader", "Resources/frag.shader");
		gouraudShader->compileShader();
		gouraudGreen->setShader(gouraudShader);

		Material* phongGreen = renderer->createMaterial(Renderer::PR_OPAQUE);
		phongGreen->setDiffuse(0, 0.9, 0.6, 1);
		phongGreen->setShininess(40);
		GLShader* phongShader = new GLShader("Resources/phongVert.shader", "Resources/phongFrag.shader");
		phongShader->compileShader();
		phongGreen->setShader(phongShader);

		GameObject *camObj = new GameObject(this);
		float near   = 0.1f;
		float far    = 500.0f;
		float fovy   = 45.0f;
		float aspect = 1.6f;

		renderer->camera = new Camera(near, far, fovy, aspect);
		camObj->getTransform()->setLocalPosition(Vector3(0,0,5));
		camObj->getTransform()->setLocalRotation(Vector3(0,0,0));
		camObj->setCamera(renderer->camera);
		camObj->getTransform()->setParent(root);
		
		GameObject *lightObj = new GameObject(this);
		Light *light = new Light(Light::Type::DIRECTIONAL); 
		light->setAmbient(1,1,1);
		light->setDiffuse(1,1,1);
		light->setSpecular(1,1,1);
		lightObj->setLight(light);
		lightObj->getTransform()->setLocalRotation(Vector3(-45*Math::DEG2RAD,70*Math::DEG2RAD,0));
		lightObj->getTransform()->setLocalPosition(Vector3(0,3,0));
		lightObj->getTransform()->setParent(root);

		GameObject *sphere1 = new GameObject(this);
		sphere1->setMesh(new Sphere(1.0,32));
		sphere1->setMaterial(gouraudGreen);
		sphere1->getTransform()->setLocalPosition(Vector3(-1.25,1,0));		
		sphere1->getTransform()->setParent(root);
		sphere1->getTransform()->name = "Sphere 1";
		
		GameObject *sphere2 = new GameObject(this);
		sphere2->setMesh(new Sphere(1.0,32));
		sphere2->setMaterial(fixedGreen);
		sphere2->getTransform()->setLocalPosition(Vector3(1.25,1,0));		
		sphere2->getTransform()->setParent(root);
		sphere2->getTransform()->name = "Sphere 2";

		GameObject* sphere3 = new GameObject(this);
		sphere3->setMesh(new Sphere(1.0, 32));
		sphere3->setMaterial(phongGreen);
		sphere3->getTransform()->setLocalPosition(Vector3(1.25, -1, 0));
		sphere3->getTransform()->setParent(root);
		sphere3->getTransform()->name = "Sphere 3";


		return true;
	}

}
