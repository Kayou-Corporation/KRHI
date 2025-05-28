#include <set>
#include <string>
#include <map>

#include "Platforms/Vulkan/VulkanDevice.hpp"

#include "Common/Instance.hpp"
#include "Platforms/Vulkan/VulkanInstance.hpp"
#include "Platforms/Vulkan/VulkanSurface.hpp"


namespace KRHI::Vulkan
{
	std::ostream operator<<(const std::ostream& lhs, const vk::QueueFlags& rhs);

	void VulkanDevice::Create(const Ref<Common::Instance>& instance, const Ref<Common::Surface>& surface, const DeviceSpec& spec)
	{
		static_cast<void>(spec);
		SelectPhysicalDevice(instance->Cast<VulkanInstance>()->GetHandle(), surface->Cast<VulkanSurface>()->GetHandle());
	}


	void VulkanDevice::Destroy()
	{

	}


	VulkanDevice::QueueFamilyIndices VulkanDevice::FindQueueFamilies(const vk::PhysicalDevice& physicalDevice, const vk::SurfaceKHR& surface) const
	{
		QueueFamilyIndices queueFamilyIndices = {};
		const std::vector<vk::QueueFamilyProperties> queueFamilyProperties = physicalDevice.getQueueFamilyProperties();

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


	vk::Format VulkanDevice::FindSupportedFormat(const std::vector<vk::Format>& candidates, const vk::ImageTiling& tiling, const vk::FormatFeatureFlags& features) const
	{
		for (const vk::Format format : candidates)
		{
			vk::FormatProperties properties = m_physicalHandle.getFormatProperties(format);

			if (tiling == vk::ImageTiling::eLinear && (properties.linearTilingFeatures & features) == features)
				return format;

			if (tiling == vk::ImageTiling::eOptimal && (properties.optimalTilingFeatures & features) == features)
				return format;
		}
		return vk::Format::eUndefined;
	}


	std::vector<std::string> VulkanDevice::GetAvailableDeviceExtensions(const std::vector<Common::DeviceExtensions>& abstractExtensions)
	{
		std::vector<std::string> extensions = {};

		for (const Common::DeviceExtensions extension : abstractExtensions)
		{
			switch (extension)
			{
			case Common::DeviceExtensions::SWAPCHAIN:
				extensions.push_back("VK_EXT_swapchainKHR");
				break;

			case Common::DeviceExtensions::SURFACE:
				extensions.push_back("VK_KHR_surface");
				break;

			case Common::DeviceExtensions::DEBUG_UTILS:
				extensions.push_back("VK_EXT_debug_report");
				break;

			case Common::DeviceExtensions::PORTABILITY_SUBSET:
				extensions.push_back("VK_KHR_portability_subset");
				break;

			case Common::DeviceExtensions::MAINTENANCE5:
				extensions.push_back("VK_KHR_maintenance5");
				break;

			case Common::DeviceExtensions::MAINTENANCE6:
				extensions.push_back("VK_KHR_maintenance6");
				break;

			case Common::DeviceExtensions::MAINTENANCE8:
				extensions.push_back("VK_KHR_maintenance8");
				break;

			case Common::DeviceExtensions::DYNAMIC_RENDERING_LOCAL_READ:
				extensions.push_back("VK_KHR_dynamic_rendering_local_memory");
				break;

			case Common::DeviceExtensions::SHADER_SUBGROUP_ROTATE:
				extensions.push_back("VK_KHR_shader_subgroup_rotate");
				break;

			case Common::DeviceExtensions::SHADER_FLOAT_CONTROLS2:
				extensions.push_back("VK_KHR_shader_float_controls2");
				break;

			case Common::DeviceExtensions::SHADER_EXPECT_ASSUME:
				extensions.push_back("VK_KHR_shader_evaluation_index");
				break;

			case Common::DeviceExtensions::LINE_RASTERIZATION:
				extensions.push_back("VK_KHR_rasterizer_discard_state");
				break;

			case Common::DeviceExtensions::VERTEX_ATTRIBUTE_DIVISOR:
				extensions.push_back("VK_KHR_vertex_attrib_divisor");
				break;

			case Common::DeviceExtensions::INDEX_TYPE_UINT8:
				extensions.push_back("VK_KHR_graphics_3d_index");
				break;

			case Common::DeviceExtensions::MAP_MEMORY2:
				extensions.push_back("VK_KHR_map_memory2");
				break;

			case Common::DeviceExtensions::PUSH_DESCRIPTOR:
				extensions.push_back("VK_KHR_push_descriptor");
				break;

			case Common::DeviceExtensions::VIDEO_MAINTENANCE2:
				extensions.push_back("VK_KHR_video_memory2");
				break;

			case Common::DeviceExtensions::PIPELINE_PROTECTED_ACCESS:
				extensions.push_back("VK_KHR_pipeline_statistics2");
				break;

			case Common::DeviceExtensions::PIPELINE_ROBUSTNESS:
				extensions.push_back("VK_KHR_pipeline_statistics2");
				break;

			case Common::DeviceExtensions::HOST_IMAGE_COPY:
				extensions.push_back("VK_KHR_host_imagecopy");
				break;

			case Common::DeviceExtensions::EXTERNAL_MEMORY_METAL:
				extensions.push_back("VK_KHR_external_memory_metal");
				break;
			}
		}
		return extensions;
	}


	void VulkanDevice::SelectPhysicalDevice(const vk::Instance& instance, const vk::SurfaceKHR& surface)
	{
		std::vector<vk::PhysicalDevice> physicalDevices = instance.enumeratePhysicalDevices();

		// TODO : Replace with logger
		if (physicalDevices.empty())
			throw std::runtime_error("No physical devices found");

		std::multimap<uint32_t, vk::PhysicalDevice> candidates = {};
		// Todo : Check if device is Suitable using IsDeviceSuitable
		for (const vk::PhysicalDevice& device : physicalDevices)
		{
			uint32_t score = RatePhysicalDevice(device, surface);
			candidates.insert(std::make_pair(score, device));
		}

		// Todo : Replace with logger
		if (candidates.empty())
			throw std::runtime_error("No physical devices found");

		m_physicalHandle = candidates.rbegin()->second;
		std::cout << "Selected physical device: " << m_physicalHandle << std::endl;
		std::cout << "Score: " << candidates.rbegin()->first << std::endl;

		candidates.clear();
		physicalDevices.clear();
	}


	bool VulkanDevice::IsDeviceSuitable(const vk::PhysicalDevice& physicalDevice, const vk::SurfaceKHR& surface) const
	{
		/*vk::PhysicalDeviceProperties properties = m_physicalHandle.getProperties();
		vk::PhysicalDeviceFeatures features = m_physicalHandle.getFeatures();

		QueueFamilyIndices queueFamilyIndices = FindQueueFamilies(surface);
		bool extensionsSupported = CheckDeviceExtensionSupport();
		bool isSwapchainAdequate = false;

		if (extensionsSupported)
		{
		}

		return false;*/

		const QueueFamilyIndices queueFamilyIndices = FindQueueFamilies(physicalDevice, surface);
		return queueFamilyIndices.IsComplete();
	}


	uint32_t VulkanDevice::RatePhysicalDevice(const vk::PhysicalDevice& physicalDevice, const vk::SurfaceKHR& surface)
	{
		const vk::PhysicalDeviceProperties properties = physicalDevice.getProperties();
		const vk::PhysicalDeviceFeatures features = physicalDevice.getFeatures();

		uint32_t deviceScore = 0;

		if (!features.geometryShader || !IsDeviceSuitable(physicalDevice, surface))
			return 0;

		if (properties.deviceType == vk::PhysicalDeviceType::eDiscreteGpu)
			deviceScore += 1000;

		deviceScore += properties.limits.maxImageDimension2D;
		return deviceScore;
	}
}
