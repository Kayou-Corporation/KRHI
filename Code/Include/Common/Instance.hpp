#pragma once

#include <vector>

#include "Utils/Export.hpp"
#include "Utils/Memory.hpp"
#include "Utils/Macros.hpp"

namespace KRHI::Common
{
	/**
	* @file Instance.hpp
	* @brief Common implementation of API instance and all required data and basic abstraction
	*/
	
	/**
	* @class Version
	* @brief Structure to define version of the application and of the engine
	*/
	struct Version
	{
		int major;
		int minor;
		int patch;
	};

	/**
	* @enum ValidationLayers
	* @brief Enum to abstract the more important validation layers
	*/
	enum class ValidationLayers : int
	{
		VALIDATION = 0, /// Most basic layer, regroup all of the checks
		MONITOR = 1, /// Check all API call
		DUMP = 2, /// Generate a .txt file with every API call 
		SIMULATION = 3, /// Enable the possibility to simulate certain extensions not natively supoorted by the GPU
		DEBUG = 4 /// Enable the possibility to capture all of the API call
	};

	/**
	* @class InstanceSpec
	* @brief structure to hold all instance creation specification
	* @param extensions The extensions provide by the surface (GLFW | SDL | etc...)
	* @param layers The abstact layers provide by the user, will the override into the API implementation of the class (Vulkan, DX12)
	* @param appName The application name
	* @param appVersion The application version
	* @param engineName The engine name
	* @param engineVersion The engine version
	*/
	struct InstanceSpec
	{
		std::vector<const char*> extensions;
		std::vector<Common::ValidationLayers> layers; 
		std::string appName; 
		Version appVersion;
		std::string engineName; 
		Version engineVersion;
	};

	/**
	* @class Instance
	* @brief Common implementation of API instance
	*/
	class Instance : public RefCast<Instance> 
	{
	public:
		KRHI_API virtual ~Instance() = default;

		/**
		* @brief Abstact version of the create function of the class
		*/
		KRHI_API virtual void Create(const InstanceSpec& spec) = 0;

		/**
		* @brief Abstact version of the destroy function of the class
		*/
		KRHI_API virtual void Destroy() = 0;

		/**
		* @brief Abstact version of the extensions getter
		*/
		KRHI_API FORCE_INLINE virtual std::vector<const char*>& GetExtensions() = 0;
	};
}