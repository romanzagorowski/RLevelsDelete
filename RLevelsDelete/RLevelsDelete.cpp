#include "pch.h"
#include "ScriptInterfaceUnit.h"

#include <format>

using namespace std::string_literals;

static const PChar scriptShortName = "RLevelsDelete";
static const PChar scriptDescription = "Deletes all R levels";

static int maxRLevel = 7;

EXPORT void __stdcall Init()
{
	Print("EXPORT void __stdcall Init()");

	ScriptShortName(scriptShortName);
	ScriptDescription(scriptDescription);

	RegOption("MaxRLevel", ot_Integer, &maxRLevel);
	SetOptionRange("MaxRLevel", -1, 10);
}

EXPORT void __stdcall Done()
{
	Print("EXPORT void __stdcall Done()");
}

EXPORT void __stdcall Execute()
{
	Print("EXPORT void __stdcall Execute()");

	SetCurrencyAndTimeframe("USDCHF", 15);

	for(int i = -1; i <= maxRLevel; ++i)
	{
		const std::string objectName = std::format("RLevel_{}", i);

		if(ObjectExists(objectName))
		{
			Print(
				std::format("INFO: Execute(): The object named '{}' exists.", objectName)
			);

			ObjectDelete(objectName);

			Print(
				std::format("INFO: Execute(): The object named '{}' deleted.", objectName)
			);
		}
		else
		{

			Print(
				std::format("INFO: Execute(): The object named '{}' does not exist.", objectName)
			);
		}
	}
}
