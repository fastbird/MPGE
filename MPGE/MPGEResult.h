#pragma once
namespace fb
{
	enum class MPGEResult
	{
		Success = 0,

		ModuleNotFound = -1,
		FunctionNotFound = -2,
		GeneralError = -3,
		PlatformError = -4,
		ModuleEntryPointNotFound = -5,
		InvalidParameter = -6,
	} ;
}