// Copyright (c) 2025 Kayou Corporation. All rights reserved.

#pragma once

#include <vulkan/vulkan.hpp>

#include "Common/Surface.hpp"

/**
 * @file VulkanSurface.hpp
 * @brief Declares the Vulkan-specific implementation of a rendering surface.
 */

namespace KRHI::Vulkan
{
	/**
	* @class VulkanSurface
	* @brief Vulkan implementation of the surface.
	*
	* This class manages a Vulkan-compatible surface used for rendering,
	* including its creation, querying supported formats and present modes,
	* and capability description.
	*/
	class VulkanSurface : public Common::Surface
	{
	public:
		/**
		 * @brief Default overriding destructor.
		 */
		KRHI_API ~VulkanSurface() override = default;

		/**
		 * @brief Destroys the Vulkan surface.
		 * @param instance Pointer to the abstract Vulkan instance that owns the surface.
		 *
		 * This method should be called to clean up the Vulkan surface resources.
		 */
		KRHI_API void Destroy(Ref<Common::Instance> instance) override;

		/**
		 * @brief Gets the raw Vulkan surface handle.
		 * @return Reference to the VkSurfaceKHR handle.
		 */
		KRHI_API vk::SurfaceKHR& GetHandle() { return m_handle; }

		/**
		 * @brief Retrieves the surface capabilities supported by the GPU.
		 * @return A VkSurfaceCapabilitiesKHR structure with the surface's properties.
		 */
		KRHI_API vk::SurfaceCapabilitiesKHR GetSurfaceCapabilities() const { return m_capabilities; }

		/**
		 * @brief Gets the supported surface formats.
		 * @return A vector of VkSurfaceFormatKHR representing the available formats.
		 */
		KRHI_API std::vector<vk::SurfaceFormatKHR> GetSurfaceFormats() const { return m_formats; }

		/**
		 * @brief Gets the supported presentation modes.
		 * @return A vector of VkPresentModeKHR representing available presentation modes.
		 */
		KRHI_API std::vector<vk::PresentModeKHR> GetSurfacePresentModes() const { return m_presentModes; }

		KRHI_API void SetHandle(const vk::SurfaceKHR& newHandle) { m_handle = newHandle; }

	private:
		vk::SurfaceKHR m_handle = nullptr;                         ///< The Vulkan surface handle.
		vk::SurfaceCapabilitiesKHR m_capabilities{};                ///< Surface capabilities (e.g., min/max image count, extent, etc.).
		std::vector<vk::SurfaceFormatKHR> m_formats{};              ///< Supported surface formats.
		std::vector<vk::PresentModeKHR> m_presentModes{};           ///< Supported presentation modes.
	};
}