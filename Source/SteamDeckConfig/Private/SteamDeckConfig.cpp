// Copyright Epic Games, Inc. All Rights Reserved.

#include "SteamDeckConfig.h"

#define PLATFORM_STEAMDECK PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_LINUX

#if PLATFORM_STEAMDECK
#include "SteamSharedModule.h"
#include "steam/isteamutils.h"
#endif

#define LOCTEXT_NAMESPACE "FSteamDeckConfigModule"

bool FSteamDeckConfigModule::IsRunningOnSteamDeck()
{
#if PLATFORM_STEAMDECK
	if (!FSteamSharedModule::IsAvailable())
	{
		// Load the module
		FSteamSharedModule::Get();
	}
	
	// Use SteamUtils if it is available
	if (FSteamSharedModule::IsAvailable())
	{
		if (SteamUtils())
		{
			return SteamUtils()->IsSteamRunningOnSteamDeck();
		}
	}

	// SteamUtils() not yet available, often due to the LoadingPhase
	return IsRunningOnSteamDeck_EarlyInit();
#else
	return false;
#endif
}

bool FSteamDeckConfigModule::IsRunningOnSteamDeck_EarlyInit()
{
#if PLATFORM_STEAMDECK
	return FPlatformMisc::GetEnvironmentVariable(TEXT("SteamDeck")).Equals(FString(TEXT("1")));
#else
	return false;
#endif
}

void FSteamDeckConfigModule::StartupModule()
{
#if PLATFORM_STEAMDECK
	// Query the Steam Deck status
	const bool bRunningOnSteamDeck = IsRunningOnSteamDeck_EarlyInit();
	if (bRunningOnSteamDeck)
	{
		TArray<FString> ConfigFiles { TEXT("Engine"), TEXT("Game"), TEXT("Input"), TEXT("DeviceProfiles"), TEXT("Scalability") };
		for (const FString& ConfigFile : ConfigFiles)
		{
			const FString OverrideConfigPath = FPaths::Combine(FPaths::ProjectConfigDir(), "SteamDeck", "SteamDeck" + ConfigFile + ".ini");
			
			FConfigFile* FoundConfig = GConfig->FindConfigFile(ConfigFile);
			FoundConfig->AddDynamicLayerToHierarchy(OverrideConfigPath);

			const FString OverrideConfigPathB = FPaths::Combine(FPaths::ProjectConfigDir(), "SteamDeck", "SteamDeck" + ConfigFile + ".ini");
		}
	}
#endif
}

void FSteamDeckConfigModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

#undef PLATFORM_STEAMDECK

IMPLEMENT_MODULE(FSteamDeckConfigModule, SteamDeckConfig)

