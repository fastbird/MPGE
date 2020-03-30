#pragma once
#include "../MPGE/MPGE.h"

extern "C" {
	MPGE_VULKAN_DLL fb::MPGE* Initialize(fb::MPGEResult* ret, fb::InitInfo* initInfo);
}

namespace fb
{
	class MPGEVulkan : public MPGE
	{
		MPGEVulkan(InitInfo* initInfo);
		~MPGEVulkan();

		MPGEResult LastResult = MPGEResult::Success;

	public:
		static MPGEVulkan* Initialize(InitInfo* initInfo);
		void Finalize() override;

		void CreateInstance(InitInfo* initInfo);
		MPGEResult GetLastResult() const { return LastResult; }

		// public functions end

	private:
		bool IsSupportedLayer(const char* layerName) const;

		
		
	};
}