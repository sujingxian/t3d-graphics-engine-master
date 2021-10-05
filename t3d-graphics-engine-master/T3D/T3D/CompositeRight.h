#pragma once
#include "Mesh.h"

namespace T3D
{
	//! \brief A simple parametric Cube Mesh.
	class CompositeRight :
		public Mesh
	{
	public:
		//! \brief Create Cube with volume = `size^3`.
		CompositeRight(float length, float width, float height);

		//! \brief Destroy Cube.
		/*! \note Mesh superclass deletes arrays if they have been created, no need to do anything here
		*/
		virtual ~CompositeRight(void) = default;
	};
}

