#pragma once

// cstdlib

// external libs
#include "GLM/common.hpp"

// program

namespace Batoidea
{
	struct Ray
	{
		Ray(glm::vec3 _origin, glm::vec3 _direction) 
		{
			origin = _origin; 
			direction = _direction;
		}

		glm::vec3 origin;
		glm::vec3 direction;
		inline glm::vec3 point_at(const float _t) { return origin + _t * direction; }
	};
}