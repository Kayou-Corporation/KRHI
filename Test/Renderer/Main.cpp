#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Platforms/Vulkan/VulkanInterface.hpp"


using namespace KRHI;

int main()
{
    std::cout << "KAYOU\n";
    Ref<Common::APIInterface> interface = Common::APIInterface::InitAPI(Common::BackendAPI::VULKAN);
    
    Ref<Common::Instance> instance = interface->InstantiateInstance();

    glfwInit();
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    instance->Create({ extensions, { Common::ValidationLayers::VALIDATION, Common::ValidationLayers::DEBUG, Common::ValidationLayers::MONITOR }, "KRHI", { 0,0,1 }, "KRHI", { 0,0,1 } });

    instance->Destroy();
    return 0;
}