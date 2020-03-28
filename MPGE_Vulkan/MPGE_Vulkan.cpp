#include "stdafx.h"
#include "MPGE_Vulkan.h"

extern "C" {
	fb::MPGE* Initialize(fb::MPGEResult* ret)
	{
		return fb::MPGEVulkan::Initialize(ret);
	}
}

namespace fb {
	MPGEVulkan* MPGEVulkan::Initialize(fb::MPGEResult* ret)
	{
		auto vul = new MPGEVulkan();
		return vul;
	}

	void MPGEVulkan::Finalize()
	{
		delete this;
	}

	MPGEVulkan::MPGEVulkan()
	{
		CreateInstance();
	}

	MPGEVulkan::~MPGEVulkan()
	{

	}

	void MPGEVulkan::CreateInstance()
	{
		PFN_vkCreateInstance vkCreateInstance = (PFN_vkCreateInstance)vkGetInstanceProcAddr(nullptr, "vkCreateInstance");
		if (!vkCreateInstance)
		{
			LastResult = MPGEResult::FunctionNotFound;
			fprintf(stderr, "vkCreateInstance() not found.\n");
			return;
		}
		vk::InstanceCreateInfo createInfo;
		//vkCreateInstance();
		LastResult = MPGEResult::Success;
	}
}