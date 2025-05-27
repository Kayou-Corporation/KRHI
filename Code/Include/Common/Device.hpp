#pragma once

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"
#include "Utils/Macros.hpp"

namespace KRHI::Common
{
	class Instance;
	class Surface;

	class Device : public RefCast<Device>
	{
	public:
		KRHI_API virtual void Create(Ref<Instance> instance, Ref<Surface> surface) = 0;
		KRHI_API virtual void Destroy() = 0;
	};
}