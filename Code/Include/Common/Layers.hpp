#pragma once

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"

namespace KRHI::Common
{
	class Instance;

	class Layers : public RefCast<Layers>
	{
	public:
		KRHI_API virtual ~Layers() = default;

		KRHI_API virtual void Create(Instance instance) = 0;
	};
}