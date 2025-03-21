#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OEIValidation

#include "Basic.hpp"


namespace SDK
{

// Enum OEIValidation.EValidationLevel
// NumValues: 0x0005
enum class EValidationLevel : uint8
{
	CriticalError                            = 0,
	Error                                    = 1,
	Warning                                  = 2,
	Info                                     = 3,
	EValidationLevel_MAX                     = 4,
};

// ScriptStruct OEIValidation.ValidationInfo
// 0x00E0 (0x00E0 - 0x0000)
struct FValidationInfo final
{
public:
	class UObject*                                ValidationObject;                                  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ObjectName;                                        // 0x0008(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 ObjectType;                                        // 0x0018(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Filename;                                          // 0x0028(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 PackagePath;                                       // 0x0038(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          TestResult;                                        // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_49[0x7];                                       // 0x0049(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 Message;                                           // 0x0050(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EValidationLevel                              Level;                                             // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_61[0x7];                                       // 0x0061(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 ReportType;                                        // 0x0068(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class FString>                         Tags;                                              // 0x0078(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
	class FString                                 OeiLinkEditor;                                     // 0x0088(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 OeiLinkGame;                                       // 0x0098(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 LastModifiedBy;                                    // 0x00A8(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FString                                 Version;                                           // 0x00B8(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          WiP;                                               // 0x00C8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_C9[0x7];                                       // 0x00C9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 Tool;                                              // 0x00D0(0x0010)(ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(FValidationInfo) == 0x000008, "Wrong alignment on FValidationInfo");
static_assert(sizeof(FValidationInfo) == 0x0000E0, "Wrong size on FValidationInfo");
static_assert(offsetof(FValidationInfo, ValidationObject) == 0x000000, "Member 'FValidationInfo::ValidationObject' has a wrong offset!");
static_assert(offsetof(FValidationInfo, ObjectName) == 0x000008, "Member 'FValidationInfo::ObjectName' has a wrong offset!");
static_assert(offsetof(FValidationInfo, ObjectType) == 0x000018, "Member 'FValidationInfo::ObjectType' has a wrong offset!");
static_assert(offsetof(FValidationInfo, Filename) == 0x000028, "Member 'FValidationInfo::Filename' has a wrong offset!");
static_assert(offsetof(FValidationInfo, PackagePath) == 0x000038, "Member 'FValidationInfo::PackagePath' has a wrong offset!");
static_assert(offsetof(FValidationInfo, TestResult) == 0x000048, "Member 'FValidationInfo::TestResult' has a wrong offset!");
static_assert(offsetof(FValidationInfo, Message) == 0x000050, "Member 'FValidationInfo::Message' has a wrong offset!");
static_assert(offsetof(FValidationInfo, Level) == 0x000060, "Member 'FValidationInfo::Level' has a wrong offset!");
static_assert(offsetof(FValidationInfo, ReportType) == 0x000068, "Member 'FValidationInfo::ReportType' has a wrong offset!");
static_assert(offsetof(FValidationInfo, Tags) == 0x000078, "Member 'FValidationInfo::Tags' has a wrong offset!");
static_assert(offsetof(FValidationInfo, OeiLinkEditor) == 0x000088, "Member 'FValidationInfo::OeiLinkEditor' has a wrong offset!");
static_assert(offsetof(FValidationInfo, OeiLinkGame) == 0x000098, "Member 'FValidationInfo::OeiLinkGame' has a wrong offset!");
static_assert(offsetof(FValidationInfo, LastModifiedBy) == 0x0000A8, "Member 'FValidationInfo::LastModifiedBy' has a wrong offset!");
static_assert(offsetof(FValidationInfo, Version) == 0x0000B8, "Member 'FValidationInfo::Version' has a wrong offset!");
static_assert(offsetof(FValidationInfo, WiP) == 0x0000C8, "Member 'FValidationInfo::WiP' has a wrong offset!");
static_assert(offsetof(FValidationInfo, Tool) == 0x0000D0, "Member 'FValidationInfo::Tool' has a wrong offset!");

}

