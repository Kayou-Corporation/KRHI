#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Platforms/Vulkan/VulkanInterface.hpp"
#include "GLWindow.hpp"


using namespace KRHI;

int main()
{
    std::cout << "KAYOU\n";
    Ref<Common::APIInterface> interface = Common::APIInterface::InitAPI(Common::BackendAPI::VULKAN);
    
    Ref<Common::Instance> instance = interface->InstantiateInstance();

    Ref<Common::Surface> surface = interface->InstantiateSurface();

    Ref<Common::Window> window = CreateRef<Examples::GLWindow>();

    glfwInit();
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    window->Create(1920, 1080, "KRHI");

    instance->Create({extensions, { Common::ValidationLayers::VALIDATION, Common::ValidationLayers::DEBUG, Common::ValidationLayers::MONITOR }, "KRHI", { 0,0,1 }, "KRHI", { 0,0,1 } });
    const vk::Instance vkInst = instance->Cast<Vulkan::VulkanInstance>()->GetHandle();
    static_cast<void>(vkInst);
    window->CreateSurface(instance, surface);

    while (!window->ShouldClose())
    {
        window->PollEvents();
    }

    extensions.clear();

    surface->Destroy(instance);

    instance->Destroy();

    window->Destroy();
    return 0;
}