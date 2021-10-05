#include "CompositeRight.h"
namespace T3D {

	CompositeRight::CompositeRight(float length, float width, float height) {
		initArrays(4 * 6,	// num vertices
			0,		// num tris
			6);

		int pos = 0;
		//front
		setVertex(pos++, 0, 0, -width);
		setVertex(pos++, length, 0, -width);
		setVertex(pos++, length, height, -width);
		setVertex(pos++, 0, height, -width);
		//back
		setVertex(pos++, 0, 0, 0);
		setVertex(pos++, length, 0, 0);
		setVertex(pos++, length, height, 0);
		setVertex(pos++, 0, height, 0);
		//left
		setVertex(pos++, 0, 0, -width);
		setVertex(pos++, 0, height, -width);
		setVertex(pos++, 0, height, 0);
		setVertex(pos++, 0, 0, 0);
		//right
		setVertex(pos++, length, 0, -width);
		setVertex(pos++, length, height, -width);
		setVertex(pos++, length, height, 0);
		setVertex(pos++, length, 0, 0);
		//bottom
		setVertex(pos++, 0, 0, -width);
		setVertex(pos++, 0, 0, 0);
		setVertex(pos++, length, 0, 0);
		setVertex(pos++, length, 0, -width);
		//top
		setVertex(pos++, 0, height, -width);
		setVertex(pos++, 0, height, 0);
		setVertex(pos++, length, height, 0);
		setVertex(pos++, length, height, -width);

		// Build quads
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

		// Check vertex and index arrays
		checkArrays();

		// Calculate normals
		calcNormals();
	}



}