#include "Common/APIInterface.hpp"

#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{
	/**
	* @file VulkanInterface.hpp
	* @brief Vulkan implementation to instanciate all required class
	*/

	/**
	* @class VulkanInterface
	* @brief Vulkan derived class of APIInterface
	*/
	class VulkanInterface : public Common::APIInterface
	{
	public:
		KRHI_API ~VulkanInterface() override = default;

		/**
		* @brief Vulkan derived function of APIInterface to instanciate instance (VulkanInstance)
		*/
		KRHI_API Ref<Common::Instance> InstantiateInstance() override { return CreateRef<VulkanInstance>(); }
	};
}