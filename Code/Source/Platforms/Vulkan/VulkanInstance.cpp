#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{
	void VulkanInstance::Create(std::vector<const char*> extensions, const std::vector<Common::ValidationLayers>& layers, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion)
	{

		vk::ApplicationInfo appInfo{};
		appInfo.pApplicationName = appName.c_str();
		appInfo.applicationVersion = VK_MAKE_VERSION(appVersion.major, appVersion.minor, appVersion.patch);
		appInfo.pEngineName = engineName.c_str();
		appInfo.engineVersion = VK_MAKE_VERSION(engineVersion.major, engineVersion.minor, engineVersion.patch);
		appInfo.apiVersion = VK_API_VERSION_1_4;
		
		std::vector<const char*> vulkanLayers = GetLayers(layers);

		vk::InstanceCreateInfo createInfo;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();

#ifdef KRHI_DEBUG
		createInfo.enabledLayerCount = static_cast<uint32_t>(vulkanLayers.size());
		createInfo.ppEnabledLayerNames = vulkanLayers.data();
#else
		createInfo.enabledLayerCount = 0;
		createInfo.ppEnabledLayerNames = {};
#endif

		m_handle = vk::createInstance(createInfo);
		m_extensions = extensions;

		vulkanLayers.clear();
		extensions.clear();
	}

	void VulkanInstance::Destroy()
	{
		m_handle.destroy();
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