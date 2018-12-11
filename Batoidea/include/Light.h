#pragma once

// cstdlib

// external libs

// program
#include "PCH.h"
#include "Logger.h"

namespace Batoidea
{
	enum LightType { LIGHT_POINT, LIGHT_DIRECTIONAL };

	struct Light
	{
	public:
		Light() { }
		Light(glm::vec3 _pos, float _int)
		{
			position = _pos;
			intensity = _int;
		}

		LightType type = LIGHT_POINT;

		glm::vec3 position;
		glm::vec3 direction;
		float intensity = 1.0f;
	};
}