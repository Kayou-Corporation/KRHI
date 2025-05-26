#include "Common/APIInterface.hpp"

#include "Platforms/Vulkan/VulkanInstance.hpp"

namespace KRHI::Vulkan
{

	class VulkanInterface : public Common::APIInterface
	{
	public:
		//KRHI_API static Ref<Common::APIInterface> Init(Common::BackendAPI api) { if (api == Common::BackendAPI::VULKAN) return CreateRef<Vulkan::VulkanInterface>(); return nullptr; }
		KRHI_API ~VulkanInterface() override = default;

		KRHI_API Ref<Common::Instance> InstantiateInstance() override { return CreateRef<VulkanInstance>(); }
		KRHI_API void DestroyInstance(Ref<Common::Instance> instance) override { instance.reset(); }
	};
}