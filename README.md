# The Outer Worlds: Spacer's Choice Edition - UEVR Plugin

> [!WARNING]
> This plugin comes in two versions, depending on where you bought the game:
> * Epic Game Store
> * Steam (should work on GOG too)
>   
> **Please Read installation instructions!**

## Features
* 6DOF guns
* Interaction Pointer - Red Dot
* HUD elements attached to player's wrists:
    * Left hand
        * Character Overview
        * Compass
    * Right hand
        * Ammo Readout
        * Item Degradation Indicator

## Fixes
* Conversation camera
* Computer Terminal camera
* Weapon materials - fixed weird geometrical distortion
* Inventory / Workbench background
* Flicker Fixer - more info below

## Mod Overlay
This profile comes with it's own overlay. The overlay is accesible by using regular mouse, so it's best to sit down at your desk with running HMD and do the adjustments before playing standed.  
Press `Save Configuration` button to store your settings.  

- Built-in Flicker Fixer  
![image](https://github.com/user-attachments/assets/e53caffa-a18c-4eb6-93b1-933c6ff8fd9e)  
_Running Flicker Fixer costs some performance. This is why it's turned on only for a brief moment._
In the screenshot above: Every 10 seconds for 0.15 of a second.
If the Flicker Fixer is not working, try increasing `Active Duration`

- Hand attachments.
The four attachments can be moved, rotated and scaled to your liking.
![image](https://github.com/user-attachments/assets/8177e7ee-2adf-40b0-8c31-b957af6aece5)  

## Installation / Configuration
This plugin is meant to be used with UEVR Native Stereo Fix feature and it requires latest nightly to work.
It's also advised to use DLSS  
*(DLSS installation is described below)*.

1) Get and Install UEVR nightly from [**HERE**](https://github.com/praydog/UEVR-nightly/releases).  
    *(I'm running it with nightly 1042, but some say, it's not the most stable version and preffer 1040)*
2) Remove your current Outer Worlds profile folder if exists:
    * Epic: `C:\Users\{username}\AppData\Roaming\UnrealVRMod\IndianaEpicGameStore-Win64-Shipping`
    * Steam: `C:\Users\{username}\AppData\Roaming\UnrealVRMod\Indiana-Win64-Shipping`
3) Download the latest release of the Outer Worlds plugin from Releases page: [**link**](https://github.com/gwizdek/OuterWorlds-UEVR-Plugin/releases)

    **Be sure to download correct file depending on the game version you use:**
    * Epic: `IndianaEpicGameStore-Win64-Shipping.zip`
    * Steam: `Indiana-Win64-Shipping.zip`

4) Open UEVR Frontend Application. Click "Import Config" and select the `.zip` file you downloaded. Accept the DLL warning.
5) Launch The Outer Worlds: Spacer's Choice Edition and inject the game with UEVR
6) Open `Game Settings -> UI -> HUD section`, and set `Aiming Reticle` option to `OFF` - you won't need the reticle anymore
7) If you're using DLSS bridge, be sure to set `Screen Effects` to Medium or above in the graphics options.

## DLSS Installation
DLSS Installation is optional, but highly recommended. The DLSS 4 upscaler that uses Transformer Model really shines in this game.
Unfortunatelly TOW doesn't support DLSS out of the box, but there is a way to add it - through a FSR -> DLSS bridge.

> [!WARNING]
> For the DLSS to work, you need `Screen Effects` to be set to Medium or above in the graphics options.

> [!NOTE]
> There are many different ways to setup DLSS4. Feel free to do it your way.

1) Download FSR2 Bridge  
Go to Nexus Mods and download `FSRBridge - DLSS` [**link**](https://www.nexusmods.com/starfield/mods/196?tab=files).  
Unpack it into `..\TOWSpacersChoice\Indiana\Binaries\Win64\` folder.  
*(this is Epic store forlder location, but it should be similar for Steam)*

2) Download DLSS DLL  
Go to TechPowerUp and download the `nvngx_dlss_310.2.zip` file [**link**](https://www.techpowerup.com/download/nvidia-dlss-dll/)  
Unpack it into `..\TOWSpacersChoice\Indiana\Binaries\Win64\` folder.

3) Use NVIDIA Profile Inspector Revamped to override DLSS settings
    * Download latest release from [**here**](https://github.com/xHybred/NvidiaProfileInspectorRevamped/releases)  
    * Unpack and Run `NV-Profile-Inspector-Revamped Lite\nvidiaProfileInspector.exe` file.  
    * Select Global Profile: `_GLOBAL_DRIVER_PROFILE (Base Profile)`  

    Inside `DLSS Overrides` section set:  
    * SR: Latest DLL: `On`
    * SR: Preset: `J`  
    (*preset `J` is the sharpest one*)

   ![image](https://github.com/user-attachments/assets/d09ce57b-8b5e-4913-8b58-dc6693749ad9)  

    **IMPORTANT:** Press `Apply Changes` button in top right corrner of the application  


5) Optional (recommended) Enable DLSS Onscreen Indicator  
Onscreen indicator will show a text message on your monitor screen when DLSS is in use. We can use it to confirm that we succesfully installed the DLSS Bridge.  
There are two `.reg` files located inside downloaded NVIDIA Profile Inspector Revamped `.zip` file: `Enable DLSS UI.reg` and `Disable DLSS UI.reg`. Use the first one to enable the indicator. 

6) Enable DLSS in the game  
Start the game. Go to Settings and select upscaling level (recommended: Performance) in `FidelityFX Super Resolution 2 (FSR 2)` option. 
Then, select `Screen Effects: Medium` or above.  
Press `Apply`.  

The game still thinks that is using FSR2, but at this point it should be using DLSS.  
If everything is set up correctly and the Onscreen Indicator is turned on, you should be able to see a text message on your monitor (bottom/left corner).  
![image](https://github.com/user-attachments/assets/45971cdc-d1ff-4681-99c2-0fa95c7367b8)  


## CVars
Here are some CVars you may want to experiment with. These can help with object shadows glitches and uneven lighting. Adding these to `user_script.txt` will cost some performance.  
If you're playing with low graphics settings then these CVars can have no visible effect, so consider using UEVR's built-in console to check how they work first, before adding them to the `user_script.txt` file.  
```
r.DistanceFieldShadowing 0
r.AOGlobalDistanceFieldPartialUpdates 0
```

## Missing Features  
Curently, there are two major features missing:
* Melee weapon handling
* Scoped weapon handling

## Troubleshooting
### 1. Game crashes right after injecting UEVR
Open `config.txt` file located in game's UEVR profile folder and edit these values:
```
OpenXR_ResolutionScale=1.000000
VR_NativeStereoFix=true
```
Save and try injecting UEVR again.

### 2. Game crashes when taking elevator to Back Bays (on the Groundbreaker)
This is a known issue with version 0.1.0 (fixed in 0.2.0).


## Credits
praydog for UEVR
