#pragma once

#include <memory>

#include <vulkan/Vulkan.hpp>

#include "Common/Instance.hpp"

namespace KRHI::Vulkan
{

	class VulkanInstance : public Common::Instance
	{
	public:
		KRHI_API VulkanInstance() = default;
		KRHI_API ~VulkanInstance() override = default;

		KRHI_API void Create(std::vector<const char*> extensions, const std::vector<Common::ValidationLayers>& layers, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion) override;
		KRHI_API void Destroy() override {};

		KRHI_API FORCE_INLINE std::vector<const char*>& GetExtensions() override { return m_extensions; }
		KRHI_API FORCE_INLINE vk::Instance GetHandle() { return m_handle.get(); }

	private:
		vk::UniqueInstance m_handle;

#ifdef KRHI_DEBUG
		vk::UniqueDebugUtilsMessengerEXT m_debugMessenger;
		void CreateDebugMessenger();
		KRHI_API static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT a_messageSeverity, vk::DebugUtilsMessageTypeFlagsEXT a_messageType, const vk::DebugUtilsMessengerCallbackDataEXT* a_pCallbackData, void* a_pUserData);
#endif
		std::vector<const char*> m_extensions;

		void CreateInstance(std::vector<const char*> extensions, const std::vector<const char*>& vulkanLayers, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion);
		std::vector<const char*> GetLayers(const std::vector<Common::ValidationLayers>& abstractLayers);
	};
}