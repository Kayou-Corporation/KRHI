#include "Platforms/Vulkan/VulkanDevice.hpp"

#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{
	void VulkanDevice::Create(Ref<Common::Instance> instance, Ref<Common::Surface> surface)
	{
		static_cast<void>(instance);
		static_cast<void>(surface);
	}

	void VulkanDevice::Destroy()
	{

	}

	void VulkanDevice::CreatePhysicalDevice(const vk::Instance instance, const vk::SurfaceCapabilitiesKHR surface)
	{
		static_cast<void>(instance);
		static_cast<void>(surface);
		//uint32_t physicalDevicesCount = 0;
		//std::vector<VkPhysicalDevice> physicalDevies;
		//instance.enumeratePhysicalDevices(physicalDevicesCount, physicalDevies.data());
	}
}