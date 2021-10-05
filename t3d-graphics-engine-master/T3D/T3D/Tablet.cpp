#include "Tablet.h"
#include "Math.h"

using namespace T3D;

Tablet::Tablet(Vector3 size, float bezel_width, float corner_radius, float screen_depression, int density) {
	/*int numVerts = 24*5 + 3*density*2*4 + 4*density*4;
	int numTris = 2 * density*4;
	int numQuads = 30 + 4*density;*/
	int numVerts = 24+24+24+24+24+26+26+26+200;
	int numTris = 12 + 12 +12 + 12;
	int numQuads = 6+6+6+6+6+6 +6 +6 +6;
	initArrays(numVerts, numTris, numQuads);

	int pos = 0;
	float hTheta = Math::PI / 2;

	
	float dTheta = hTheta / density;
    float theta = 0;


	//front bottom
	setVertex(pos++, -(size.x-2*bezel_width)/2, -(size.y-screen_depression)/2, -(size.z-2*bezel_width)/2);
	setVertex(pos++, (size.x-2*bezel_width)/2, -(size.y-screen_depression)/2, -(size.z-2*bezel_width)/2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	//back bottom
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, (size.z - 2 * bezel_width)/2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	//left bottom
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	//right bottom
	setVertex(pos++, (size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	//bottom bottom
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, -(size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	//top bottom
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);
	setVertex(pos++, -(size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, (size.z - 2 * bezel_width) /2);
	setVertex(pos++, (size.x - 2 * bezel_width) /2, (size.y - screen_depression) /2, -(size.z - 2 * bezel_width) /2);



	////front front
	setVertex(pos++, -(size.x - 2*corner_radius) / 2, -(size.y - screen_depression) / 2, -size.z / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, -size.z / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, -size.z / 2);
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, -size.z / 2);
	////back front
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	////left front
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, -size.z / 2);
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, -size.z / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	////right front
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, -size.z / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, -size.z / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	////bottom front
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, -size.z / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, -size.z / 2);
	////top front
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, -size.z / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, -size.z / 2);




	////front left
	setVertex(pos++, -size.x / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -size.x / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * corner_radius) / 2);
	////back left
	setVertex(pos++, -size.x / 2, -(size.y - screen_depression) / 2, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -size.x / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * corner_radius) / 2);
	////left left
	setVertex(pos++, -size.x / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -size.x / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -size.x / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -size.x / 2, -(size.y - screen_depression) / 2, (size.z - 2 * corner_radius) / 2);
	////right left
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	////bottom left
	setVertex(pos++, -size.x / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -size.x / 2, -(size.y - screen_depression) / 2, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	////top left
	setVertex(pos++, -size.x / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -size.x / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);


	////front back
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	////back back
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, size.z / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, size.z / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, size.z / 2);
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, size.z / 2);
	////left back
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, size.z  / 2);
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2 , size.z / 2);
	////right back
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, size.z / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, size.z / 2);
	////bottom back
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, size.z / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, -(size.y - screen_depression) / 2, size.z / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	////top back
	setVertex(pos++, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, -(size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, size.z / 2);
	setVertex(pos++, (size.x - 2 * corner_radius) / 2, (size.y - screen_depression) / 2 + screen_depression, size.z / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);

	////front right
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, size.x / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, size.x / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	////back right
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, size.x / 2, -(size.y - screen_depression) / 2, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, size.x / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	////left right
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	////right right
	setVertex(pos++, size.x / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, size.x / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * corner_radius) / 2);
	setVertex(pos++, size.x / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, size.x / 2, -(size.y - screen_depression) / 2, (size.z - 2 * corner_radius) / 2);
	////bottom right
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, size.x / 2, -(size.y - screen_depression) / 2, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, size.x / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * corner_radius) / 2);
	////top right
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);
	setVertex(pos++, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);
	setVertex(pos++, size.x / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * corner_radius) / 2);
	setVertex(pos++, size.x / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * corner_radius) / 2);





	//top vertex Right-Bottom

	

	for (int pos = 120; pos-120 <= density; pos++) {
		theta = (pos-120) * dTheta;
		//float R = cos(Math::PI / 4) * corner_radius / sin(hTheta / 2);
		float x = size.x / 2- corner_radius + cos(theta) * corner_radius;
		float z = size.z / 2 - corner_radius + sin(theta) * corner_radius;


		// top vertex
		setVertex(pos, x, (size.y - screen_depression) / 2 + screen_depression, z);
		setVertex(density+pos+1, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);

	
	}
	


	for (int pos = 134; pos - 134 <= density; pos++) {
		theta = (pos - 134) * dTheta;
		//float R = cos(Math::PI / 4) * corner_radius/sin(hTheta / 2) ;
		float x = size.x / 2 - corner_radius + cos(theta) * corner_radius;
		float z = size.z / 2 - corner_radius + sin(theta) * corner_radius;
		

		// bottom vertex
		setVertex(pos, x, -(size.y - screen_depression) / 2, z);
		setVertex(density + pos+1, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2 , (size.z - 2 * bezel_width) / 2);

	}

	
	



	//	//top vertex Right-top
	for (int pos = 148; pos - 148 <= density; pos++) {
		theta = (pos - 148) * dTheta;
		float x = size.x / 2 - corner_radius + cos(theta) * corner_radius;
		float z = size.z / 2 - corner_radius + sin(theta) * corner_radius;


		// top vertex
		setVertex(pos, x, (size.y - screen_depression) / 2 + screen_depression, -z);
		setVertex(density + pos + 1, (size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);


	}


	////bottom vertex Right-top

	for (int pos = 162; pos - 162 <= density; pos++) {
		theta = (pos - 162) * dTheta;
		float x = size.x / 2 - corner_radius + cos(theta) * corner_radius;
		float z = size.z / 2 - corner_radius + sin(theta) * corner_radius;


		// bottom vertex
		setVertex(pos, x, -(size.y - screen_depression) / 2, -z);
		setVertex(density + pos + 1, (size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);

	}

	//	//top vertex left-top
	for (int pos = 176; pos - 176 <= density; pos++) {
		theta = (pos - 176) * dTheta;
		float x = size.x / 2 - corner_radius + cos(theta) * corner_radius;
		float z = size.z / 2 - corner_radius + sin(theta) * corner_radius;


		// top vertex
		setVertex(pos, -x, (size.y - screen_depression) / 2 + screen_depression, -z);
		setVertex(density + pos + 1, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, -(size.z - 2 * bezel_width) / 2);


	}
	////bottom vertex left-top

	for (int pos = 190; pos - 190 <= density; pos++) {
		theta = (pos - 190) * dTheta;
		float x = size.x / 2 - corner_radius + cos(theta) * corner_radius;
		float z = size.z / 2 - corner_radius + sin(theta) * corner_radius;


		// bottom vertex
		setVertex(pos, -x, -(size.y - screen_depression) / 2, -z);
		setVertex(density + pos + 1, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, -(size.z - 2 * bezel_width) / 2);

	}

	//	//top vertex left-bottom
	for (int pos = 204; pos - 204 <= density; pos++) {
		theta = (pos - 204) * dTheta;
		float x = size.x / 2 - corner_radius + cos(theta) * corner_radius;
		float z = size.z / 2 - corner_radius + sin(theta) * corner_radius;


		// top vertex
		setVertex(pos, -x, (size.y - screen_depression) / 2 + screen_depression, z);
		setVertex(density + pos + 1, -(size.x - 2 * bezel_width) / 2, (size.y - screen_depression) / 2 + screen_depression, (size.z - 2 * bezel_width) / 2);


	}
	////bottom vertex left-bottom

	for (int pos = 218; pos - 218 <= density; pos++) {
		theta = (pos - 218) * dTheta;
		float x = size.x / 2 - corner_radius + cos(theta) * corner_radius;
		float z = size.z / 2 - corner_radius + sin(theta) * corner_radius;


		// bottom vertex
		setVertex(pos, -x, -(size.y - screen_depression) / 2, z);
		setVertex(density + pos + 1, -(size.x - 2 * bezel_width) / 2, -(size.y - screen_depression) / 2, (size.z - 2 * bezel_width) / 2);

	}
	

	pos = 0;
	//front
	setQuadFace(pos++, 3, 2, 1, 0);
	//back
	setQuadFace(pos++, 4, 5, 6, 7);
	//left
	setQuadFace(pos++, 11, 10, 9, 8);
	//right
	setQuadFace(pos++, 12, 13, 14, 15);
	//bottom
	setQuadFace(pos++, 19, 18, 17, 16);
	//top
	setQuadFace(pos++, 20, 21, 22, 23);

	//front front
	setQuadFace(pos++, 27, 26, 25, 24);
	//back front
	setQuadFace(pos++, 28, 29, 30, 31);
	//left front
	setQuadFace(pos++, 35, 34, 33, 32);
	//right front
	setQuadFace(pos++, 36, 37, 38, 39);
	//bottom front
	setQuadFace(pos++, 43, 42, 41, 40);
	//top front
	setQuadFace(pos++, 44, 45, 46, 47);


	//front left
	setQuadFace(pos++, 51, 50, 49, 48);
	//back left
	setQuadFace(pos++, 52, 53, 54, 55);
	//left left
	setQuadFace(pos++, 59, 58, 57, 56);
	//right left
	setQuadFace(pos++, 60, 61, 62, 63);
	//bottom left
	setQuadFace(pos++, 67, 66, 65, 64);
	//top left
	setQuadFace(pos++, 68, 69, 70, 71);

	//front back
	setQuadFace(pos++, 75, 74, 73, 72);
	//back back
	setQuadFace(pos++, 76, 77, 78, 79);
	//left back
	setQuadFace(pos++, 83, 82, 81, 80);
	//right back
	setQuadFace(pos++, 84, 85, 86, 87);
	//bottom back
	setQuadFace(pos++, 91, 90, 89, 88);
	//top back
	setQuadFace(pos++, 92, 93, 94, 95);

	//front right
	setQuadFace(pos++, 99, 98, 97, 96);
	//back right
	setQuadFace(pos++, 100, 101, 102, 103);
	//left right
	setQuadFace(pos++, 107, 106, 105, 104);
	//right right
	setQuadFace(pos++, 108, 109, 110, 111);
	//bottom right
	setQuadFace(pos++, 115, 114, 113, 112);
	//top right
	setQuadFace(pos++, 116, 117, 118, 119);

	for (int i = 120; i < 126; i++) {
		setQuadFace(pos++, i + 15, i + 14, i, i + 1);
	}


	for (int i = 148; i < 154; i++) {
		setQuadFace(pos++, i +1, i , i+14, i + 15);
	}
	for (int i = 176; i < 182; i++) {
		setQuadFace(pos++, i + 15, i + 14, i , i + 1);
	}

	for (int i = 204; i < 210; i++) {
		setQuadFace(pos++, i + 1, i , i+14, i + 15);
	}


	pos = 0;


	for (int i = 120; i < 126; i++) {
		setTriFace(pos++, i, i+7, i+1);
	}

	
	for (int i = 134; i < 140; i++) {
		setTriFace(pos++, i+1, i + 7, i );
	}



	for (int i = 148; i < 154; i++) {
		setTriFace(pos++, i +1, i + 7, i );
	}


	for (int i = 162; i < 168; i++) {
		setTriFace(pos++, i , i + 7, i+1);
	}
	
	for (int i = 176; i < 182; i++) {
		setTriFace(pos++, i , i + 7, i +1);
	}


	for (int i = 190; i < 196; i++) {
		setTriFace(pos++, i +1, i + 7, i );
	}



	for (int i = 204; i < 210; i++) {
		setTriFace(pos++, i+1, i + 7, i );
	}


	for (int i = 218; i < 224; i++) {
		setTriFace(pos++, i , i + 7, i+1);
	}





	checkArrays();

	calcNormals();
	
	
	}


