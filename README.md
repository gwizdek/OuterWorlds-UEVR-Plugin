# The Outer Worlds: Spacer's Choice Edition - UEVR Plugin

This is an early version of UEVR profile and it includes a `.dll` plugin. The profile is actively worked on to add some important missing features.

## Important!
This plugin comes in two versions, depending on where you bought the game:
* Epic Game Store
* Steam

**Read installation instructions!**

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
* Weapon materials - caused odd geometrical distortion
* Inventory / Workbench background
* Right eye flicker - more info below

## Controls
The plugin doesn't change any of the game controller bindings but it adds one:
* Hold Left Thumbstick Button for >3s to remove eye flicker
*(more about this option down below)*

## Installation / Configuration
This plugin is meant to be used with UEVR Native Stereo Fix feature and it requires latest nightly to work.
It's also advised to use DLSS *(DLSS installation is described below)*.

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

## DLSS Installation
DLSS Installation is optional, but highly recommended. The DLSS 4 upscaler that uses Transformer Model really shines in this game.
Unfortunatelly TOW doesn't support DLSS out of the box, but there is a way to add it - through a FSR -> DLSS bridge.

*Note: There are many different ways to setup DLSS4. Feel free to do it your way.*

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

    Inside `Clarity and Detail` section set:  
    * NVSharpen Mode: `On`
    * NVSharpen Value: `1.00`

   ![image](https://github.com/user-attachments/assets/c56796fe-dbba-4d7a-b69d-93df5d2870b9)  
    **IMPORTANT:** Press `Apply Changes` button in top right corrner of the application  


5) Optional (recommended) Enable DLSS Onscreen Indicator  
Onscreen indicator will show a text message on your monitor screen when DLSS is in use. We can use it to confirm that we succesfully installed the DLSS Bridge.  
There are two `.reg` files located inside downloaded NVIDIA Profile Inspector Revamped `.zip` file: `Enable DLSS UI.reg` and `Disable DLSS UI.reg`. Use the first one to enable the indicator. 

6) Enable DLSS in the game  
Start the game. Go to Settings and select upscaling level (recommended: Performance) in `FidelityFX Super Resolution 2 (FSR 2)` option. Press `Apply`.  
The game still thinks that is using FSR2, but at this point it should be using DLSS.  
If everything is set up correctly and the Onscreen Indicator is turned on, you should be able to see a text message on your monitor (bottom/left corner).  
![image](https://github.com/user-attachments/assets/45971cdc-d1ff-4681-99c2-0fa95c7367b8)  


## Eye flicker fix
The latest changes made by praydog to UEVR brought better image quality in Native Stereo Rendering Method. This feature is enabled by using `Native Stereo Fix -> Enabled` checkbox. The feature is not perfect yet and in some games it causes side effects.  
In regards to Outer Worlds that side effect is image flickering seen in one of the eyes. This is related to the game engine recalculating lighting conditions for given time of day.  

The issue can be mitigated in two ways:  
* Disable and enable Native Stereo Fix or set rendering method to Synchronized Sequential and back to Native Stereo
* Stop the game from reevaluating lighting conditions  

The first option works only for a short period of time and then you need to do it again  
The second option effectively stops progress of day time

The profile provides both mitigation methods:  
* If you're not using `Pause Daytime` feature and the screen starts to flicker, press and hold `Left Thumbstick Button` for >3s to remove eye flicker
* If you want to test `Pause Daytime` go to the plugin overlay window (an extra window visible next to UEVR overlay window) and press `Pause Daytime` button.
This will pause daytime until you change game location or reload the game (you can wait up to the moment when the lighting conditions suit you and pause daytime then).  
If you like the feature, you can also use use `Auto Pause Daytime on Level Load` option available in plugin overlay.  
Pressing `Save Configuration` button will save the options to hard drive.  
![image](https://github.com/user-attachments/assets/655da1d9-7049-4b55-8da7-981fddb335a2)  


If you want to disable the `Pause Daytime` feature. Uncheck `Auto Pause Daytime on Level Load` and reload the game.

## Missing Features  
Curently, there are two major features missing:
* Melee weapon handling
* Scoped weapon handling


## Credits
praydog for UEVR
