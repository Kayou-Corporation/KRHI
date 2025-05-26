#include "Common/APIInterface.hpp"
#include "Platforms/Vulkan/VulkanInterface.hpp"

namespace KRHI::Common
{
	Ref<APIInterface> APIInterface::InitAPI(BackendAPI api)
	{ 
		if (api == Common::BackendAPI::VULKAN)
		{
			return CreateRef<Vulkan::VulkanInterface>();
		}
		return nullptr; 
	}
}