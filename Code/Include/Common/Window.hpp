// Copyright (c) 2025 Kayou Corporation. All rights reserved.

#pragma once

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"

/**
 * @file Window.hpp
 * @brief File for an abstract window class.
 */

namespace KRHI::Common
{
	class Instance;
	class Surface;

	/**
	* @class Window
	* @brief Abstract window class. Its purpose is to be a base for the user to create their own overriding class depending on the windowing api they use.
	*/
	class Window : public RefCast<Window>
	{
	public:
		/**
		 * @brief Default virtual destructor.
		 */
		KRHI_API virtual ~Window() = default;

		/**
		 * @brief Pure virtual method to create a window.
		 * @param width Wanted width of the window.
		 * @param height Wanted height of the window.
		 * @param name Name that will be displayed on the window.
		 */
		KRHI_API virtual void Create(int width, int height, const char* name) = 0;

		/**
		 * @brief Pure virtual method to destroy the window.
		 */
		KRHI_API virtual void Destroy() = 0;

		/**
		 * @brief Creates the window surface. Pure virtual method.
		 * @param instance Abstract instance. The user needs to cast it depending on the graphics api they are using.
		 * @param surface Abstract surface that will also need to be cast.
		 */
		KRHI_API virtual void CreateSurface(Ref<Instance> instance, Ref<Surface> surface) = 0;

		/**
		 * @brief Gets wether the window should close or not.
		 * @return Bool : true means window should close, false means it shouldn't.
		 */
		KRHI_API virtual bool ShouldClose() = 0;

		/**
		 * @brief Processes all pending events.
		 */
		KRHI_API virtual void PollEvents() = 0;

		/**
		 * @brief Gets the extensions for the instance.
		 * @param extensionsCount Unsigned int that the user creates on their side to know the number of available extensions.
		 * @return The array containing the extensions.
		 */
		KRHI_API virtual const char** GetInstanceExtensions(uint32_t& extensionsCount) = 0;
	};
}