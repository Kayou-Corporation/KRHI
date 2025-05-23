#pragma once

#include <vector>

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"
#include "Utils/Macros.hpp"

namespace KRHI::Vulkan
{
	class VulkanInstance;
}

namespace KRHI::Common
{
	struct Version
	{
		int major;
		int minor;
		int patch;
	};

	class Instance : public RefCast<Instance> 
	{
	public:
		KRHI_API virtual ~Instance() = default;

		KRHI_API virtual void Create(std::vector<const char*> extensions, const std::string& appName, const Version& appVersion,  const std::string& engineName, const Version& engineVersion) = 0;
		KRHI_API virtual void Destroy() = 0;

		KRHI_API FORCE_INLINE virtual std::vector<const char*>& GetExtensions() = 0;
	};
}