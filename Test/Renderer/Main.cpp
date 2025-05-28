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

    window->Create(1920, 1080, "KRHI");

    uint32_t extensionsCount = 0;
    const char** rawExtensions = window->GetInstanceExtensions(extensionsCount);
    std::vector<const char*> extensions(rawExtensions, rawExtensions + extensionsCount);

    instance->Create({ extensions, {Common::ValidationLayers::VALIDATION,Common::ValidationLayers::DEBUG, Common::ValidationLayers::MONITOR}, "KRHI", { 0,0,1 }, "KRHI", { 0,0,1 } });
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