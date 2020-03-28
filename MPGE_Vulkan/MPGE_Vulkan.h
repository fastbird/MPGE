#pragma once
#include "../MPGE/MPGE.h"

extern "C" {
	MPGE_VULKAN_DLL fb::MPGE* Initialize(fb::MPGEResult* ret);
}

namespace fb
{
	class MPGEVulkan : public MPGE
	{
		MPGEVulkan();
		~MPGEVulkan();

		MPGEResult LastResult = MPGEResult::Success;

	public:
		static MPGEVulkan* Initialize(fb::MPGEResult* ret);
		void Finalize() override;

		void CreateInstance();
		
		
	};
}