#include "../MPGE/MPGE.h"

#define VK_MAKE_VERSION(major, minor, patch) \
    (((major) << 22) | ((minor) << 12) | (patch))

using namespace fb;
int main()
{
	InitInfo info;
	info.ApplicationName = "MPGETestApp";
	info.ApplicationVersion = VK_MAKE_VERSION(0, 0, 0);
	info.EngineName = "MPGE";
	info.EngineVersion = VK_MAKE_VERSION(0, 0, 0);
	auto mpge = MPGE::Initialize(RenderAPIName::Vulkan, &info);
	int a = 0;
	++a;

	return 0;
}