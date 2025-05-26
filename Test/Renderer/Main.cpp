#include <iostream>

#include "Platforms/Vulkan/VulkanInterface.hpp"

using namespace KRHI;

int main()
{
    std::cout << "KAYOU\n";
    Ref<Common::APIInterface> interface = Common::APIInterface::InitAPI(Common::BackendAPI::VULKAN);
    
    Ref<Common::Instance> instance = interface->InstantiateInstance();

    //instance->Create()
    return 0;
}