#include "Common/APIInterface.hpp"

#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{

	class VulkanInterface : public Common::APIInterface
	{
	public:
		KRHI_API ~VulkanInterface() override = default;

		KRHI_API Ref<Common::Instance> InstantiateInstance() override { return CreateRef<VulkanInstance>(); }
	};
}