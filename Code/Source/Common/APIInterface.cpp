#include "Common/APIInterface.hpp"
#include "Platforms/Vulkan/VulkanInterface.hpp"

namespace KRHI::Common
{
	Ref<APIInterface> APIInterface::InitAPI(BackendAPI api)
	{ 
		switch (api)
		{
		case BackendAPI::VULKAN:
			return CreateRef<Vulkan::VulkanInterface>();
			break;
		
		default:
			break;
		}
		return nullptr; 
	}
}