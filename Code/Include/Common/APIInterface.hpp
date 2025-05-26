#pragma once

#include "Common/Instance.hpp"

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"

namespace KRHI::Vulkan
{
	class VulkanInterface;
}

namespace KRHI::Common
{
	enum class BackendAPI : uint8_t
	{
		NONE = 0,
		VULKAN = 1
	};

	class APIInterface
	{
	public:
		KRHI_API static Ref<APIInterface> InitAPI(BackendAPI api);
		KRHI_API virtual ~APIInterface() = default;

		KRHI_API virtual Ref<Instance> InstantiateInstance() = 0;
		KRHI_API virtual void DestroyInstance(Ref<Instance> instance) { instance.reset(); }
	};
}