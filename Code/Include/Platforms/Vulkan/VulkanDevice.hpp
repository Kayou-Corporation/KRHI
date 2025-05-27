#pragma once

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
		KRHI_API QueueFamilyIndices GetQueueFamilies(Ref<Common::Surface> surface) const;


	private:
		vk::Device m_handle = nullptr;

		vk::PhysicalDevice m_physicalHandle = nullptr;
		void CreatePhysicalDevice(const vk::Instance& instance, const vk::SurfaceCapabilitiesKHR& surface);

	};
}