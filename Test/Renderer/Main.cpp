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

    instance->Create(extensions, { Common::ValidationLayers::Validation,Common::ValidationLayers::Debug, Common::ValidationLayers::Monitor }, "KRHI", { 0,0,1 }, "KRHI", { 0,0,1 });

    window->CreateSurface(instance, surface);

    while (!window->ShouldClose())
    {
        window->PollEvents();
    }

    extensions.clear();

    instance->Destroy();

    window->Destroy();
    return 0;
}