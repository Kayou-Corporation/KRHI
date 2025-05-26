#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{
	void VulkanInstance::Create(std::vector<const char*> extensions, const std::vector<Common::ValidationLayers>& layers, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion)
	{
		std::vector<const char*> vulkanLayers = GetLayers(layers);
		CreateInstance(extensions, vulkanLayers, appName, appVersion, engineName, engineVersion);

#ifdef KRHI_DEBUG
		CreateDebugMessenger();
#endif

		m_extensions = extensions;

		vulkanLayers.clear();
		extensions.clear();
	}

	void VulkanInstance::Destroy()
	{
#ifdef KRHI_DEBUG
		m_handle.destroyDebugUtilsMessengerEXT(m_debugMessenger, nullptr, m_dispatchLoader);
#endif
		m_handle.destroy();
	}

	void VulkanInstance::CreateInstance(std::vector<const char*> extensions, const std::vector<const char*>& vulkanLayers, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion)
	{
		vk::ApplicationInfo appInfo{};
		appInfo.pApplicationName = appName.c_str();
		appInfo.applicationVersion = VK_MAKE_VERSION(appVersion.major, appVersion.minor, appVersion.patch);
		appInfo.pEngineName = engineName.c_str();
		appInfo.engineVersion = VK_MAKE_VERSION(engineVersion.major, engineVersion.minor, engineVersion.patch);
		appInfo.apiVersion = VK_API_VERSION_1_4;

		vk::InstanceCreateInfo createInfo;
		createInfo.pApplicationInfo = &appInfo;

#ifdef KRHI_DEBUG
		bool debugUtilsPresent = std::any_of(extensions.begin(), extensions.end(), [](const char* ext) { return std::strcmp(ext, VK_EXT_DEBUG_UTILS_EXTENSION_NAME) == 0; });

		if (!debugUtilsPresent)
		{
			extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		}

		createInfo.enabledLayerCount = static_cast<uint32_t>(vulkanLayers.size());
		createInfo.ppEnabledLayerNames = vulkanLayers.data();
#else
		createInfo.enabledLayerCount = 0;
		createInfo.ppEnabledLayerNames = {};
#endif

		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();

		m_handle = vk::createInstance(createInfo);

#ifdef KRHI_DEBUG
		vk::detail::DynamicLoader dl;
		PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr =
			dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");

		m_dispatchLoader.init(m_handle, vkGetInstanceProcAddr);
#endif
	}

#ifdef KRHI_DEBUG
	void VulkanInstance::CreateDebugMessenger()
	{
		vk::DebugUtilsMessengerCreateInfoEXT createInfo{};
		createInfo.messageSeverity = vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo |
			vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose |
			vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning |
			vk::DebugUtilsMessageSeverityFlagBitsEXT::eError;

		createInfo.messageType = vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral |
			vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation |
			vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance;

		createInfo.pfnUserCallback = DebugCallback;

		m_debugMessenger = m_handle.createDebugUtilsMessengerEXT(createInfo, nullptr, m_dispatchLoader);
	}

	// TODO (Ethan / Corentin) : Change to use Logger instead when it's ready
	VKAPI_ATTR VkBool32 VKAPI_CALL VulkanInstance::DebugCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT a_messageSeverity, vk::DebugUtilsMessageTypeFlagsEXT a_messageType, const vk::DebugUtilsMessengerCallbackDataEXT* a_pCallbackData, void* a_pUserData)
	{
		static_cast<void>(a_pUserData);

		std::string t_messageType;

		if (a_messageType & vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral)
		{
			t_messageType = "GENERAL";
		}
		else if (a_messageType & vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation)
		{
			t_messageType = "VALIDATION";
		}
		else if (a_messageType & vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance)
		{
			t_messageType = "PERFORMANCE";
		}

		if (a_messageSeverity & vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose)
		{
			//LOG_VERBOSE("[Vulkan] : Validation layers: " + t_messageType + " " + Debugging::ToString(a_pCallbackData->pMessage) + '\n');
			std::cout << "[Vulkan] : Validation layers: " + t_messageType + " " + a_pCallbackData->pMessage + '\n';
		}
		else if (a_messageSeverity & vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo)
		{
			//LOG_INFO("[Vulkan] : Validation layers: " + t_messageType + " " + Debugging::ToString(a_pCallbackData->pMessage) + '\n');
			std::cout << "[Vulkan] : Validation layers: " + t_messageType + " " + a_pCallbackData->pMessage + '\n';
		}
		else if (a_messageSeverity & vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning)
		{
			//LOG_WARNING("[Vulkan] : Validation layers: " + t_messageType + " " + Debugging::ToString(a_pCallbackData->pMessage) + '\n');
			std::cout << "[Vulkan] : Validation layers: " + t_messageType + " " + a_pCallbackData->pMessage + '\n';
		}
		else if (a_messageSeverity & vk::DebugUtilsMessageSeverityFlagBitsEXT::eError)
		{
			//LOG_ERROR("[Vulkan] : Validation layers: " + t_messageType + " " + Debugging::ToString(a_pCallbackData->pMessage) + '\n');
			std::cout << "[Vulkan] : Validation layers: " + t_messageType + " " + a_pCallbackData->pMessage + '\n';
		}

		return VK_FALSE;
	}
#endif

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