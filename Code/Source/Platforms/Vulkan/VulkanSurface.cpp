// Copyright (c) 2025 Kayou Corporation. All rights reserved.

#include "Platforms/Vulkan/VulkanSurface.hpp"
#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{
	void VulkanSurface::Destroy(Ref<Common::Instance> instance)
	{
		const vk::Instance vkInstance = instance->Cast<VulkanInstance>()->GetHandle();
		vkInstance.destroySurfaceKHR(m_surface, nullptr);
	}
}
