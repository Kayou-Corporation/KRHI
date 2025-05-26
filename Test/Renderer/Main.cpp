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

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    instance->Create(extensions, { Common::ValidationLayers::Validation,Common::ValidationLayers::Debug, Common::ValidationLayers::Monitor }, "KRHI", { 0,0,1 }, "KRHI", { 0,0,1 });

    delete glfwExtensions;
    extensions.clear();

    instance->Destroy();
    return 0;
}