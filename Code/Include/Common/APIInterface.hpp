#pragma once

#include "Common/Instance.hpp"

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"

namespace KRHI::Vulkan
{
	class VulkanInterface;
}

namespace KRHI::Common
{
	/**
	* @file APIInterface.hpp
	* @brief Common implementation of API instancing and all required class
	*/

	/**
	* @enum BackendAPI
	* @brief Enum to describe all API implementation available
	*/
	enum class BackendAPI : uint8_t
	{
		NONE = 0,
		VULKAN = 1
	};

	class APIInterface
	{
	public:
		KRHI_API static Ref<APIInterface> InitAPI(BackendAPI api);
		KRHI_API virtual ~APIInterface() = default;

		KRHI_API virtual Ref<Instance> InstantiateInstance() = 0;
		KRHI_API virtual void DestroyInstance(Ref<Instance> instance) { instance.reset(); }
	};
}