#pragma once

#include <memory>

#include <vulkan/Vulkan.hpp>

#include "Common/Instance.hpp"

namespace KRHI::Vulkan
{	
    /**
    * @file VulkanInstance.hpp
    * @brief Vulkan implementation of instance creation and all data required
    */

    /**
    * @class VulkanInstance
    * @brief Vulkan override of common instance class, responsible for holding the instance & the debug system
    */
    class VulkanInstance : public Common::Instance
    {
    public:
        KRHI_API VulkanInstance() = default;
        KRHI_API ~VulkanInstance() override = default;

        /**
        * @brief Vulkan override of common function to create the instance class & the debugger, check the common implementation to have details about the parameters
        */
        KRHI_API void Create(std::vector<const char*> extensions, const std::vector<Common::ValidationLayers>& layers, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion) override;

        /**
        * @brief Vulkan override of common function to destroy the instance & the debugger
        */
        KRHI_API void Destroy() override;

        /**
        * @brief Vulkan override of common getter
        */
        KRHI_API FORCE_INLINE std::vector<const char*>& GetExtensions() override { return m_extensions; }

        /**
        * @brief Vulkan function of get the vk::Instance
        */
        KRHI_API FORCE_INLINE const vk::Instance& GetHandle() const { return m_handle; }
        KRHI_API FORCE_INLINE const vk::detail::DispatchLoaderDynamic& GetDynamicLoader() const { return m_dispatchLoader; }

    private:
        /**
        * @brief Vulkan instance
        */
        vk::Instance m_handle;

        /**
        * @brief Intern function, to create the vk::Instance
        */
        void CreateInstance(std::vector<const char*> extensions, const std::vector<const char*>& vulkanLayers, const std::string& appName, const Common::Version& appVersion, const std::string& engineName, const Common::Version& engineVersion);

        /**
        * @brief List of instance extensions
        */
        std::vector<const char*> m_extensions;

        /**
        * @brief Intern function, to translate the abstract layers into vulkan layers
        * @param abstractLayers list of abstract layers to be translate into vulkan
        */
        /// Validation => VK_LAYER_KHRONOS_validation
        /// Monitor => VK_LAYER_LUNARG_monitor
        /// Simulation => VK_LAYER_LUNARG_device_simulation
        /// Debug => VK_LAYER_LUNARG_gfxreconstruct
        std::vector<const char*> GetLayers(const std::vector<Common::ValidationLayers>& abstractLayers);

        /**
        * @brief Vulkan dispatch system, only available in debug mod
        */
        vk::detail::DispatchLoaderDynamic m_dispatchLoader;

#ifdef KRHI_DEBUG
        /**
        * @brief Vulkan debug system, only available in debug mod
        */
        vk::DebugUtilsMessengerEXT m_debugMessenger;

        /**
        * @brief Intern function, to create the the debugger
        */
        void CreateDebugMessenger();

        /**
        * @brief Intern function, default vulkan debug callback
        */
        KRHI_API static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT a_messageSeverity, vk::DebugUtilsMessageTypeFlagsEXT a_messageType, const vk::DebugUtilsMessengerCallbackDataEXT* a_pCallbackData, void* a_pUserData);
#endif

    };
}
