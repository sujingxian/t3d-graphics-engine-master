#include "Cylinder.h"
#include "Math.h"

using namespace T3D;

Cylinder::Cylinder(float r, float h, int d) {

	int numVerts = 10*d;
	int numTris = 2*d;
	int numQuads = d;
	initArrays(numVerts, numTris, numQuads);

	int pos = 0;


	float dTheta = Math::TWO_PI / d; 
	float theta = 0;
	
	for (int i = 0; i < d; i++) {
		theta = i * dTheta;
		float x = r * cos(theta);
		float z = r* sin(theta);


		// top vertex
		setVertex(i, x, h, z);
		setVertex(2 * d + i, 0, h, 0);
		
		// bottom vertex
		setVertex(d + i, x, -h, z);
		setVertex(3*d + i, 0, -h, 0);
		
	}

	for (int i = 0; i < d; i++) {
		setQuadFace(i,
			i,
			(i+1)%d,
			d+(i+1)%d,
			d+i
			);
	}

	for (int i = 0; i < 2*d; i++) {
		if (i < d) {
			setTriFace(i,
				i,
				2 * d + i,
				(i + 1) % d

			);

		}
		else {
			setTriFace(i,
				d+(i+1)%d,
				3 * d + (i-d),
				d+(i-d)

			);

		}

		
	}

	// COLORS
	for (int i = 0; i < numVerts; i++) {
		setColor(i, 1, 1, 1, 1);
	}


	checkArrays();

	// NORMALS
	calcNormals();

	//initArrays(36,	// num vertices
	//	0,		// num tris
	//	6);		// num quads

	//int pos = 0;

	////front
	//setVertex(pos++, size, -size, -size);
	//setVertex(pos++, size, size, -size);
	//setVertex(pos++, -size, size, -size);
	//setVertex(pos++, -size, -size, -size);
	////back
	//setVertex(pos++, size, -size, size);
	//setVertex(pos++, size, size, size);
	//setVertex(pos++, -size, size, size);
	//setVertex(pos++, -size, -size, size);
	////left front
	//setVertex(pos++, -size, -size, -size);
	//setVertex(pos++, -size, size, -size);
	//setVertex(pos++, -size, size, 0);
	//setVertex(pos++, -size, -size, 0);
	////right front
	//setVertex(pos++, size, -size, 0);
	//setVertex(pos++, size, size, 0);
	//setVertex(pos++, size, size, -size);
	//setVertex(pos++, size, -size, -size);
	////left back
	//setVertex(pos++, -size, -size, size);
	//setVertex(pos++, -size, size, size);
	//setVertex(pos++, -size, size, 0);
	//setVertex(pos++, -size, -size, 0);
	////right back
	//setVertex(pos++, size, -size, 0);
	//setVertex(pos++, size, size, 0);
	//setVertex(pos++, size, size, size);
	//setVertex(pos++, size, -size, size);

	////top
	//setVertex(pos++, size, size, size);
	//setVertex(pos++, size, size, 0);
	//setVertex(pos++, size, size, -size);
	//setVertex(pos++, -size, size, -size);
	//setVertex(pos++, -size, size, 0);
	//setVertex(pos++, -size, size, size);
	////bottom
	//setVertex(pos++, size, -size, size);
	//setVertex(pos++, size, -size, 0);
	//setVertex(pos++, size, -size, -size);
	//setVertex(pos++, -size, -size, -size);
	//setVertex(pos++, -size, -size, 0);
	//setVertex(pos++, -size, -size, size);

	//// Build quads
	//pos = 0;
	////front
}
