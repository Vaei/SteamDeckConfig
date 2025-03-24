// Copyright (c) 2025 Jared Taylor

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSteamDeckConfigModule : public IModuleInterface
{
public:
	STEAMDECKCONFIG_API static bool IsRunningOnSteamDeck();
	STEAMDECKCONFIG_API static bool IsRunningOnSteamDeck_EarlyInit();

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
