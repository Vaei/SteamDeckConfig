﻿// Copyright (c) 2025 Jared Taylor

using UnrealBuildTool;

public class SteamDeckConfig : ModuleRules
{
	public SteamDeckConfig(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
			}
			);

		if (Target.Platform == UnrealTargetPlatform.Win64 || 
		    Target.Platform == UnrealTargetPlatform.Linux ||
		    Target.Platform == UnrealTargetPlatform.Mac)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"SteamShared", 
					"Steamworks",
				}
			);
		}
	}
}
