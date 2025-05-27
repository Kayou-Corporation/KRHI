#pragma once

#include <vulkan/Vulkan.hpp>

#include "Common/Device.hpp"

namespace KRHI::Vulkan
{
	class VulkanDevice : public Common::Device
	{
	public:
		KRHI_API void Create(Ref<Common::Instance> instance, Ref<Common::Surface> surface) override;
		KRHI_API void Destroy() override;



	private:
		vk::Device m_handle = nullptr;

		vk::PhysicalDevice m_physicalHandle = nullptr;
		void CreatePhysicalDevice(const vk::Instance instance, const vk::SurfaceCapabilitiesKHR surface);

	};
}