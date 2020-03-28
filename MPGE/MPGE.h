#pragma once
#include "stdafx.h"
#include "MPGEResult.h"

namespace fb
{
	enum class GraphicAPIName {
		DX12,
		Vulkan,
		Metal,
	};

	class MPGE
	{
	public:
		MPGE_DLL static MPGEResult LastResult;
		MPGE_DLL static MPGE* Initialize(GraphicAPIName apiName);
		virtual void Finalize() = 0;


		
	};
}