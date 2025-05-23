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

		KRHI_API void Create(std::vector<const char*> extensions, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion) override;
		KRHI_API void Destroy() override;

		KRHI_API FORCE_INLINE std::vector<const char*>& GetExtensions() override { return m_extensions; }

	private:
		VkInstance m_handle = nullptr;
		std::vector<const char*> m_extensions = std::vector<const char*>(0, nullptr);
	};
}