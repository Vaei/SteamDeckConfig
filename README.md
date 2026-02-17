> [!IMPORTANT]
> Makes SteamDeck into it's own platform for Config .ini file purposes

Provides `static bool FSteamDeckConfigModule::IsRunningOnSteamDeck()`

# How to Use

Add to Project `.Build.cs`

```cpp
if (Target.Platform == UnrealTargetPlatform.Win64 || 
    Target.Platform == UnrealTargetPlatform.Linux ||
    Target.Platform == UnrealTargetPlatform.Mac)
{
	PrivateDependencyModuleNames.AddRange(
		new string[]
		{
			"SteamDeckConfig",
			"Steamworks",
		}
	);
}
```

Enable the plugin in `.uproject`

Add `<YourProject>/Config/SteamDeck` config files - [You can download these as a starting point](https://drive.google.com/file/d/1rCfxz-fz3Tu1v61X-yusiK8McTzt0GPO/view?usp=sharing)

If using the provided files, modify `SteamDeckEngine.ini` and replace `ipAddr`, `Name`, `UserName`, `Password` with the specific settings for your own device -- these are just placholders.

That's it.

## Changelog

### 1.0.1
* Fix crash

### 1.0.0
* Initial Release