#pragma once
#include "Mesh.h"

namespace T3D
{
	//! \brief A simple parametric Cube Mesh.
	class CompositeLeft :
		public Mesh
	{
	public:
		//! \brief Create Cube with volume = `size^3`.
		CompositeLeft(float length, float width, float height);

		//! \brief Destroy Cube.
		/*! \note Mesh superclass deletes arrays if they have been created, no need to do anything here
		*/
		virtual ~CompositeLeft(void) = default;
	};
}

