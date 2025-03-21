#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BackgroundPanelWidget

#include "Basic.hpp"


namespace SDK::Params
{

// Function BackgroundPanelWidget.BackgroundPanelWidget_C.ExecuteUbergraph_BackgroundPanelWidget
// 0x0028 (0x0028 - 0x0000)
struct BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UTexture2D*                             K2Node_Event_Texture;                              // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UTexture2D*                             K2Node_Event_Texture_1;                            // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_Event_bFocused;                             // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget) == 0x000008, "Wrong alignment on BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget");
static_assert(sizeof(BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget) == 0x000028, "Wrong size on BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget");
static_assert(offsetof(BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget, EntryPoint) == 0x000000, "Member 'BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget::EntryPoint' has a wrong offset!");
static_assert(offsetof(BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget, K2Node_Event_Texture) == 0x000008, "Member 'BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget::K2Node_Event_Texture' has a wrong offset!");
static_assert(offsetof(BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget, CallFunc_IsValid_ReturnValue) == 0x000010, "Member 'BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget, K2Node_Event_Texture_1) == 0x000018, "Member 'BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget::K2Node_Event_Texture_1' has a wrong offset!");
static_assert(offsetof(BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget, CallFunc_IsValid_ReturnValue_1) == 0x000020, "Member 'BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget, K2Node_Event_bFocused) == 0x000021, "Member 'BackgroundPanelWidget_C_ExecuteUbergraph_BackgroundPanelWidget::K2Node_Event_bFocused' has a wrong offset!");

// Function BackgroundPanelWidget.BackgroundPanelWidget_C.OnOuterTextureLoaded
// 0x0008 (0x0008 - 0x0000)
struct BackgroundPanelWidget_C_OnOuterTextureLoaded final
{
public:
	class UTexture2D*                             Texture;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BackgroundPanelWidget_C_OnOuterTextureLoaded) == 0x000008, "Wrong alignment on BackgroundPanelWidget_C_OnOuterTextureLoaded");
static_assert(sizeof(BackgroundPanelWidget_C_OnOuterTextureLoaded) == 0x000008, "Wrong size on BackgroundPanelWidget_C_OnOuterTextureLoaded");
static_assert(offsetof(BackgroundPanelWidget_C_OnOuterTextureLoaded, Texture) == 0x000000, "Member 'BackgroundPanelWidget_C_OnOuterTextureLoaded::Texture' has a wrong offset!");

// Function BackgroundPanelWidget.BackgroundPanelWidget_C.OnInnerTextureLoaded
// 0x0008 (0x0008 - 0x0000)
struct BackgroundPanelWidget_C_OnInnerTextureLoaded final
{
public:
	class UTexture2D*                             Texture;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BackgroundPanelWidget_C_OnInnerTextureLoaded) == 0x000008, "Wrong alignment on BackgroundPanelWidget_C_OnInnerTextureLoaded");
static_assert(sizeof(BackgroundPanelWidget_C_OnInnerTextureLoaded) == 0x000008, "Wrong size on BackgroundPanelWidget_C_OnInnerTextureLoaded");
static_assert(offsetof(BackgroundPanelWidget_C_OnInnerTextureLoaded, Texture) == 0x000000, "Member 'BackgroundPanelWidget_C_OnInnerTextureLoaded::Texture' has a wrong offset!");

// Function BackgroundPanelWidget.BackgroundPanelWidget_C.SetBackgroundFocused
// 0x0001 (0x0001 - 0x0000)
struct BackgroundPanelWidget_C_SetBackgroundFocused final
{
public:
	bool                                          bFocused;                                          // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BackgroundPanelWidget_C_SetBackgroundFocused) == 0x000001, "Wrong alignment on BackgroundPanelWidget_C_SetBackgroundFocused");
static_assert(sizeof(BackgroundPanelWidget_C_SetBackgroundFocused) == 0x000001, "Wrong size on BackgroundPanelWidget_C_SetBackgroundFocused");
static_assert(offsetof(BackgroundPanelWidget_C_SetBackgroundFocused, bFocused) == 0x000000, "Member 'BackgroundPanelWidget_C_SetBackgroundFocused::bFocused' has a wrong offset!");

}

