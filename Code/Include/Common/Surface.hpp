// Copyright (c) 2025 Kayou Corporation. All rights reserved.

#pragma once

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"

/**
 * @file Surface.hpp
 * @brief File for an abstract surface class.
 */

namespace KRHI::Common
{
	class Instance;

	/**
	* @class Surface
	* @brief Abstract surface class. It is a base for the implementations for different graphics api's.
	*/
	class Surface : public RefCast<Surface>
	{
	public:
		/**
		 * @brief Default virtual destructor.
		 */
		KRHI_API virtual ~Surface() = default;

		/**
		 * @brief Pure virtual method to destroy the surface.
		 * @param instance Abstract instance created from the desired graphics api's instance.
		 */
		KRHI_API virtual void Destroy(Ref<Instance> instance) = 0;
	};
}