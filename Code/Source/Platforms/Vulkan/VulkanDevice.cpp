#include "Common/Surface.hpp"

#include "Platforms/Vulkan/VulkanDevice.hpp"

#include <set>

#include "Platforms/Vulkan/VulkanInstance.hpp"


namespace KRHI::Vulkan
{
	std::ostream operator<<(const std::ostream& lhs, const vk::QueueFlags& rhs);

	void VulkanDevice::Create(const Ref<Common::Instance> instance, const Ref<Common::Surface> surface)
	{
		static_cast<void>(instance);
		static_cast<void>(surface);
	}


	void VulkanDevice::Destroy()
	{

	}



	bool VulkanDevice::CheckDeviceExtensionSupport() const
	{
		std::vector<vk::ExtensionProperties> extensions = m_physicalHandle.enumerateDeviceExtensionProperties();
		std::set<std::string> requiredExtensions(extensions.begin(), extensions.end());

		for (const vk::ExtensionProperties& extension : extensions)
			requiredExtensions.erase(extension.extensionName);

		return requiredExtensions.empty();
	}


	VulkanDevice::QueueFamilyIndices VulkanDevice::FindQueueFamilies(const vk::SurfaceKHR& surface) const
	{
		QueueFamilyIndices queueFamilyIndices = {};
		const std::vector<vk::QueueFamilyProperties> queueFamilyProperties = m_physicalHandle.getQueueFamilyProperties();

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

			const vk::Bool32 presentSupport = m_physicalHandle.getSurfaceSupportKHR(i, surface);
			std::cout << "Queue family " << i << " supports surface: " << presentSupport  << "\n";

			if (presentSupport)
				queueFamilyIndices.presentFamily = i;

			if (queueFamilyIndices.IsComplete())
				break;

			++i;
		}
		return queueFamilyIndices;
	}


	void VulkanDevice::SelectPhysicalDevice(const vk::Instance& instance)
	{
		const std::vector<vk::PhysicalDevice> physicalDevices = instance.enumeratePhysicalDevices();

		// TODO : Replace with logger
		if (physicalDevices.empty())
			throw std::runtime_error("No physical devices found");

		// Todo : Check if device is Suitable using IsDeviceSuitable
		for (const vk::PhysicalDevice& device : physicalDevices)
		{
			m_physicalHandle = device;
		}

		// Todo : Replace with logger
		if (m_physicalHandle == nullptr)
			throw std::runtime_error("No physical devices found");
	}


	bool VulkanDevice::IsDeviceSuitable(const vk::SurfaceKHR& surface) const
	{
		QueueFamilyIndices queueFamilyIndices = FindQueueFamilies(surface);
		bool extensionsSupported = CheckDeviceExtensionSupport();
		bool isSwapchainAdequate = false;

		if (extensionsSupported)
		{
		}

		return false;
	}
}
