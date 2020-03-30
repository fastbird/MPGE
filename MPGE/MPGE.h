#pragma once
#include "stdafx.h"
#include "MPGEResult.h"

namespace fb
{
	enum class RenderAPIName {
		DX12,
		Vulkan,
		Metal,
	};

	struct InitInfo
	{
		const char* ApplicationName = "App_Name";
		uint32_t ApplicationVersion = 0;
		const char* EngineName = "Engine_Name";
		uint32_t EngineVersion = 0;
	};

	class MPGE
	{
	public:
		MPGE_DLL static MPGEResult LastResult;
		MPGE_DLL static MPGE* Initialize(RenderAPIName apiName, InitInfo* initInfo);
		virtual void Finalize() = 0;


		
	};
}