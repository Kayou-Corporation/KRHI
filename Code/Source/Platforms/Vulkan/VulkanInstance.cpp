#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{
	void VulkanInstance::Create(std::vector<const char*> extensions, const std::vector<Common::ValidationLayers>& layers, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion)
	{
		//VkApplicationInfo appInfo
		//{
		//	.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
		//	.pApplicationName = appName.c_str(),
		//	.applicationVersion = VK_MAKE_VERSION(appVersion.major, appVersion.minor, appVersion.patch),
		//	.pEngineName = engineName.c_str(),
		//	.engineVersion = VK_MAKE_VERSION(engineVersion.major, engineVersion.minor, engineVersion.patch),
		//	.apiVersion = VK_API_VERSION_1_4
		//};
		//
		//std::vector<const char*> vulkanLayers = GetLayers(layers);
		//VkInstanceCreateInfo createInfo
		//{
		//	.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		//	.pApplicationInfo = &appInfo,
		//	.enabledExtensionCount = static_cast<uint32_t>(extensions.size()),
		//	.ppEnabledExtensionNames = extensions.data(),
		//
		//	#ifdef KRHI_DEBUG
		//	.enabledLayerCount = vulkanLayers.size(),
		//	.ppEnabledLayerNames = vulkanLayers.data()
		//	#else
		//	.enabledLayerCount = 0,
		//	.ppEnabledLayerNames = {}
		//	#endif
		//};


	}

	void VulkanInstance::Destroy()
	{
		vkDestroyInstance(m_handle, nullptr);
	}

	std::vector<const char*> VulkanInstance::GetLayers(const std::vector<Common::ValidationLayers>& abstractLayers)
	{
		std::vector<const char*> layers;

		for (Common::ValidationLayers layer : abstractLayers)
		{
			switch (layer)
			{
			case Common::ValidationLayers::Validation:
					layers.push_back("VK_LAYER_KHRONOS_validation");
					break;
			case Common::ValidationLayers::Monitor:
				layers.push_back("VK_LAYER_LUNARG_monitor");
				break;
			case Common::ValidationLayers::Simulation:
				layers.push_back("VK_LAYER_LUNARG_device_simulation");
				break;
			case Common::ValidationLayers::Debug:
				layers.push_back("VK_LAYER_LUNARG_gfxreconstruct");
				break;
			default:
				// TODO : ADD Warning unsupported layer
				break;
			}
		}

		return layers;
	}
}