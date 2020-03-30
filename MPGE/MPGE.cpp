#include "stdafx.h"
#include "MPGE.h"

namespace fb
{
	MPGE_DLL MPGEResult MPGE::LastResult;

	MPGE* InitDX12(InitInfo* initInfo)
	{
#if defined(_MSC_VER)
		// Load MPGE_DX12.dll
		auto dx12 = LoadLibrary(L"MPGE_DX12.dll");
		if (!dx12) {
			MPGE::LastResult = MPGEResult::ModuleNotFound;
			fprintf(stderr, "MPGE_DX12.dll not found.\n");
			return nullptr;
		}
		typedef MPGE* (*InitializeProc)(MPGEResult*, InitInfo*);
		InitializeProc Initialize = (InitializeProc)GetProcAddress(dx12, "Initialize");
		if (!Initialize) {
			MPGE::LastResult = MPGEResult::ModuleEntryPointNotFound;
			fprintf(stderr, "Module entry point function not found.\n");
			return nullptr;
		}
		return Initialize(&MPGE::LastResult, initInfo);		
#else
		MPGE::LastResult = MPGEResult::PlatformError;
		fprintf(stderr, "Invalid platform.\n");
		return nullptr;
#endif
	}

	MPGE* InitVulkan(InitInfo* initInfo)
	{
#if defined(_MSC_VER)
		// Load MPGE_Vulkan.dll
		auto vulkan = LoadLibrary(L"MPGE_Vulkan.dll");
		if (!vulkan) {
			MPGE::LastResult = MPGEResult::ModuleNotFound;
			fprintf(stderr, "MPGE_Vulkan.dll not found.\n");
			return nullptr;
		}
		typedef MPGE* (*InitializeProc)(MPGEResult*, InitInfo*);
		InitializeProc Initialize = (InitializeProc)GetProcAddress(vulkan, "Initialize");
		if (!Initialize) {
			MPGE::LastResult = MPGEResult::ModuleEntryPointNotFound;
			fprintf(stderr, "Module entry point function not found.\n");
			return nullptr;
		}
		return Initialize(&MPGE::LastResult, initInfo);
#else
		// TODO: Mac, Android, iOS
		MPGE::LastResult = MPGEResult::PlatformError;
		fprintf(stderr, "Invalid platform.\n");
		return nullptr;
#endif
	}

	MPGE* InitMetal(InitInfo* initInfo)
	{
		// TODO : Metal API
		return nullptr;
	}

	MPGE_DLL MPGE* MPGE::Initialize(RenderAPIName apiName, InitInfo* initInfo)
	{
		if (!initInfo) {
			LastResult = MPGEResult::InvalidParameter;
			fprintf(stderr, "'initInfo' must not be null.\n");
			return nullptr;
		}
		switch (apiName) {
		case RenderAPIName::DX12:
			return InitDX12(initInfo);
		case RenderAPIName::Vulkan:
			return InitVulkan(initInfo);
		case RenderAPIName::Metal:
			return InitMetal(initInfo);
		}
		LastResult = MPGEResult::InvalidParameter;
		fprintf(stderr, "Invaild API Name.\n");
		return nullptr;
	}
}