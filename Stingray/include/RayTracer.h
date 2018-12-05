#pragma once

// cstdlib

// external libs

// program
#include "PCH.h"
#include "Logger.h"
#include "RenderQuad.h"
#include "Sphere.h"
#include "RayTracerSettings.h"
#include "Ray.h"
#include "Timer.h"
#include "Camera.h"
#include "Light.h"

namespace Batoidea
{
	/*! @class RayTracer
	*	@brief The primary ray tracer class which handles the rendering of a scene
	*
	*	This class is the primary renderer for a list of objects in a scene. The ray tracer holds a thread pool which it uses to distribute
	*	the rendering of the scene over various threads.
	*/
	class RayTracer
	{
	public:
		/** @brief RayTracer Constructor
		*	@param _settings The settings to use when rendering
		*
		*	Creates the raytracer and applies the settings
		*/
		RayTracer(const RayTracerSettings _settings);

		/** @brief Primary Render Method
		*	@param _renderables The vector of renderbales to render to the surface
		*	@param _lights The vector of lights to render with
		*	@param _surface The SDL surface to render the image to
		*	@return The rendered SDL surface
		*
		*	Takes renderables and a renderable surface and ray traces the scene from the camera
		*/
		SDL_Surface render(std::vector<Sphere> &_renderables, std::vector<Light> &_lights, SDL_Surface &_surface);

	protected:

		// TODO: Doxygen
		void renderQuadToPixels(const glm::vec2 _start, const glm::vec2 _finish);

		/** @brief Per pixel trace method
		*	@param _ray The ray to trace through the scene
		*	@return The colour (normalised) at the ray end
		*
		*	The per pixel render method which traces a ray through the scene.
		*/
		glm::vec3 trace(const Ray &_ray);
		/** @brief Lighting Calculation 
		*	@param _normal The normal of the point to calculate lighting on
		*	@param _position The position in space of which to calculate the lighting of
		*	@return The light intensity at the position
		*
		*	Computes the lighting for a given position and normal
		*/
		float computeLighting(glm::vec3 _normal, glm::vec3 _position);

		std::shared_ptr<Threads::ThreadPool>		m_threadPool;	/**< The thread pool used to render the scene */

		std::shared_ptr<Camera>						m_camera;		/**< The scene camera */

		RayTracerSettings							m_settings;		/**< The ray tracer settings */

		std::vector<Sphere>							m_objects;		/**< Vector of spheres in the scene */
		std::vector<Light>							m_lights;		/**< Vector of lights in the scene */

		std::mutex									m_pixelMutex;
		Uint32										*m_pixels;		/**< Pointer to the pixels of the surface */
	};
}
