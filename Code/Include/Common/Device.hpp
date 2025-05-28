#pragma once

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"
#include "Utils/Macros.hpp"

namespace KRHI::Common
{
	class Instance;
	class Surface;

	/**
	* @enum DeviceExtensions
	* @brief Enum to abstract the device extensions
	*/
	enum class DeviceExtensions : int
	{
		SWAPCHAIN,							/// Support for presenting rendered images to the screen
		SURFACE,							/// Base surface abstraction (platform-specific variants exist)
		DEBUG_UTILS,						/// Debugging and validation tools
		PORTABILITY_SUBSET,					/// Portability support on non-standard Vulkan implementations

		MAINTENANCE5,						/// Enables improvements in descriptor buffer and pipeline layouts
		MAINTENANCE6,						/// Adds better resource alignment and shader binding control
		MAINTENANCE8,						/// Minor improvements to memory barriers and image operations
		DYNAMIC_RENDERING_LOCAL_READ,		/// Enables reading depth/stencil/multisample attachments during dynamic rendering
		SHADER_SUBGROUP_ROTATE,				/// Allows subgroup rotation operations in shaders
		SHADER_FLOAT_CONTROLS2,				/// Adds additional floating-point control options in shaders
		SHADER_EXPECT_ASSUME,				/// Optimizes shaders by providing compiler assumptions
		LINE_RASTERIZATION,					/// Advanced line rendering modes (rectangular, bresenham, etc.)
		VERTEX_ATTRIBUTE_DIVISOR,			/// Enables per-instance vertex attribute rate control
		INDEX_TYPE_UINT8,					/// Allows use of 8-bit indices in index buffers
		MAP_MEMORY2,						/// Improves memory mapping operations and synchronization
		PUSH_DESCRIPTOR,					/// Allows binding descriptors directly via push commands
		VIDEO_MAINTENANCE2,					/// Enhances support and performance for video encoding/decoding
		PIPELINE_PROTECTED_ACCESS,			/// Adds access control for protected rendering pipelines
		PIPELINE_ROBUSTNESS,				/// Increases error resilience and stability of pipelines
		HOST_IMAGE_COPY,					/// Allows CPU-side image copy operations for faster uploads
		EXTERNAL_MEMORY_METAL,				/// Enables external memory sharing with Apple Metal
	};


	class Device : public RefCast<Device>
	{
	public:
		struct KRHI_API DeviceSpec { std::vector<std::string> requiredExtensions = {}; };
		KRHI_API virtual void Create(const Ref<Instance>& instance, const Ref<Surface>& surface, const DeviceSpec& spec) = 0;
		KRHI_API virtual void Destroy() = 0;
	};
}