// Copyright Epic Games, Inc. All Rights Reserved.

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
