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
		KRHI_API void Create(Ref<Common::Instance> instance, Ref<Common::Surface> surface) override;
		KRHI_API void Destroy() override;


	private:
		void SelectPhysicalDevice(const vk::Instance& instance);
		void CreateLogicalDevice();
		bool IsDeviceSuitable(const vk::PhysicalDevice& physicalDevice) const;
		bool CheckDeviceExtensionSupport() const;
		QueueFamilyIndices FindQueueFamilies(const vk::SurfaceKHR& surface) const;

		vk::Device m_handle = nullptr;

		vk::PhysicalDevice m_physicalHandle = nullptr;
	};
}