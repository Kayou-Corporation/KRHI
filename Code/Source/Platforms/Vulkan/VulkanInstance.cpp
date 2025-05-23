#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{
	void VulkanInstance::Create(std::vector<const char*> extensions, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion)
	{
		VkApplicationInfo appInfo
		{
			.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
			.pApplicationName = appName.c_str(),
			.applicationVersion = VK_MAKE_VERSION(appVersion.major, appVersion.minor, appVersion.patch),
			.pEngineName = engineName.c_str(),
			.engineVersion = VK_MAKE_VERSION(engineVersion.major, engineVersion.minor, engineVersion.patch),
			.apiVersion = VK_API_VERSION_1_4
		};

		//VkInstanceCreateInfo createInfo
		//{
		//	.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		//	.pApplicationInfo = &appInfo,
		//	.enabledExtensionCount = static_cast<uint32_t>(extensions.size()),
		//	.ppEnabledExtensionNames = extensions.data(),
		//
		//	#ifdef KRHI_DEBUG
		//	.enabledLayerCount = 0,
		//	.ppEnabledLayerNames = {}
		//	#endif
		//};
	}
	void VulkanInstance::Destroy()
	{
		vkDestroyInstance(m_handle, nullptr);
	}
}