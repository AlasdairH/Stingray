#pragma once

// cstdlib
#include <iostream>
#include <string>
#include <memory>

// external libs
#include "GL\glew.h"
#include "SDL\SDL.h"

// program
#include "Logger.h"

namespace Batoidea
{
	/*! @class Window
	*	@brief An abstraction of the SDL Window class
	*
	*	This class uses the SDL Window class to create a window in the constructor. By use of default parameters,
	*	a default window can be created by passing no arguments to the constructor or various settings can be applied.
	*/
	class Window
	{
	public:
		/** @brief The Window Constructor
		*	@param _title The Window Title that will be displayed in the OS
		*	@param _width The default width of the window
		*	@param _height The default height of the window
		*
		*	The constructor takes default arguments for a standard window but title, width and height can be set
		*	by overwriting these provided values.
		*	The constructor creates an SDL Window, SDL Renderer and an accompanying GL Context.
		*/
		Window(const std::string _title = "Default", const int _width = 1280, const int _height = 720);

		/** @brief The Window Destructor
		*
		*	This Destructor simply destorys the SDL Window and Renderer.
		*/
		~Window();

		/** @brief Window Surface Render
		*
		*	Renders the surface to the screen
		*/
		void render();

		/** @brief Sets a new window size
		*	@param _width The new width of the window
		*	@param _height The new height of the window
		*
		*	Resizes the window and applies the info to OpenGL
		*/
		void resize(int _width, int _height);

		/** @brief Sets a new window title
		*	@param _title The new title to give the window
		*
		*	Sets a new window title to the one given
		*/
		void setTitle(const std::string &_title);

		/** @brief Get window surface
		*	@return The SDL surface for the window
		*
		*	Returns the window width.
		*/
		inline SDL_Surface * getSurface() { return SDL_GetWindowSurface(m_window); }

		/** @brief Get the window width
		*	@return An integar containing the window width
		*
		*	Returns the window width.
		*/
		inline int getWidth() { return m_width; }
		/** @brief Get the window Height
		*	@return An integar containing the window height
		*
		*	Returns the window height.
		*/
		inline int getHeight() { return m_height; }

	protected:
		SDL_Window		*m_window;				/**< A pointer to the SDL_Window. */
		SDL_Renderer	*m_renderer;			/**< A pointer to the SDL_Renderer. */


		int				 m_width;				/**< The Window Width */
		int				 m_height;				/**< The Window Width */
	};
}