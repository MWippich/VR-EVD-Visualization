﻿#include "pch-c.h"
#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include "codegen/il2cpp-codegen-metadata.h"





#if IL2CPP_MONO_DEBUGGER
static const Il2CppMethodExecutionContextInfo g_methodExecutionContextInfos[5] = 
{
	{ 10555, 0,  1 } /*tableIndex: 0 */,
	{ 14009, 1,  1 } /*tableIndex: 1 */,
	{ 10555, 2,  1 } /*tableIndex: 2 */,
	{ 14009, 3,  1 } /*tableIndex: 3 */,
	{ 6589, 4,  1 } /*tableIndex: 4 */,
};
#else
static const Il2CppMethodExecutionContextInfo g_methodExecutionContextInfos[1] = { { 0, 0, 0 } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const char* g_methodExecutionContextInfoStrings[5] = 
{
	"ptr1",
	"size1",
	"ptr2",
	"size2",
	"data",
};
#else
static const char* g_methodExecutionContextInfoStrings[1] = { NULL };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppMethodExecutionContextInfoIndex g_methodExecutionContextInfoIndexes[8] = 
{
	{ 0, 0 } /* 0x06000001 System.IntPtr UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::HookGetInstanceProcAddr(System.IntPtr) */,
	{ 0, 5 } /* 0x06000002 System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::RecvMsg(UnityEngine.Networking.PlayerConnection.MessageEventArgs) */,
	{ 0, 0 } /* 0x06000003 System.IntPtr UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::Native_HookGetInstanceProcAddr(System.IntPtr,System.UInt32,System.UInt32) */,
	{ 0, 0 } /* 0x06000004 System.Boolean UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::Native_GetDataForRead(System.IntPtr&,System.UInt32&) */,
	{ 0, 0 } /* 0x06000005 System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::Native_StartDataAccess() */,
	{ 0, 0 } /* 0x06000006 System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::Native_EndDataAccess() */,
	{ 0, 0 } /* 0x06000007 System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::.ctor() */,
	{ 0, 0 } /* 0x06000008 System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::.cctor() */,
};
#else
static const Il2CppMethodExecutionContextInfoIndex g_methodExecutionContextInfoIndexes[1] = { { 0, 0} };
#endif
#if IL2CPP_MONO_DEBUGGER
IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnity_XR_OpenXR_Features_RuntimeDebugger[];
Il2CppSequencePoint g_sequencePointsUnity_XR_OpenXR_Features_RuntimeDebugger[47] = 
{
	{ 45215, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 0 } /* seqPointIndex: 0 */,
	{ 45215, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 1 } /* seqPointIndex: 1 */,
	{ 45215, 1, 43, 43, 9, 10, 0, kSequencePointKind_Normal, 0, 2 } /* seqPointIndex: 2 */,
	{ 45215, 1, 45, 45, 13, 95, 1, kSequencePointKind_Normal, 0, 3 } /* seqPointIndex: 3 */,
	{ 45215, 1, 45, 45, 13, 95, 1, kSequencePointKind_StepOut, 0, 4 } /* seqPointIndex: 4 */,
	{ 45215, 1, 45, 45, 13, 95, 18, kSequencePointKind_StepOut, 0, 5 } /* seqPointIndex: 5 */,
	{ 45215, 1, 45, 45, 13, 95, 23, kSequencePointKind_StepOut, 0, 6 } /* seqPointIndex: 6 */,
	{ 45215, 1, 49, 49, 13, 38, 29, kSequencePointKind_Normal, 0, 7 } /* seqPointIndex: 7 */,
	{ 45215, 1, 49, 49, 13, 38, 29, kSequencePointKind_StepOut, 0, 8 } /* seqPointIndex: 8 */,
	{ 45215, 1, 50, 50, 13, 36, 35, kSequencePointKind_Normal, 0, 9 } /* seqPointIndex: 9 */,
	{ 45215, 1, 50, 50, 13, 36, 35, kSequencePointKind_StepOut, 0, 10 } /* seqPointIndex: 10 */,
	{ 45215, 1, 52, 52, 13, 88, 41, kSequencePointKind_Normal, 0, 11 } /* seqPointIndex: 11 */,
	{ 45215, 1, 52, 52, 13, 88, 54, kSequencePointKind_StepOut, 0, 12 } /* seqPointIndex: 12 */,
	{ 45215, 1, 53, 53, 9, 10, 62, kSequencePointKind_Normal, 0, 13 } /* seqPointIndex: 13 */,
	{ 45216, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 14 } /* seqPointIndex: 14 */,
	{ 45216, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 15 } /* seqPointIndex: 15 */,
	{ 45216, 1, 56, 56, 9, 10, 0, kSequencePointKind_Normal, 0, 16 } /* seqPointIndex: 16 */,
	{ 45216, 1, 57, 57, 13, 38, 1, kSequencePointKind_Normal, 0, 17 } /* seqPointIndex: 17 */,
	{ 45216, 1, 57, 57, 13, 38, 1, kSequencePointKind_StepOut, 0, 18 } /* seqPointIndex: 18 */,
	{ 45216, 1, 60, 60, 13, 64, 7, kSequencePointKind_Normal, 0, 19 } /* seqPointIndex: 19 */,
	{ 45216, 1, 60, 60, 13, 64, 11, kSequencePointKind_StepOut, 0, 20 } /* seqPointIndex: 20 */,
	{ 45216, 1, 61, 61, 13, 64, 17, kSequencePointKind_Normal, 0, 21 } /* seqPointIndex: 21 */,
	{ 45216, 1, 61, 61, 13, 64, 21, kSequencePointKind_StepOut, 0, 22 } /* seqPointIndex: 22 */,
	{ 45216, 1, 63, 63, 13, 51, 27, kSequencePointKind_Normal, 0, 23 } /* seqPointIndex: 23 */,
	{ 45216, 1, 64, 64, 13, 53, 37, kSequencePointKind_Normal, 0, 24 } /* seqPointIndex: 24 */,
	{ 45216, 1, 64, 64, 13, 53, 42, kSequencePointKind_StepOut, 0, 25 } /* seqPointIndex: 25 */,
	{ 45216, 1, 65, 65, 13, 27, 48, kSequencePointKind_Normal, 0, 26 } /* seqPointIndex: 26 */,
	{ 45216, 1, 65, 65, 0, 0, 54, kSequencePointKind_Normal, 0, 27 } /* seqPointIndex: 27 */,
	{ 45216, 1, 66, 66, 17, 66, 58, kSequencePointKind_Normal, 0, 28 } /* seqPointIndex: 28 */,
	{ 45216, 1, 66, 66, 17, 66, 63, kSequencePointKind_StepOut, 0, 29 } /* seqPointIndex: 29 */,
	{ 45216, 1, 68, 68, 13, 36, 69, kSequencePointKind_Normal, 0, 30 } /* seqPointIndex: 30 */,
	{ 45216, 1, 68, 68, 13, 36, 69, kSequencePointKind_StepOut, 0, 31 } /* seqPointIndex: 31 */,
	{ 45216, 1, 71, 71, 13, 85, 75, kSequencePointKind_Normal, 0, 32 } /* seqPointIndex: 32 */,
	{ 45216, 1, 71, 71, 13, 85, 75, kSequencePointKind_StepOut, 0, 33 } /* seqPointIndex: 33 */,
	{ 45216, 1, 71, 71, 13, 85, 87, kSequencePointKind_StepOut, 0, 34 } /* seqPointIndex: 34 */,
	{ 45216, 1, 75, 75, 9, 10, 93, kSequencePointKind_Normal, 0, 35 } /* seqPointIndex: 35 */,
	{ 45221, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 36 } /* seqPointIndex: 36 */,
	{ 45221, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 37 } /* seqPointIndex: 37 */,
	{ 45221, 1, 34, 34, 9, 43, 0, kSequencePointKind_Normal, 0, 38 } /* seqPointIndex: 38 */,
	{ 45221, 1, 39, 39, 9, 50, 11, kSequencePointKind_Normal, 0, 39 } /* seqPointIndex: 39 */,
	{ 45221, 1, 39, 39, 9, 50, 23, kSequencePointKind_StepOut, 0, 40 } /* seqPointIndex: 40 */,
	{ 45222, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 41 } /* seqPointIndex: 41 */,
	{ 45222, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 42 } /* seqPointIndex: 42 */,
	{ 45222, 1, 28, 28, 9, 127, 0, kSequencePointKind_Normal, 0, 43 } /* seqPointIndex: 43 */,
	{ 45222, 1, 28, 28, 9, 127, 5, kSequencePointKind_StepOut, 0, 44 } /* seqPointIndex: 44 */,
	{ 45222, 1, 29, 29, 9, 124, 15, kSequencePointKind_Normal, 0, 45 } /* seqPointIndex: 45 */,
	{ 45222, 1, 29, 29, 9, 124, 20, kSequencePointKind_StepOut, 0, 46 } /* seqPointIndex: 46 */,
};
#else
extern Il2CppSequencePoint g_sequencePointsUnity_XR_OpenXR_Features_RuntimeDebugger[];
Il2CppSequencePoint g_sequencePointsUnity_XR_OpenXR_Features_RuntimeDebugger[1] = { { 0, 0, 0, 0, 0, 0, 0, kSequencePointKind_Normal, 0, 0, } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppCatchPoint g_catchPoints[1] = { { 0, 0, 0, 0, } };
#else
static const Il2CppCatchPoint g_catchPoints[1] = { { 0, 0, 0, 0, } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppSequencePointSourceFile g_sequencePointSourceFiles[] = {
{ "", { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} }, //0 
{ "D:\\Programmerings Projekt\\Neuro\\Library\\PackageCache\\com.unity.xr.openxr@1.4.2\\RuntimeDebugger\\RuntimeDebuggerOpenXRFeature.cs", { 16, 201, 59, 117, 187, 47, 105, 101, 65, 121, 37, 70, 211, 204, 37, 168} }, //1 
};
#else
static const Il2CppSequencePointSourceFile g_sequencePointSourceFiles[1] = { NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppTypeSourceFilePair g_typeSourceFiles[1] = 
{
	{ 6413, 1 },
};
#else
static const Il2CppTypeSourceFilePair g_typeSourceFiles[1] = { { 0, 0 } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppMethodScope g_methodScopes[2] = 
{
	{ 0, 64 },
	{ 0, 94 },
};
#else
static const Il2CppMethodScope g_methodScopes[1] = { { 0, 0 } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppMethodHeaderInfo g_methodHeaderInfos[8] = 
{
	{ 64, 0, 1 } /* System.IntPtr UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::HookGetInstanceProcAddr(System.IntPtr) */,
	{ 94, 1, 1 } /* System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::RecvMsg(UnityEngine.Networking.PlayerConnection.MessageEventArgs) */,
	{ 0, 0, 0 } /* System.IntPtr UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::Native_HookGetInstanceProcAddr(System.IntPtr,System.UInt32,System.UInt32) */,
	{ 0, 0, 0 } /* System.Boolean UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::Native_GetDataForRead(System.IntPtr&,System.UInt32&) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::Native_StartDataAccess() */,
	{ 0, 0, 0 } /* System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::Native_EndDataAccess() */,
	{ 0, 0, 0 } /* System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::.ctor() */,
	{ 0, 0, 0 } /* System.Void UnityEngine.XR.OpenXR.Features.RuntimeDebugger.RuntimeDebuggerOpenXRFeature::.cctor() */,
};
#else
static const Il2CppMethodHeaderInfo g_methodHeaderInfos[1] = { { 0, 0, 0 } };
#endif
IL2CPP_EXTERN_C const Il2CppDebuggerMetadataRegistration g_DebuggerMetadataRegistrationUnity_XR_OpenXR_Features_RuntimeDebugger;
const Il2CppDebuggerMetadataRegistration g_DebuggerMetadataRegistrationUnity_XR_OpenXR_Features_RuntimeDebugger = 
{
	(Il2CppMethodExecutionContextInfo*)g_methodExecutionContextInfos,
	(Il2CppMethodExecutionContextInfoIndex*)g_methodExecutionContextInfoIndexes,
	(Il2CppMethodScope*)g_methodScopes,
	(Il2CppMethodHeaderInfo*)g_methodHeaderInfos,
	(Il2CppSequencePointSourceFile*)g_sequencePointSourceFiles,
	47,
	(Il2CppSequencePoint*)g_sequencePointsUnity_XR_OpenXR_Features_RuntimeDebugger,
	0,
	(Il2CppCatchPoint*)g_catchPoints,
	1,
	(Il2CppTypeSourceFilePair*)g_typeSourceFiles,
	(const char**)g_methodExecutionContextInfoStrings,
};
