// Copyright (c) 2025 Kayou Corporation. All rights reserved.

#include "GLWindow.hpp"

#include "GLFW/glfw3.h"
#include "Platforms/Vulkan/VulkanInstance.hpp"
#include "Platforms/Vulkan/VulkanSurface.hpp"

namespace KRHI::Examples
{
	void GLWindow::Create(int width, int height, const char* name)
	{
		m_width = width;
		m_height = height;

		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		m_window = glfwCreateWindow(m_width, m_height, name, nullptr, nullptr);
		glfwSetWindowUserPointer(m_window, this);
	}

	void GLWindow::Destroy()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void GLWindow::CreateSurface(Ref<Common::Instance> instance, Ref<Common::Surface> surface)
	{
		VkSurfaceKHR vkSurface;
		glfwCreateWindowSurface(instance->Cast<Vulkan::VulkanInstance>()->GetHandle(), m_window, nullptr, &vkSurface);
		surface->Cast<Vulkan::VulkanSurface>()->SetHandle(vkSurface);
	}

	bool GLWindow::ShouldClose()
	{
		return glfwWindowShouldClose(m_window);
	}

	void GLWindow::PollEvents()
	{
		glfwPollEvents();
	}

	const char** GLWindow::GetInstanceExtensions(uint32_t& extensionsCount)
	{
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&extensionsCount);
		return glfwExtensions;
	}
}
