#pragma once

#include <optional>

#include <vulkan/Vulkan.hpp>

#include "Common/Device.hpp"

namespace KRHI::Vulkan
{
	class VulkanDevice : public Common::Device
	{
		struct QueueFamilyIndices
		{
			std::optional<uint32_t> graphicsFamily = {};
			std::optional<uint32_t> presentFamily = {};

			bool IsComplete() const { return graphicsFamily.has_value() && presentFamily.has_value(); }
		};


	public:
		VulkanDevice() = default;
		~VulkanDevice() override = default;

		KRHI_API void Create(const Ref<Common::Instance>& instance, const Ref<Common::Surface>& surface, const DeviceSpec& spec) override;
		KRHI_API void Destroy() override;


	private:
		void SelectPhysicalDevice(const vk::Instance& instance, const vk::SurfaceKHR& surface);
		void CreateLogicalDevice();
		bool IsDeviceSuitable(const vk::PhysicalDevice& physicalDevice, const vk::SurfaceKHR& surface) const;
		//bool CheckDeviceExtensionSupport(const std::vector<std::string>& requiredExtensions) const;
		uint32_t RatePhysicalDevice(const vk::PhysicalDevice& physicalDevice, const vk::SurfaceKHR& surface);
		QueueFamilyIndices FindQueueFamilies(const vk::PhysicalDevice& physicalDevice, const vk::SurfaceKHR& surface) const;
		vk::Format FindSupportedFormat(const std::vector<vk::Format>& candidates, const vk::ImageTiling& tiling, const vk::FormatFeatureFlags& features) const;
		std::vector<std::string> GetAvailableDeviceExtensions(const std::vector<Common::DeviceExtensions>& abstractExtensions);

		vk::Device m_handle = nullptr;
		vk::PhysicalDevice m_physicalHandle = nullptr;
	};
}