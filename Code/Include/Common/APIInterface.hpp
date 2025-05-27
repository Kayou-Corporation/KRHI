#pragma once


#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"

namespace KRHI::Common
{
	class Instance;
	/**
	* @file APIInterface.hpp
	* @brief Common implementation of API instancing and all required class
	*/

	class Surface;

	/**
	* @enum BackendAPI
	* @brief Enum to describe all API implementation available
	*/
	enum class BackendAPI : uint8_t
	{
		NONE = 0,
		VULKAN = 1
	};

	/**
	* @class APIInterface
	* @brief Class to instantiate API object
	*/
	class APIInterface
	{
	public:
		/**
		* @brief Function to init the interface into the right API (Vulkan, DirectX12, etc...)
		*/
		KRHI_API static Ref<APIInterface> InitAPI(BackendAPI api);
		KRHI_API virtual ~APIInterface() = default;

		/**
		* @brief Abstract function to instantiate the instance (VulkanInstance, etc..)
		*/
		KRHI_API virtual Ref<Instance> InstantiateInstance() = 0;

		/**
		* @brief Abstract function to instantiate the surface (VulkanSurface, etc..)
		*/
		KRHI_API virtual Ref<Surface> InstantiateSurface() = 0;

		/**
		* @brief Abstract function to destroy the instance (VulkanInstance, etc..)
		*/
		KRHI_API virtual void DestroyInstance(Ref<Instance> instance) { instance.reset(); }
	};
}