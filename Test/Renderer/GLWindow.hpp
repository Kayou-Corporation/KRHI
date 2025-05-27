// Copyright (c) 2025 Kayou Corporation. All rights reserved.

#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Common/Window.hpp"

namespace KRHI::Examples
{
	class GLWindow final : public Common::Window
	{
	public:
		KRHI_API ~GLWindow() override = default;
		KRHI_API void Create(int width, int height, const char* name) override;
		KRHI_API void Destroy() override;
		KRHI_API void CreateSurface(Ref<Common::Instance> instance, Ref<Common::Surface> surface) override;
		KRHI_API bool ShouldClose() override;
		KRHI_API void PollEvents() override;

	private:
		int m_width = 0;
		int m_height = 0;
		GLFWwindow* m_window = nullptr;
	};
}