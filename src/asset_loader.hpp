#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "inttypes.h"

#include "uevr/API.hpp"
#include "indiana/SDK/Engine_classes.hpp"

using namespace uevr;

//using StaticLoadObject_t = SDK::UObject* (*)(uevr::API::UClass* ObjectClass, uevr::API::UObject* InOuter, const wchar_t* inName, const wchar_t* Filename, int32_t LoadFlags, struct UPackageMap* Sandbox, bool bAllowObjectReconciliation, const struct FLinkerInstancingContext* InstancingContext);

class AssetLoader
{
private:
    //uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
    //{
    //    uintptr_t modBaseAddr = 0;
    //    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
    //    if (hSnap != INVALID_HANDLE_VALUE)
    //    {
    //        MODULEENTRY32 modEntry;
    //        modEntry.dwSize = sizeof(modEntry);
    //        if (Module32First(hSnap, &modEntry))
    //        {
    //            do
    //            {
    //                if (!_wcsicmp(modEntry.szModule, modName))
    //                {
    //                    modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
    //                    break;
    //                }
    //            } while (Module32Next(hSnap, &modEntry));
    //        }
    //    }
    //    CloseHandle(hSnap);
    //    return modBaseAddr;
    //}

    //static StaticLoadObject_t m_load_asset_fn_address;


public:
    AssetLoader() = default;
    virtual ~AssetLoader() {};
    

    static void init() {
        //m_load_asset_fn_address = (StaticLoadObject_t)0x7ff7e9277740;
        //m_load_asset_fn_address = (StaticLoadObject_t)(0x1C67740 + base_address);
    }

    //COREUOBJECT_API UObject* StaticLoadObject                                     (UClass* Class, UObject* InOuter, const TCHAR* Name, const TCHAR* Filename = nullptr, uint32 LoadFlags = LOAD_None, UPackageMap* Sandbox = nullptr, bool bAllowObjectReconciliation = true, const FLinkerInstancingContext* InstancingContext = nullptr);

    //L"Class /Script/Engine.ParticleSystem"
    //L"/Game/Art/VFX/ParticleSystems/Weapons/Projectiles/Plasma/PS_Plasma_Ball.PS_Plasma_Ball"

    static SDK::UObject* load_asset(std::wstring class_name, std::wstring resource_name) {
        //0x7ff7e9277740
        //0x7FF7E7610000
        //     0x1C67740
        auto asset_class = API::get()->find_uobject<API::UClass>(class_name);

        if (!asset_class) {
            API::get()->log_warn("Failed to find StaticMesh class");
            return;
        }
       
        API::get()->log_warn("Calling function");
        //SDK::UObject* asset = m_load_asset_fn_address(asset_class, nullptr, resource_name.c_str(), nullptr, 0, nullptr, true, nullptr);
        //if (!asset) {
        //    API::get()->log_warn("Failed to load Plasma Ball");
        //    return;
        //}
        //if (asset->IsA(SDK::UParticleSystem::StaticClass())) {
        //    API::get()->log_warn("Loaded Plasma Ball");
        //}
        //else {
        //    API::get()->log_warn("Loaded Something...");
        //}
    }

};
