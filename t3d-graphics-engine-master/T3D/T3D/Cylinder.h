#pragma once

#include "Mesh.h"
#include "Math.h"
namespace T3D
{
	class Cylinder :
		public Mesh
	{
	public:
		//! \brief Create Cube with volume = `size^3`.
		Cylinder(float radius, float height , int density );

		//! \brief Destroy Cube.
		/*! \note Mesh superclass deletes arrays if they have been created, no need to do anything here
		*/
		virtual ~Cylinder(void) = default;
	};
}
