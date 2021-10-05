#include "Pyramid.h"

using namespace T3D;

Pyramid::Pyramid(float size) 
{
	initArrays(16,	// num vertices
		4,		// num tris
		1);		// num quads

	

	int pos = 0;

	//front
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, 0, size, 0);
	setVertex(pos++, size, -size, -size);
	
	//back
	setVertex(pos++, size, -size, size);
	setVertex(pos++, 0, size, 0);
	setVertex(pos++, -size, -size, size);
	
	//left
	setVertex(pos++, -size, -size, size);
	setVertex(pos++, 0, size, 0);
	setVertex(pos++, -size, -size, -size);
	
	//right
	setVertex(pos++, size, -size, -size);
	setVertex(pos++, 0, size, 0);
	setVertex(pos++, size, -size, size);
	
	//bottom
	setVertex(pos++, -size, -size, -size);
	setVertex(pos++, size, -size, -size);
	setVertex(pos++, size, -size, size);
	setVertex(pos++, -size, -size, size);
	

	// Build quads
	pos = 0;
	//front
	setTriFace(pos++, 2, 1, 0);
	//back
	setTriFace(pos++, 5, 4, 3);
	//left
	setTriFace(pos++, 8, 7, 6);
	//right
	setTriFace(pos++, 11, 10, 9);
	//bottom
	setQuadFace(pos++, 15, 14, 13, 12);
	

	// Check vertex and index arrays
	checkArrays();

	// Calculate normals
	calcNormals();

	// Setup other arrays		
	pos = 0;
	//front
	for (int i = 0; i < 4; i++) {
		colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
	}
	//back
	for (int i = 0; i < 4; i++) {
		colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1;
	}
	//left
	for (int i = 0; i < 4; i++) {
		colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
	}
	//right
	for (int i = 0; i < 4; i++) {
		colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 0; colors[pos++] = 1;
	}
	//bottom
	for (int i = 0; i < 4; i++) {
		colors[pos++] = 0; colors[pos++] = 0; colors[pos++] = 1; colors[pos++] = 1;
	}
	

	//uvs
	pos = 0;
	for (int f = 0; f < 6; f++) {
		uvs[pos++] = 0; uvs[pos++] = 0;
		uvs[pos++] = 0; uvs[pos++] = 1;
		uvs[pos++] = 1; uvs[pos++] = 1;
		uvs[pos++] = 1; uvs[pos++] = 0;
	}
}



