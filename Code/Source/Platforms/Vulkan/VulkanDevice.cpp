#include "Platforms/Vulkan/VulkanDevice.hpp"

#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{
	void VulkanDevice::Create(const Ref<Common::Instance> instance, const Ref<Common::Surface> surface)
	{
		static_cast<void>(instance);
		static_cast<void>(surface);
	}


	void VulkanDevice::Destroy()
	{

	}


	/*std::ostream operator<<(const std::ostream& lhs, const vk::QueueFlags& rhs);

	VulkanDevice::QueueFamilyIndices VulkanDevice::GetQueueFamilies() const
	{
		QueueFamilyIndices queueFamilyIndices = {};

		uint32_t queueFamilyCount = 0;
		m_physicalHandle.getQueueFamilyProperties(&queueFamilyCount, nullptr);

		std::vector<vk::QueueFamilyProperties> queueFamilyProperties = m_physicalHandle.getQueueFamilyProperties();

		std::cout << "Queue Family size: " << queueFamilyProperties.size() << std::endl;
		for (size_t i = 0; i < queueFamilyProperties.size(); ++i)
		{
			std::cout << "Queue Family #" << i << ":\n";
			std::cout << " - Queue count: " << queueFamilyProperties[i].queueCount << "\n";
			std::cout << " - Flags: " << queueFamilyProperties[i].queueFlags << "\n";
		}

		int i = 0;
		for (const auto& queueFamily : queueFamilyProperties)
		{
			if (queueFamily.queueFlags & vk::QueueFlagBits::eGraphics)
				queueFamilyIndices.graphicsFamily = i;

			const vk::Bool32 presentSupport = false;
			vk::Result result = m_physicalHandle.getSurfaceSupportKHR(i, surface);
			std::cout << "Queue family " << i << " supports surface: " << (result ? "Yes" : "No") << "\n";

			if (presentSupport)
				queueFamilyIndices.presentFamily = i;

			if (queueFamilyIndices.IsComplete())
				break;

			++i;
		}
		return queueFamilyIndices;
	}*/


	void VulkanDevice::CreatePhysicalDevice(const vk::Instance& instance, const vk::SurfaceCapabilitiesKHR& surface)
	{
		static_cast<void>(instance);
		static_cast<void>(surface);
		//uint32_t physicalDevicesCount = 0;
		//std::vector<VkPhysicalDevice> physicalDevies;
		//instance.enumeratePhysicalDevices(physicalDevicesCount, physicalDevies.data());
	}
}