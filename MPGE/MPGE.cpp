#include "stdafx.h"
#include "MPGE.h"

namespace fb
{
	MPGE_DLL MPGEResult MPGE::LastResult;

	MPGE* InitDX12()
	{
#if defined(_MSC_VER)
		// Load MPGE_DX12.dll
		auto dx12 = LoadLibrary(L"MPGE_DX12.dll");
		if (!dx12) {
			MPGE::LastResult = MPGEResult::ModuleNotFound;
			fprintf(stderr, "MPGE_DX12.dll not found.\n");
			return nullptr;
		}
		typedef MPGE* (*InitializeProc)(MPGEResult*);
		InitializeProc Initialize = (InitializeProc)GetProcAddress(dx12, "Initialize");
		if (!Initialize) {
			MPGE::LastResult = MPGEResult::ModuleEntryPointNotFound;
			fprintf(stderr, "Module entry point function not found.\n");
			return nullptr;
		}
		return Initialize(&MPGE::LastResult);		
#else
		MPGE::LastResult = MPGEResult::PlatformError;
		fprintf(stderr, "Invalid platform.\n");
		return nullptr;
#endif
	}

	MPGE* InitVulkan()
	{
#if defined(_MSC_VER)
		// Load MPGE_Vulkan.dll
		auto vulkan = LoadLibrary(L"MPGE_Vulkan.dll");
		if (!vulkan) {
			MPGE::LastResult = MPGEResult::ModuleNotFound;
			fprintf(stderr, "MPGE_Vulkan.dll not found.\n");
			return nullptr;
		}
		typedef MPGE* (*InitializeProc)(MPGEResult*);
		InitializeProc Initialize = (InitializeProc)GetProcAddress(vulkan, "Initialize");
		if (!Initialize) {
			MPGE::LastResult = MPGEResult::ModuleEntryPointNotFound;
			fprintf(stderr, "Module entry point function not found.\n");
			return nullptr;
		}
		return Initialize(&MPGE::LastResult);
#else
		// TODO: Mac, Android, iOS
		MPGE::LastResult = MPGEResult::PlatformError;
		fprintf(stderr, "Invalid platform.\n");
		return nullptr;
#endif
	}

	MPGE* InitMetal()
	{
		// TODO : Metal API
		return nullptr;
	}

	MPGE_DLL MPGE* MPGE::Initialize(GraphicAPIName apiName)
	{
		switch (apiName) {
		case GraphicAPIName::DX12:
			return InitDX12();
		case GraphicAPIName::Vulkan:
			return InitVulkan();
		case GraphicAPIName::Metal:
			return InitMetal();
		}
		fprintf(stderr, "Invaild API Name.\n");
		return nullptr;
	}
}