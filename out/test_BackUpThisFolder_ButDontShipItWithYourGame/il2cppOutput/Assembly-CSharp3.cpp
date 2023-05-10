#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>
#include <stdint.h>


struct VirtualActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1, typename T2>
struct VirtualActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

// System.Runtime.CompilerServices.ConditionalWeakTable`2<System.Object,System.Runtime.Serialization.SerializationInfo>
struct ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// openDicom.DataStructure.DataSet.DataElement[]
struct DataElementU5BU5D_tA692899F5BBF2F54DF713616F87C97FDF6F8A3F9;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// System.Collections.Hashtable/bucket[]
struct bucketU5BU5D_t59F1C7BC4EBFE874CA0B3F391EA65717E3C8D587;
// System.Collections.ArrayList
struct ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A;
// openDicom.Encoding.CharacterRepertoire
struct CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1;
// openDicom.DataStructure.DataSet.DataElement
struct DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F;
// openDicom.DataStructure.DataSet.DataSet
struct DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7;
// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095;
// System.Collections.Hashtable
struct Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D;
// System.Collections.ICollection
struct ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E;
// System.Collections.IEnumerator
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
// System.Collections.IEqualityComparer
struct IEqualityComparer_tEF8F1EC76B9C8E76695BE848D41E6B147928D1C1;
// openDicom.DataStructure.DataSet.NestedDataSet
struct NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD;
// System.Threading.SemaphoreSlim
struct SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2;
// openDicom.DataStructure.DataSet.Sequence
struct Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C;
// System.IO.Stream
struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE;
// System.String
struct String_t;
// openDicom.DataStructure.Tag
struct Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D;
// openDicom.Encoding.TransferSyntax
struct TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F;
// openDicom.Registry.Uid
struct Uid_t95DC8BA9DD1640900AA4A4AE7FD093B31CB97820;
// openDicom.DataStructure.Value
struct Value_tBB45E224730D00460EF4DF654DD83F51A9B05438;
// openDicom.DataStructure.ValueLength
struct ValueLength_t1364D01B32A890C2A108538663C45EAD3810526E;
// openDicom.DataStructure.ValueRepresentation
struct ValueRepresentation_t504BA281529626716A2E18FBB30EC6D3202A72B8;
// System.IO.Stream/ReadWriteTask
struct ReadWriteTask_t0821BF49EE38596C7734E86E1A6A39D769BE2C05;

IL2CPP_EXTERN_C RuntimeClass* ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DataElementU5BU5D_tA692899F5BBF2F54DF713616F87C97FDF6F8A3F9_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* String_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0F0A5D424C28A42A7E1B29C286B7C516EF31B4FA;
IL2CPP_EXTERN_C String_t* _stringLiteral8AF0F149B052017E5BD59790E10BB7FC6189418C;
IL2CPP_EXTERN_C String_t* _stringLiteral9441854635B34F2C803AA684E62CC57FC4482357;
IL2CPP_EXTERN_C String_t* _stringLiteralAB33FE70A8F926088C384248059A27AE458AE755;

struct DataElementU5BU5D_tA692899F5BBF2F54DF713616F87C97FDF6F8A3F9;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA  : public RuntimeObject
{
};

struct U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA_StaticFields
{
	// System.Int32 <PrivateImplementationDetails>::4C07EAEA1325B5D4E41ED98D5C96E4681EEFDE39E58AFF9F47ADAF7AF2D0D46A
	int32_t ___4C07EAEA1325B5D4E41ED98D5C96E4681EEFDE39E58AFF9F47ADAF7AF2D0D46A_0;
};
struct Il2CppArrayBounds;

// System.Collections.ArrayList
struct ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A  : public RuntimeObject
{
	// System.Object[] System.Collections.ArrayList::_items
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items_0;
	// System.Int32 System.Collections.ArrayList::_size
	int32_t ____size_1;
	// System.Int32 System.Collections.ArrayList::_version
	int32_t ____version_2;
	// System.Object System.Collections.ArrayList::_syncRoot
	RuntimeObject* ____syncRoot_3;
};

// openDicom.Encoding.CharacterRepertoire
struct CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1  : public RuntimeObject
{
	// System.Text.Encoding openDicom.Encoding.CharacterRepertoire::encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___encoding_6;
};

struct CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_StaticFields
{
	// openDicom.DataStructure.Tag openDicom.Encoding.CharacterRepertoire::CharacterSetTag
	Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* ___CharacterSetTag_0;
	// openDicom.Encoding.CharacterRepertoire openDicom.Encoding.CharacterRepertoire::Default
	CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* ___Default_1;
	// openDicom.Encoding.CharacterRepertoire openDicom.Encoding.CharacterRepertoire::Ascii
	CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* ___Ascii_2;
	// openDicom.Encoding.CharacterRepertoire openDicom.Encoding.CharacterRepertoire::Utf8
	CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* ___Utf8_3;
	// openDicom.Encoding.CharacterRepertoire openDicom.Encoding.CharacterRepertoire::G0
	CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* ___G0_4;
	// openDicom.Encoding.CharacterRepertoire openDicom.Encoding.CharacterRepertoire::G1
	CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* ___G1_5;
};

// openDicom.DataStructure.DataSet.DataElement
struct DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F  : public RuntimeObject
{
	// openDicom.DataStructure.Tag openDicom.DataStructure.DataSet.DataElement::tag
	Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* ___tag_0;
	// openDicom.DataStructure.ValueRepresentation openDicom.DataStructure.DataSet.DataElement::vr
	ValueRepresentation_t504BA281529626716A2E18FBB30EC6D3202A72B8* ___vr_1;
	// openDicom.DataStructure.ValueLength openDicom.DataStructure.DataSet.DataElement::valueLength
	ValueLength_t1364D01B32A890C2A108538663C45EAD3810526E* ___valueLength_2;
	// openDicom.DataStructure.Value openDicom.DataStructure.DataSet.DataElement::value
	Value_tBB45E224730D00460EF4DF654DD83F51A9B05438* ___value_3;
	// openDicom.Encoding.TransferSyntax openDicom.DataStructure.DataSet.DataElement::transferSyntax
	TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax_4;
};

// System.Collections.Hashtable
struct Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D  : public RuntimeObject
{
	// System.Collections.Hashtable/bucket[] System.Collections.Hashtable::_buckets
	bucketU5BU5D_t59F1C7BC4EBFE874CA0B3F391EA65717E3C8D587* ____buckets_10;
	// System.Int32 System.Collections.Hashtable::_count
	int32_t ____count_11;
	// System.Int32 System.Collections.Hashtable::_occupancy
	int32_t ____occupancy_12;
	// System.Int32 System.Collections.Hashtable::_loadsize
	int32_t ____loadsize_13;
	// System.Single System.Collections.Hashtable::_loadFactor
	float ____loadFactor_14;
	// System.Int32 modreq(System.Runtime.CompilerServices.IsVolatile) System.Collections.Hashtable::_version
	int32_t ____version_15;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.Collections.Hashtable::_isWriterInProgress
	bool ____isWriterInProgress_16;
	// System.Collections.ICollection System.Collections.Hashtable::_keys
	RuntimeObject* ____keys_17;
	// System.Collections.ICollection System.Collections.Hashtable::_values
	RuntimeObject* ____values_18;
	// System.Collections.IEqualityComparer System.Collections.Hashtable::_keycomparer
	RuntimeObject* ____keycomparer_19;
	// System.Object System.Collections.Hashtable::_syncRoot
	RuntimeObject* ____syncRoot_20;
};

struct Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_StaticFields
{
	// System.Runtime.CompilerServices.ConditionalWeakTable`2<System.Object,System.Runtime.Serialization.SerializationInfo> System.Collections.Hashtable::s_serializationInfoTable
	ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* ___s_serializationInfoTable_21;
};

// System.MarshalByRefObject
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE  : public RuntimeObject
{
	// System.Object System.MarshalByRefObject::_identity
	RuntimeObject* ____identity_0;
};
// Native definition for P/Invoke marshalling of System.MarshalByRefObject
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE_marshaled_pinvoke
{
	Il2CppIUnknown* ____identity_0;
};
// Native definition for COM marshalling of System.MarshalByRefObject
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE_marshaled_com
{
	Il2CppIUnknown* ____identity_0;
};

// openDicom.DataStructure.DataSet.Sequence
struct Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C  : public RuntimeObject
{
	// System.Collections.ArrayList openDicom.DataStructure.DataSet.Sequence::itemList
	ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* ___itemList_1;
	// openDicom.Encoding.TransferSyntax openDicom.DataStructure.DataSet.Sequence::transferSyntax
	TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax_2;
	// System.Int64 openDicom.DataStructure.DataSet.Sequence::streamPosition
	int64_t ___streamPosition_3;
};

struct Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_StaticFields
{
	// openDicom.DataStructure.Tag openDicom.DataStructure.DataSet.Sequence::DelimiterTag
	Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* ___DelimiterTag_0;
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// openDicom.DataStructure.Tag
struct Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D  : public RuntimeObject
{
	// System.String openDicom.DataStructure.Tag::group
	String_t* ___group_0;
	// System.String openDicom.DataStructure.Tag::element
	String_t* ___element_1;
	// System.Int64 openDicom.DataStructure.Tag::streamPosition
	int64_t ___streamPosition_2;
	// openDicom.Encoding.TransferSyntax openDicom.DataStructure.Tag::transferSyntax
	TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax_3;
};

// openDicom.Encoding.TransferSyntax
struct TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F  : public RuntimeObject
{
	// System.Boolean openDicom.Encoding.TransferSyntax::isImplicitVR
	bool ___isImplicitVR_3;
	// System.Boolean openDicom.Encoding.TransferSyntax::isLittleEndian
	bool ___isLittleEndian_4;
	// openDicom.Encoding.CharacterRepertoire openDicom.Encoding.TransferSyntax::characterRepertoire
	CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* ___characterRepertoire_5;
	// openDicom.Registry.Uid openDicom.Encoding.TransferSyntax::uid
	Uid_t95DC8BA9DD1640900AA4A4AE7FD093B31CB97820* ___uid_6;
};

struct TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_StaticFields
{
	// openDicom.DataStructure.Tag openDicom.Encoding.TransferSyntax::UidTag
	Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* ___UidTag_0;
	// openDicom.Encoding.TransferSyntax openDicom.Encoding.TransferSyntax::Default
	TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___Default_1;
	// openDicom.Encoding.TransferSyntax openDicom.Encoding.TransferSyntax::FileMetaInformation
	TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___FileMetaInformation_2;
};

// openDicom.DataStructure.Value
struct Value_tBB45E224730D00460EF4DF654DD83F51A9B05438  : public RuntimeObject
{
	// System.Collections.ArrayList openDicom.DataStructure.Value::valueList
	ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* ___valueList_0;
	// openDicom.DataStructure.ValueRepresentation openDicom.DataStructure.Value::vr
	ValueRepresentation_t504BA281529626716A2E18FBB30EC6D3202A72B8* ___vr_1;
	// openDicom.DataStructure.ValueLength openDicom.DataStructure.Value::valueLength
	ValueLength_t1364D01B32A890C2A108538663C45EAD3810526E* ___valueLength_2;
	// System.Int64 openDicom.DataStructure.Value::streamPosition
	int64_t ___streamPosition_3;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	// System.Char System.Char::m_value
	Il2CppChar ___m_value_0;
};

struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	// System.Byte[] System.Char::s_categoryForLatin1
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1_3;
};

// openDicom.DataStructure.DataSet.DataSet
struct DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7  : public Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C
{
	// System.Collections.Hashtable openDicom.DataStructure.DataSet.DataSet::keys
	Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* ___keys_4;
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.Int64
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	// System.Int64 System.Int64::m_value
	int64_t ___m_value_0;
};

// System.IO.Stream
struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE  : public MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE
{
	// System.IO.Stream/ReadWriteTask System.IO.Stream::_activeReadWriteTask
	ReadWriteTask_t0821BF49EE38596C7734E86E1A6A39D769BE2C05* ____activeReadWriteTask_2;
	// System.Threading.SemaphoreSlim System.IO.Stream::_asyncActiveSemaphore
	SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2* ____asyncActiveSemaphore_3;
};

struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE_StaticFields
{
	// System.IO.Stream System.IO.Stream::Null
	Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___Null_1;
};

// System.UInt32
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	// System.UInt32 System.UInt32::m_value
	uint32_t ___m_value_0;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// openDicom.DataStructure.DataSet.NestedDataSet
struct NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD  : public DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7
{
};

struct NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_StaticFields
{
	// openDicom.DataStructure.Tag openDicom.DataStructure.DataSet.NestedDataSet::DelimiterTag
	Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* ___DelimiterTag_5;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// openDicom.DataStructure.DataSet.DataElement[]
struct DataElementU5BU5D_tA692899F5BBF2F54DF713616F87C97FDF6F8A3F9  : public RuntimeArray
{
	ALIGN_FIELD (8) DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* m_Items[1];

	inline DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};



// openDicom.DataStructure.DataSet.DataElement openDicom.DataStructure.DataSet.Sequence::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* Sequence_get_Item_mA3B302B18C7C3ED08B3D3F10CC1F8760F9A24D1B (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, int32_t ___index0, const RuntimeMethod* method) ;
// System.Void System.Collections.Hashtable::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Hashtable__ctor_mD7E2F1EB1BFD683186ECD6EDBE1708AF35C3A87D (Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* __this, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.Sequence::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence__ctor_mF9BB9E11FFF4A127D4CBDAD0519CF82D18D02C08 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.Sequence::.ctor(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence__ctor_mFAB3DDAF14C8DA17AED1AA40C32712E124A9ADD6 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.Sequence::.ctor(System.IO.Stream,openDicom.Encoding.TransferSyntax)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence__ctor_m3520CBA8D0740EBF3AA308F66DFF6DF8867F5FC5 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax1, const RuntimeMethod* method) ;
// openDicom.Encoding.TransferSyntax openDicom.DataStructure.DataSet.Sequence::get_TransferSyntax()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) ;
// System.Void openDicom.Encoding.TransferSyntax::set_CharacterRepertoire(openDicom.Encoding.CharacterRepertoire)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TransferSyntax_set_CharacterRepertoire_mFDCB9EB5ED3E0BAF6DB187E0C198134D3BA6720E (TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* __this, CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* ___value0, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.DataElement::.ctor(System.IO.Stream,openDicom.Encoding.TransferSyntax)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataElement__ctor_mC9771DB96F7483D64EB6025888342E639E3D4812 (DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax1, const RuntimeMethod* method) ;
// openDicom.DataStructure.Tag openDicom.DataStructure.DataSet.DataElement::get_Tag()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC (DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* __this, const RuntimeMethod* method) ;
// System.Boolean openDicom.DataStructure.Tag::Equals(openDicom.DataStructure.Tag)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Tag_Equals_m47E0DDE19DB60704948525D228A94DF7AF03C889 (Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* __this, Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* ___tag0, const RuntimeMethod* method) ;
// openDicom.DataStructure.Value openDicom.DataStructure.DataSet.DataElement::get_Value()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Value_tBB45E224730D00460EF4DF654DD83F51A9B05438* DataElement_get_Value_mDA522A9539D1E16FD9CCFC2351704270E77709F0 (DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* __this, const RuntimeMethod* method) ;
// System.Object openDicom.DataStructure.Value::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Value_get_Item_mC0821F3FC1832B985AE789FE4D30EF0B0D61F394 (Value_tBB45E224730D00460EF4DF654DD83F51A9B05438* __this, int32_t ___index0, const RuntimeMethod* method) ;
// System.Void openDicom.Encoding.CharacterRepertoire::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CharacterRepertoire__ctor_m0AD99D377BE9D1BBF12247E69241623B5EE6EFEC (CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* __this, String_t* ___characterSet0, const RuntimeMethod* method) ;
// System.Boolean openDicom.DataStructure.Tag::Equals(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Tag_Equals_m309E81C20017DBD9AC3A33CB9DE94AEDE215A75D (Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* __this, String_t* ___tag0, const RuntimeMethod* method) ;
// System.Int32 openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.DataElement)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sequence_Add_m488C2E75C38A5F14D33BB9BB39F39D971FD2CE3F (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* ___dataElement0, const RuntimeMethod* method) ;
// System.Collections.IEnumerator openDicom.DataStructure.DataSet.Sequence::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Sequence_GetEnumerator_m076590366A9A9AA5BADFA65E09C1E656EC36BA1C (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) ;
// openDicom.DataStructure.DataSet.Sequence openDicom.DataStructure.DataSet.Sequence::GetJointSubsequences()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* Sequence_GetJointSubsequences_m022675DD2F7B4F38B20F0011DC3A10F60FC333EC (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.Sequence::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_Clear_m35C93BEA7B3A0C5CBB0549ED8F8E295673A6E4E0 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.Sequence::Sort()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_Sort_m5E7A7055D8E71374A6B96575D61C02C72624EB42 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) ;
// System.Int32 openDicom.DataStructure.DataSet.Sequence::get_Count()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sequence_get_Count_m68A3CC8B9371C0E570FCF3BEB959A4C21D81E959 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.DataSet::.ctor(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet__ctor_mCED69B9AC07B609958EA89E8B2A059961461E1ED (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.DataSet::.ctor(System.IO.Stream,openDicom.Encoding.TransferSyntax)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet__ctor_m1FDE14ED600AB7A47CB28904533CFBB0E46EC738 (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax1, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.Tag::.ctor(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Tag__ctor_mD73A46B61F11C5361434F8746E48AE831D088EEF (Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* __this, String_t* ___group0, String_t* ___element1, const RuntimeMethod* method) ;
// System.Void System.Collections.ArrayList::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArrayList__ctor_m07DC369002304B483B9FC41DBDAF4A25AC3C9F80 (ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* __this, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.Sequence::set_TransferSyntax(openDicom.Encoding.TransferSyntax)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_set_TransferSyntax_m50D66DEB15CE675934FBE8BEE32D78F282548115 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___value0, const RuntimeMethod* method) ;
// System.Collections.IEnumerator openDicom.DataStructure.Value::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Value_GetEnumerator_m55A491E58A49E301D5290F92AEBA5B3755BF746A (Value_tBB45E224730D00460EF4DF654DD83F51A9B05438* __this, const RuntimeMethod* method) ;
// openDicom.DataStructure.DataSet.Sequence openDicom.DataStructure.DataSet.Sequence::TreeNodeToSequence(openDicom.DataStructure.DataSet.Sequence)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* Sequence_TreeNodeToSequence_m1B202FC1531B68F5EDA4C987FE7DF8F68D22F9FA (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* ___sequence0, const RuntimeMethod* method) ;
// System.Void openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.Sequence)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_Add_m4F7621AF822E72321740024C6EAFFF119C7A53C0 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* ___sequence0, const RuntimeMethod* method) ;
// System.Char System.String::get_Chars(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3 (String_t* __this, int32_t ___index0, const RuntimeMethod* method) ;
// System.Int32 System.String::get_Length()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// openDicom.DataStructure.DataSet.DataElement openDicom.DataStructure.DataSet.DataSet::get_Item(openDicom.DataStructure.Tag)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* DataSet_get_Item_m406AA02ABEE6798BC90C9246A05D2B4963444A25 (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* ___tag0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// int index = (int) keys[tag.ToString()];
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_0 = __this->___keys_4;
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_1 = ___tag0;
		NullCheck(L_1);
		String_t* L_2;
		L_2 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_1);
		NullCheck(L_0);
		RuntimeObject* L_3;
		L_3 = VirtualFuncInvoker1< RuntimeObject*, RuntimeObject* >::Invoke(21 /* System.Object System.Collections.Hashtable::get_Item(System.Object) */, L_0, L_2);
		V_0 = ((*(int32_t*)((int32_t*)(int32_t*)UnBox(L_3, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var))));
		// return base[index];
		int32_t L_4 = V_0;
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_5;
		L_5 = Sequence_get_Item_mA3B302B18C7C3ED08B3D3F10CC1F8760F9A24D1B(__this, L_4, NULL);
		return L_5;
	}
}
// System.Void openDicom.DataStructure.DataSet.DataSet::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet__ctor_m06436468044356DEDC4C4D263C47F438A6A5A5B3 (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Hashtable keys = new Hashtable();
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_0 = (Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D*)il2cpp_codegen_object_new(Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Hashtable__ctor_mD7E2F1EB1BFD683186ECD6EDBE1708AF35C3A87D(L_0, NULL);
		__this->___keys_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___keys_4), (void*)L_0);
		// public DataSet() {}
		il2cpp_codegen_runtime_class_init_inline(Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		Sequence__ctor_mF9BB9E11FFF4A127D4CBDAD0519CF82D18D02C08(__this, NULL);
		// public DataSet() {}
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.DataSet::.ctor(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet__ctor_mCED69B9AC07B609958EA89E8B2A059961461E1ED (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Hashtable keys = new Hashtable();
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_0 = (Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D*)il2cpp_codegen_object_new(Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Hashtable__ctor_mD7E2F1EB1BFD683186ECD6EDBE1708AF35C3A87D(L_0, NULL);
		__this->___keys_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___keys_4), (void*)L_0);
		// public DataSet(Stream stream): base(stream) {}
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_1 = ___stream0;
		il2cpp_codegen_runtime_class_init_inline(Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		Sequence__ctor_mFAB3DDAF14C8DA17AED1AA40C32712E124A9ADD6(__this, L_1, NULL);
		// public DataSet(Stream stream): base(stream) {}
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.DataSet::.ctor(System.IO.Stream,openDicom.Encoding.TransferSyntax)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet__ctor_m1FDE14ED600AB7A47CB28904533CFBB0E46EC738 (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Hashtable keys = new Hashtable();
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_0 = (Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D*)il2cpp_codegen_object_new(Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Hashtable__ctor_mD7E2F1EB1BFD683186ECD6EDBE1708AF35C3A87D(L_0, NULL);
		__this->___keys_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___keys_4), (void*)L_0);
		// base(stream, transferSyntax) {}
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_1 = ___stream0;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_2 = ___transferSyntax1;
		il2cpp_codegen_runtime_class_init_inline(Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		Sequence__ctor_m3520CBA8D0740EBF3AA308F66DFF6DF8867F5FC5(__this, L_1, L_2, NULL);
		// base(stream, transferSyntax) {}
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.DataSet::LoadFrom(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet_LoadFrom_mE5DA86321F74B35C17CF79BAC0E51977D9ABE826 (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0F0A5D424C28A42A7E1B29C286B7C516EF31B4FA);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* V_1 = NULL;
	{
		// streamPosition = stream.Position;
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_0 = ___stream0;
		NullCheck(L_0);
		int64_t L_1;
		L_1 = VirtualFuncInvoker0< int64_t >::Invoke(12 /* System.Int64 System.IO.Stream::get_Position() */, L_0);
		((Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C*)__this)->___streamPosition_3 = L_1;
		// TransferSyntax.CharacterRepertoire = CharacterRepertoire.Default;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_2;
		L_2 = Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_il2cpp_TypeInfo_var);
		CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* L_3 = ((CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_StaticFields*)il2cpp_codegen_static_fields_for(CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_il2cpp_TypeInfo_var))->___Default_1;
		NullCheck(L_2);
		TransferSyntax_set_CharacterRepertoire_mFDCB9EB5ED3E0BAF6DB187E0C198134D3BA6720E(L_2, L_3, NULL);
		// bool isTrailingPadding = false;
		V_0 = (bool)0;
		goto IL_007c;
	}

IL_0020:
	{
		// DataElement element = new DataElement(stream, TransferSyntax);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_4 = ___stream0;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_5;
		L_5 = Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline(__this, NULL);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_6 = (DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)il2cpp_codegen_object_new(DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		NullCheck(L_6);
		DataElement__ctor_mC9771DB96F7483D64EB6025888342E639E3D4812(L_6, L_4, L_5, NULL);
		V_1 = L_6;
		// if (element.Tag.Equals(CharacterRepertoire.CharacterSetTag))
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_7 = V_1;
		NullCheck(L_7);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_8;
		L_8 = DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC(L_7, NULL);
		il2cpp_codegen_runtime_class_init_inline(CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_il2cpp_TypeInfo_var);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_9 = ((CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_StaticFields*)il2cpp_codegen_static_fields_for(CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_il2cpp_TypeInfo_var))->___CharacterSetTag_0;
		NullCheck(L_8);
		bool L_10;
		L_10 = Tag_Equals_m47E0DDE19DB60704948525D228A94DF7AF03C889(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0060;
		}
	}
	{
		// TransferSyntax.CharacterRepertoire =
		//     new CharacterRepertoire((string) element.Value[0]);
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_11;
		L_11 = Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline(__this, NULL);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_12 = V_1;
		NullCheck(L_12);
		Value_tBB45E224730D00460EF4DF654DD83F51A9B05438* L_13;
		L_13 = DataElement_get_Value_mDA522A9539D1E16FD9CCFC2351704270E77709F0(L_12, NULL);
		NullCheck(L_13);
		RuntimeObject* L_14;
		L_14 = Value_get_Item_mC0821F3FC1832B985AE789FE4D30EF0B0D61F394(L_13, 0, NULL);
		CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1* L_15 = (CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1*)il2cpp_codegen_object_new(CharacterRepertoire_t2EB67192233E24A9F5BA957CD731F95E4E07A2F1_il2cpp_TypeInfo_var);
		NullCheck(L_15);
		CharacterRepertoire__ctor_m0AD99D377BE9D1BBF12247E69241623B5EE6EFEC(L_15, ((String_t*)CastclassSealed((RuntimeObject*)L_14, String_t_il2cpp_TypeInfo_var)), NULL);
		NullCheck(L_11);
		TransferSyntax_set_CharacterRepertoire_mFDCB9EB5ED3E0BAF6DB187E0C198134D3BA6720E(L_11, L_15, NULL);
	}

IL_0060:
	{
		// isTrailingPadding = element.Tag.Equals("(0000,0000)");
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_16 = V_1;
		NullCheck(L_16);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_17;
		L_17 = DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC(L_16, NULL);
		NullCheck(L_17);
		bool L_18;
		L_18 = Tag_Equals_m309E81C20017DBD9AC3A33CB9DE94AEDE215A75D(L_17, _stringLiteral0F0A5D424C28A42A7E1B29C286B7C516EF31B4FA, NULL);
		V_0 = L_18;
		// if ( ! isTrailingPadding)
		bool L_19 = V_0;
		if (L_19)
		{
			goto IL_007c;
		}
	}
	{
		// Add(element);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_20 = V_1;
		int32_t L_21;
		L_21 = VirtualFuncInvoker1< int32_t, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* >::Invoke(7 /* System.Int32 openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.DataElement) */, __this, L_20);
	}

IL_007c:
	{
		// while (stream.Position < stream.Length && ! isTrailingPadding)
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_22 = ___stream0;
		NullCheck(L_22);
		int64_t L_23;
		L_23 = VirtualFuncInvoker0< int64_t >::Invoke(12 /* System.Int64 System.IO.Stream::get_Position() */, L_22);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_24 = ___stream0;
		NullCheck(L_24);
		int64_t L_25;
		L_25 = VirtualFuncInvoker0< int64_t >::Invoke(11 /* System.Int64 System.IO.Stream::get_Length() */, L_24);
		if ((((int64_t)L_23) >= ((int64_t)L_25)))
		{
			goto IL_008d;
		}
	}
	{
		bool L_26 = V_0;
		if (!L_26)
		{
			goto IL_0020;
		}
	}

IL_008d:
	{
		// }
		return;
	}
}
// System.Int32 openDicom.DataStructure.DataSet.DataSet::Add(openDicom.DataStructure.DataSet.DataElement)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t DataSet_Add_mAC86A9F52A44BE923DC08D5386809D56EFBF0C8A (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* ___dataElement0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// int index = base.Add(dataElement);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_0 = ___dataElement0;
		int32_t L_1;
		L_1 = Sequence_Add_m488C2E75C38A5F14D33BB9BB39F39D971FD2CE3F(__this, L_0, NULL);
		V_0 = L_1;
		// keys.Add(dataElement.Tag.ToString(), index);
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_2 = __this->___keys_4;
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_3 = ___dataElement0;
		NullCheck(L_3);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_4;
		L_4 = DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC(L_3, NULL);
		NullCheck(L_4);
		String_t* L_5;
		L_5 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_4);
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		RuntimeObject* L_8 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_7);
		NullCheck(L_2);
		VirtualActionInvoker2< RuntimeObject*, RuntimeObject* >::Invoke(15 /* System.Void System.Collections.Hashtable::Add(System.Object,System.Object) */, L_2, L_5, L_8);
		// return index;
		int32_t L_9 = V_0;
		return L_9;
	}
}
// System.Void openDicom.DataStructure.DataSet.DataSet::Add(openDicom.DataStructure.DataSet.DataSet)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet_Add_mCC82154BFD5EE2E9596BB71080E09B0F60C3CBAA (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* ___dataSet0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	{
		// foreach (DataElement element in dataSet)
		DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* L_0 = ___dataSet0;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = Sequence_GetEnumerator_m076590366A9A9AA5BADFA65E09C1E656EC36BA1C(L_0, NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0027:
			{// begin finally (depth: 1)
				{
					RuntimeObject* L_2 = V_0;
					V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
					RuntimeObject* L_3 = V_2;
					if (!L_3)
					{
						goto IL_0037;
					}
				}
				{
					RuntimeObject* L_4 = V_2;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_0037:
				{
					return;
				}
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_001d_1;
			}

IL_0009_1:
			{
				// foreach (DataElement element in dataSet)
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				RuntimeObject* L_6;
				L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1 /* System.Object System.Collections.IEnumerator::get_Current() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_5);
				V_1 = ((DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)CastclassSealed((RuntimeObject*)L_6, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var));
				// Add(element);
				DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_7 = V_1;
				int32_t L_8;
				L_8 = VirtualFuncInvoker1< int32_t, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* >::Invoke(7 /* System.Int32 openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.DataElement) */, __this, L_7);
			}

IL_001d_1:
			{
				// foreach (DataElement element in dataSet)
				RuntimeObject* L_9 = V_0;
				NullCheck(L_9);
				bool L_10;
				L_10 = InterfaceFuncInvoker0< bool >::Invoke(0 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_9);
				if (L_10)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_0038;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0038:
	{
		// }
		return;
	}
}
// openDicom.DataStructure.DataSet.Sequence openDicom.DataStructure.DataSet.DataSet::GetJointSubsequences()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* DataSet_GetJointSubsequences_mE0572C3D8E414FC068D15568B83EAB78F42F67CD (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, const RuntimeMethod* method) 
{
	{
		// return base.GetJointSubsequences();
		Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_0;
		L_0 = Sequence_GetJointSubsequences_m022675DD2F7B4F38B20F0011DC3A10F60FC333EC(__this, NULL);
		return L_0;
	}
}
// System.Boolean openDicom.DataStructure.DataSet.DataSet::Contains(openDicom.DataStructure.Tag)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool DataSet_Contains_m452B8D07CAC15FB9A8DE1A454DB696A3FD3841B4 (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* ___tag0, const RuntimeMethod* method) 
{
	{
		// return keys.Contains(tag.ToString());
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_0 = __this->___keys_4;
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_1 = ___tag0;
		NullCheck(L_1);
		String_t* L_2;
		L_2 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_1);
		NullCheck(L_0);
		bool L_3;
		L_3 = VirtualFuncInvoker1< bool, RuntimeObject* >::Invoke(18 /* System.Boolean System.Collections.Hashtable::Contains(System.Object) */, L_0, L_2);
		return L_3;
	}
}
// System.Void openDicom.DataStructure.DataSet.DataSet::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet_Clear_mB7603D08B429BB535E58BE0121CE5E74F4D645FD (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, const RuntimeMethod* method) 
{
	{
		// keys.Clear();
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_0 = __this->___keys_4;
		NullCheck(L_0);
		VirtualActionInvoker0::Invoke(16 /* System.Void System.Collections.Hashtable::Clear() */, L_0);
		// base.Clear();
		Sequence_Clear_m35C93BEA7B3A0C5CBB0549ED8F8E295673A6E4E0(__this, NULL);
		// }
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.DataSet::Sort()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DataSet_Sort_mA7CD308021043D9553AB6A22BA1FE9D32E1F86A7 (DataSet_t340DD891617C8D2654598BC60CC97F0A0D9FE7D7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	String_t* V_1 = NULL;
	{
		// base.Sort();
		Sequence_Sort_m5E7A7055D8E71374A6B96575D61C02C72624EB42(__this, NULL);
		// for (int index = 0; index < Count; index++)
		V_0 = 0;
		goto IL_0032;
	}

IL_000a:
	{
		// string tagKey = base[index].Tag.ToString();
		int32_t L_0 = V_0;
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_1;
		L_1 = Sequence_get_Item_mA3B302B18C7C3ED08B3D3F10CC1F8760F9A24D1B(__this, L_0, NULL);
		NullCheck(L_1);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_2;
		L_2 = DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC(L_1, NULL);
		NullCheck(L_2);
		String_t* L_3;
		L_3 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_2);
		V_1 = L_3;
		// keys[tagKey] = index;
		Hashtable_tEFC3B6496E6747787D8BB761B51F2AE3A8CFFE2D* L_4 = __this->___keys_4;
		String_t* L_5 = V_1;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		RuntimeObject* L_8 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_7);
		NullCheck(L_4);
		VirtualActionInvoker2< RuntimeObject*, RuntimeObject* >::Invoke(22 /* System.Void System.Collections.Hashtable::set_Item(System.Object,System.Object) */, L_4, L_5, L_8);
		// for (int index = 0; index < Count; index++)
		int32_t L_9 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0032:
	{
		// for (int index = 0; index < Count; index++)
		int32_t L_10 = V_0;
		int32_t L_11;
		L_11 = Sequence_get_Count_m68A3CC8B9371C0E570FCF3BEB959A4C21D81E959(__this, NULL);
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_000a;
		}
	}
	{
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void openDicom.DataStructure.DataSet.NestedDataSet::.ctor(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NestedDataSet__ctor_mE07705E6EB3F4226AFD23C19430B4EFF5E019A71 (NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, const RuntimeMethod* method) 
{
	{
		// public NestedDataSet(Stream stream): base(stream) {}
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_0 = ___stream0;
		DataSet__ctor_mCED69B9AC07B609958EA89E8B2A059961461E1ED(__this, L_0, NULL);
		// public NestedDataSet(Stream stream): base(stream) {}
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.NestedDataSet::.ctor(System.IO.Stream,openDicom.Encoding.TransferSyntax)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NestedDataSet__ctor_mA3B5C37E5835C075AE00E08ED45E4E9FD279C949 (NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax1, const RuntimeMethod* method) 
{
	{
		// base(stream, transferSyntax) {}
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_0 = ___stream0;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_1 = ___transferSyntax1;
		DataSet__ctor_m1FDE14ED600AB7A47CB28904533CFBB0E46EC738(__this, L_0, L_1, NULL);
		// base(stream, transferSyntax) {}
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.NestedDataSet::LoadFrom(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NestedDataSet_LoadFrom_mC4DC9C616C1E0EC86808BDADB7D550EAC19A00F8 (NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0F0A5D424C28A42A7E1B29C286B7C516EF31B4FA);
		s_Il2CppMethodInitialized = true;
	}
	DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* V_0 = NULL;
	{
		// streamPosition = stream.Position;
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_0 = ___stream0;
		NullCheck(L_0);
		int64_t L_1;
		L_1 = VirtualFuncInvoker0< int64_t >::Invoke(12 /* System.Int64 System.IO.Stream::get_Position() */, L_0);
		((Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C*)__this)->___streamPosition_3 = L_1;
		// DataElement element = new DataElement(stream, TransferSyntax);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_2 = ___stream0;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_3;
		L_3 = Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline(__this, NULL);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_4 = (DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)il2cpp_codegen_object_new(DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		DataElement__ctor_mC9771DB96F7483D64EB6025888342E639E3D4812(L_4, L_2, L_3, NULL);
		V_0 = L_4;
		goto IL_0042;
	}

IL_001b:
	{
		// isTrailingPadding = element.Tag.Equals("(0000,0000)");
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_5 = V_0;
		NullCheck(L_5);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_6;
		L_6 = DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC(L_5, NULL);
		NullCheck(L_6);
		bool L_7;
		L_7 = Tag_Equals_m309E81C20017DBD9AC3A33CB9DE94AEDE215A75D(L_6, _stringLiteral0F0A5D424C28A42A7E1B29C286B7C516EF31B4FA, NULL);
		// if ( ! isTrailingPadding)
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		// Add(element);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_8 = V_0;
		int32_t L_9;
		L_9 = VirtualFuncInvoker1< int32_t, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* >::Invoke(7 /* System.Int32 openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.DataElement) */, __this, L_8);
	}

IL_0035:
	{
		// element = new DataElement(stream, TransferSyntax);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_10 = ___stream0;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_11;
		L_11 = Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline(__this, NULL);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_12 = (DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)il2cpp_codegen_object_new(DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		NullCheck(L_12);
		DataElement__ctor_mC9771DB96F7483D64EB6025888342E639E3D4812(L_12, L_10, L_11, NULL);
		V_0 = L_12;
	}

IL_0042:
	{
		// while ( ! element.Tag.Equals(DelimiterTag) &&
		//     stream.Position < stream.Length)
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_13 = V_0;
		NullCheck(L_13);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_14;
		L_14 = DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC(L_13, NULL);
		il2cpp_codegen_runtime_class_init_inline(NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_il2cpp_TypeInfo_var);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_15 = ((NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_StaticFields*)il2cpp_codegen_static_fields_for(NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_il2cpp_TypeInfo_var))->___DelimiterTag_5;
		NullCheck(L_14);
		bool L_16;
		L_16 = Tag_Equals_m47E0DDE19DB60704948525D228A94DF7AF03C889(L_14, L_15, NULL);
		if (L_16)
		{
			goto IL_0062;
		}
	}
	{
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_17 = ___stream0;
		NullCheck(L_17);
		int64_t L_18;
		L_18 = VirtualFuncInvoker0< int64_t >::Invoke(12 /* System.Int64 System.IO.Stream::get_Position() */, L_17);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_19 = ___stream0;
		NullCheck(L_19);
		int64_t L_20;
		L_20 = VirtualFuncInvoker0< int64_t >::Invoke(11 /* System.Int64 System.IO.Stream::get_Length() */, L_19);
		if ((((int64_t)L_18) < ((int64_t)L_20)))
		{
			goto IL_001b;
		}
	}

IL_0062:
	{
		// }
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.NestedDataSet::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NestedDataSet__cctor_m2A1EA69CE91AAC8C3905F88BFADF05235E5BCD88 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8AF0F149B052017E5BD59790E10BB7FC6189418C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAB33FE70A8F926088C384248059A27AE458AE755);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public new static readonly Tag DelimiterTag = new Tag("FFFE", "E00D");
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_0 = (Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D*)il2cpp_codegen_object_new(Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Tag__ctor_mD73A46B61F11C5361434F8746E48AE831D088EEF(L_0, _stringLiteralAB33FE70A8F926088C384248059A27AE458AE755, _stringLiteral8AF0F149B052017E5BD59790E10BB7FC6189418C, NULL);
		((NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_StaticFields*)il2cpp_codegen_static_fields_for(NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_il2cpp_TypeInfo_var))->___DelimiterTag_5 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_StaticFields*)il2cpp_codegen_static_fields_for(NestedDataSet_tB996DD1A2FC41A892E4627617395DAE8F0CE6FDD_il2cpp_TypeInfo_var))->___DelimiterTag_5), (void*)L_0);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// openDicom.DataStructure.DataSet.DataElement openDicom.DataStructure.DataSet.Sequence::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* Sequence_get_Item_mA3B302B18C7C3ED08B3D3F10CC1F8760F9A24D1B (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, int32_t ___index0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get { return (DataElement) itemList[index]; }
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___itemList_1;
		int32_t L_1 = ___index0;
		NullCheck(L_0);
		RuntimeObject* L_2;
		L_2 = VirtualFuncInvoker1< RuntimeObject*, int32_t >::Invoke(25 /* System.Object System.Collections.ArrayList::get_Item(System.Int32) */, L_0, L_1);
		return ((DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)CastclassSealed((RuntimeObject*)L_2, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var));
	}
}
// System.Int32 openDicom.DataStructure.DataSet.Sequence::get_Count()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sequence_get_Count_m68A3CC8B9371C0E570FCF3BEB959A4C21D81E959 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// get { return itemList.Count; }
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___itemList_1;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = VirtualFuncInvoker0< int32_t >::Invoke(21 /* System.Int32 System.Collections.ArrayList::get_Count() */, L_0);
		return L_1;
	}
}
// System.Boolean openDicom.DataStructure.DataSet.Sequence::get_IsEmpty()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Sequence_get_IsEmpty_m589F8EF1C112A56A28E1304C8A0EC840CE471CD6 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// get { return Count == 0; }
		int32_t L_0;
		L_0 = Sequence_get_Count_m68A3CC8B9371C0E570FCF3BEB959A4C21D81E959(__this, NULL);
		return (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::set_TransferSyntax(openDicom.Encoding.TransferSyntax)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_set_TransferSyntax_m50D66DEB15CE675934FBE8BEE32D78F282548115 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___value0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (value == null)
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_0 = ___value0;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		// transferSyntax = TransferSyntax.Default;
		il2cpp_codegen_runtime_class_init_inline(TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var);
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_1 = ((TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_StaticFields*)il2cpp_codegen_static_fields_for(TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var))->___Default_1;
		__this->___transferSyntax_2 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___transferSyntax_2), (void*)L_1);
		return;
	}

IL_000f:
	{
		// transferSyntax = value;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_2 = ___value0;
		__this->___transferSyntax_2 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___transferSyntax_2), (void*)L_2);
		// }
		return;
	}
}
// openDicom.Encoding.TransferSyntax openDicom.DataStructure.DataSet.Sequence::get_TransferSyntax()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// get { return transferSyntax; }
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_0 = __this->___transferSyntax_2;
		return L_0;
	}
}
// System.Int64 openDicom.DataStructure.DataSet.Sequence::get_StreamPosition()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t Sequence_get_StreamPosition_mDD78BD77FA30EC151B454C478CDBB8CC4510BC1E (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// get { return streamPosition; }
		int64_t L_0 = __this->___streamPosition_3;
		return L_0;
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence__ctor_mF9BB9E11FFF4A127D4CBDAD0519CF82D18D02C08 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// protected ArrayList itemList = new ArrayList();
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = (ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A*)il2cpp_codegen_object_new(ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		ArrayList__ctor_m07DC369002304B483B9FC41DBDAF4A25AC3C9F80(L_0, NULL);
		__this->___itemList_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___itemList_1), (void*)L_0);
		// private TransferSyntax transferSyntax = TransferSyntax.Default;
		il2cpp_codegen_runtime_class_init_inline(TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var);
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_1 = ((TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_StaticFields*)il2cpp_codegen_static_fields_for(TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var))->___Default_1;
		__this->___transferSyntax_2 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___transferSyntax_2), (void*)L_1);
		// protected long streamPosition = -1;
		__this->___streamPosition_3 = ((int64_t)(-1));
		// public Sequence() {}
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// public Sequence() {}
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::.ctor(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence__ctor_mFAB3DDAF14C8DA17AED1AA40C32712E124A9ADD6 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, const RuntimeMethod* method) 
{
	{
		// public Sequence(Stream stream): this(stream, null) {}
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_0 = ___stream0;
		Sequence__ctor_m3520CBA8D0740EBF3AA308F66DFF6DF8867F5FC5(__this, L_0, (TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F*)NULL, NULL);
		// public Sequence(Stream stream): this(stream, null) {}
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::.ctor(System.IO.Stream,openDicom.Encoding.TransferSyntax)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence__ctor_m3520CBA8D0740EBF3AA308F66DFF6DF8867F5FC5 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* ___transferSyntax1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// protected ArrayList itemList = new ArrayList();
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = (ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A*)il2cpp_codegen_object_new(ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		ArrayList__ctor_m07DC369002304B483B9FC41DBDAF4A25AC3C9F80(L_0, NULL);
		__this->___itemList_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___itemList_1), (void*)L_0);
		// private TransferSyntax transferSyntax = TransferSyntax.Default;
		il2cpp_codegen_runtime_class_init_inline(TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var);
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_1 = ((TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_StaticFields*)il2cpp_codegen_static_fields_for(TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F_il2cpp_TypeInfo_var))->___Default_1;
		__this->___transferSyntax_2 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___transferSyntax_2), (void*)L_1);
		// protected long streamPosition = -1;
		__this->___streamPosition_3 = ((int64_t)(-1));
		// public Sequence(Stream stream, TransferSyntax transferSyntax)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// TransferSyntax = transferSyntax;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_2 = ___transferSyntax1;
		Sequence_set_TransferSyntax_m50D66DEB15CE675934FBE8BEE32D78F282548115(__this, L_2, NULL);
		// LoadFrom(stream);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_3 = ___stream0;
		VirtualActionInvoker1< Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* >::Invoke(8 /* System.Void openDicom.DataStructure.DataSet.Sequence::LoadFrom(System.IO.Stream) */, __this, L_3);
		// }
		return;
	}
}
// System.Int32 openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.DataElement)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Sequence_Add_m488C2E75C38A5F14D33BB9BB39F39D971FD2CE3F (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* ___dataElement0, const RuntimeMethod* method) 
{
	{
		// return itemList.Add(dataElement);
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___itemList_1;
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_1 = ___dataElement0;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = VirtualFuncInvoker1< int32_t, RuntimeObject* >::Invoke(27 /* System.Int32 System.Collections.ArrayList::Add(System.Object) */, L_0, L_1);
		return L_2;
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.Sequence)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_Add_m4F7621AF822E72321740024C6EAFFF119C7A53C0 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* ___sequence0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	{
		// foreach (DataElement element in sequence)
		Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_0 = ___sequence0;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = Sequence_GetEnumerator_m076590366A9A9AA5BADFA65E09C1E656EC36BA1C(L_0, NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0027:
			{// begin finally (depth: 1)
				{
					RuntimeObject* L_2 = V_0;
					V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
					RuntimeObject* L_3 = V_2;
					if (!L_3)
					{
						goto IL_0037;
					}
				}
				{
					RuntimeObject* L_4 = V_2;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_0037:
				{
					return;
				}
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_001d_1;
			}

IL_0009_1:
			{
				// foreach (DataElement element in sequence)
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				RuntimeObject* L_6;
				L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1 /* System.Object System.Collections.IEnumerator::get_Current() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_5);
				V_1 = ((DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)CastclassSealed((RuntimeObject*)L_6, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var));
				// Add(element);
				DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_7 = V_1;
				int32_t L_8;
				L_8 = VirtualFuncInvoker1< int32_t, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* >::Invoke(7 /* System.Int32 openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.DataElement) */, __this, L_7);
			}

IL_001d_1:
			{
				// foreach (DataElement element in sequence)
				RuntimeObject* L_9 = V_0;
				NullCheck(L_9);
				bool L_10;
				L_10 = InterfaceFuncInvoker0< bool >::Invoke(0 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_9);
				if (L_10)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_0038;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0038:
	{
		// }
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::LoadFrom(System.IO.Stream)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_LoadFrom_mB59AE25D3A76D09E277C8A5A0BAFB4F5EA1441DB (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___stream0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0F0A5D424C28A42A7E1B29C286B7C516EF31B4FA);
		s_Il2CppMethodInitialized = true;
	}
	DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* V_0 = NULL;
	{
		// streamPosition = stream.Position;
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_0 = ___stream0;
		NullCheck(L_0);
		int64_t L_1;
		L_1 = VirtualFuncInvoker0< int64_t >::Invoke(12 /* System.Int64 System.IO.Stream::get_Position() */, L_0);
		__this->___streamPosition_3 = L_1;
		// DataElement element = new DataElement(stream, TransferSyntax);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_2 = ___stream0;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_3;
		L_3 = Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline(__this, NULL);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_4 = (DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)il2cpp_codegen_object_new(DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		DataElement__ctor_mC9771DB96F7483D64EB6025888342E639E3D4812(L_4, L_2, L_3, NULL);
		V_0 = L_4;
		goto IL_0042;
	}

IL_001b:
	{
		// isTrailingPadding = element.Tag.Equals("(0000,0000)");
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_5 = V_0;
		NullCheck(L_5);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_6;
		L_6 = DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC(L_5, NULL);
		NullCheck(L_6);
		bool L_7;
		L_7 = Tag_Equals_m309E81C20017DBD9AC3A33CB9DE94AEDE215A75D(L_6, _stringLiteral0F0A5D424C28A42A7E1B29C286B7C516EF31B4FA, NULL);
		// if ( ! isTrailingPadding)
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		// Add(element);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_8 = V_0;
		int32_t L_9;
		L_9 = VirtualFuncInvoker1< int32_t, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* >::Invoke(7 /* System.Int32 openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.DataElement) */, __this, L_8);
	}

IL_0035:
	{
		// element = new DataElement(stream, TransferSyntax);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_10 = ___stream0;
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_11;
		L_11 = Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline(__this, NULL);
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_12 = (DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)il2cpp_codegen_object_new(DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		NullCheck(L_12);
		DataElement__ctor_mC9771DB96F7483D64EB6025888342E639E3D4812(L_12, L_10, L_11, NULL);
		V_0 = L_12;
	}

IL_0042:
	{
		// while ( ! element.Tag.Equals(DelimiterTag) &&
		//     stream.Position < stream.Length)
		DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_13 = V_0;
		NullCheck(L_13);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_14;
		L_14 = DataElement_get_Tag_m4049183C5FA0A9F41C19CB394F9C6F7FA0DBF2BC(L_13, NULL);
		il2cpp_codegen_runtime_class_init_inline(Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_15 = ((Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_StaticFields*)il2cpp_codegen_static_fields_for(Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var))->___DelimiterTag_0;
		NullCheck(L_14);
		bool L_16;
		L_16 = Tag_Equals_m47E0DDE19DB60704948525D228A94DF7AF03C889(L_14, L_15, NULL);
		if (L_16)
		{
			goto IL_0062;
		}
	}
	{
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_17 = ___stream0;
		NullCheck(L_17);
		int64_t L_18;
		L_18 = VirtualFuncInvoker0< int64_t >::Invoke(12 /* System.Int64 System.IO.Stream::get_Position() */, L_17);
		Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_19 = ___stream0;
		NullCheck(L_19);
		int64_t L_20;
		L_20 = VirtualFuncInvoker0< int64_t >::Invoke(11 /* System.Int64 System.IO.Stream::get_Length() */, L_19);
		if ((((int64_t)L_18) < ((int64_t)L_20)))
		{
			goto IL_001b;
		}
	}

IL_0062:
	{
		// }
		return;
	}
}
// openDicom.DataStructure.DataSet.Sequence openDicom.DataStructure.DataSet.Sequence::TreeNodeToSequence(openDicom.DataStructure.DataSet.Sequence)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* Sequence_TreeNodeToSequence_m1B202FC1531B68F5EDA4C987FE7DF8F68D22F9FA (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* ___sequence0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* V_2 = NULL;
	RuntimeObject* V_3 = NULL;
	RuntimeObject* V_4 = NULL;
	RuntimeObject* V_5 = NULL;
	{
		// Sequence result = new Sequence();
		Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_0 = (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C*)il2cpp_codegen_object_new(Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Sequence__ctor_mF9BB9E11FFF4A127D4CBDAD0519CF82D18D02C08(L_0, NULL);
		V_0 = L_0;
		// foreach (DataElement element in sequence)
		Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_1 = ___sequence0;
		NullCheck(L_1);
		RuntimeObject* L_2;
		L_2 = Sequence_GetEnumerator_m076590366A9A9AA5BADFA65E09C1E656EC36BA1C(L_1, NULL);
		V_1 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_007d:
			{// begin finally (depth: 1)
				{
					RuntimeObject* L_3 = V_1;
					V_5 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
					RuntimeObject* L_4 = V_5;
					if (!L_4)
					{
						goto IL_0090;
					}
				}
				{
					RuntimeObject* L_5 = V_5;
					NullCheck(L_5);
					InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
				}

IL_0090:
				{
					return;
				}
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_0073_1;
			}

IL_000f_1:
			{
				// foreach (DataElement element in sequence)
				RuntimeObject* L_6 = V_1;
				NullCheck(L_6);
				RuntimeObject* L_7;
				L_7 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1 /* System.Object System.Collections.IEnumerator::get_Current() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_6);
				V_2 = ((DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F*)CastclassSealed((RuntimeObject*)L_7, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F_il2cpp_TypeInfo_var));
				// result.Add(element);
				Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_8 = V_0;
				DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_9 = V_2;
				NullCheck(L_8);
				int32_t L_10;
				L_10 = VirtualFuncInvoker1< int32_t, DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* >::Invoke(7 /* System.Int32 openDicom.DataStructure.DataSet.Sequence::Add(openDicom.DataStructure.DataSet.DataElement) */, L_8, L_9);
				// foreach (object value in element.Value)
				DataElement_tCF2D6B405653798E83760BF00038034DB9DE319F* L_11 = V_2;
				NullCheck(L_11);
				Value_tBB45E224730D00460EF4DF654DD83F51A9B05438* L_12;
				L_12 = DataElement_get_Value_mDA522A9539D1E16FD9CCFC2351704270E77709F0(L_11, NULL);
				NullCheck(L_12);
				RuntimeObject* L_13;
				L_13 = Value_GetEnumerator_m55A491E58A49E301D5290F92AEBA5B3755BF746A(L_12, NULL);
				V_3 = L_13;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_005f_1:
					{// begin finally (depth: 2)
						{
							RuntimeObject* L_14 = V_3;
							V_5 = ((RuntimeObject*)IsInst((RuntimeObject*)L_14, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
							RuntimeObject* L_15 = V_5;
							if (!L_15)
							{
								goto IL_0072_1;
							}
						}
						{
							RuntimeObject* L_16 = V_5;
							NullCheck(L_16);
							InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_16);
						}

IL_0072_1:
						{
							return;
						}
					}// end finally (depth: 2)
				});
				try
				{// begin try (depth: 2)
					{
						goto IL_0055_2;
					}

IL_0031_2:
					{
						// foreach (object value in element.Value)
						RuntimeObject* L_17 = V_3;
						NullCheck(L_17);
						RuntimeObject* L_18;
						L_18 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1 /* System.Object System.Collections.IEnumerator::get_Current() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_17);
						V_4 = L_18;
						// if (value is Sequence)
						RuntimeObject* L_19 = V_4;
						if (!((Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C*)IsInstClass((RuntimeObject*)L_19, Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var)))
						{
							goto IL_0055_2;
						}
					}
					{
						// result.Add(TreeNodeToSequence((Sequence) value));
						Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_20 = V_0;
						RuntimeObject* L_21 = V_4;
						Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_22;
						L_22 = Sequence_TreeNodeToSequence_m1B202FC1531B68F5EDA4C987FE7DF8F68D22F9FA(__this, ((Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C*)CastclassClass((RuntimeObject*)L_21, Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var)), NULL);
						NullCheck(L_20);
						Sequence_Add_m4F7621AF822E72321740024C6EAFFF119C7A53C0(L_20, L_22, NULL);
					}

IL_0055_2:
					{
						// foreach (object value in element.Value)
						RuntimeObject* L_23 = V_3;
						NullCheck(L_23);
						bool L_24;
						L_24 = InterfaceFuncInvoker0< bool >::Invoke(0 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_23);
						if (L_24)
						{
							goto IL_0031_2;
						}
					}
					{
						goto IL_0073_1;
					}
				}// end try (depth: 2)
				catch(Il2CppExceptionWrapper& e)
				{
					__finallyBlock.StoreException(e.ex);
				}
			}

IL_0073_1:
			{
				// foreach (DataElement element in sequence)
				RuntimeObject* L_25 = V_1;
				NullCheck(L_25);
				bool L_26;
				L_26 = InterfaceFuncInvoker0< bool >::Invoke(0 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_25);
				if (L_26)
				{
					goto IL_000f_1;
				}
			}
			{
				goto IL_0091;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0091:
	{
		// return result;
		Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_27 = V_0;
		return L_27;
	}
}
// openDicom.DataStructure.DataSet.Sequence openDicom.DataStructure.DataSet.Sequence::GetJointSubsequences()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* Sequence_GetJointSubsequences_m022675DD2F7B4F38B20F0011DC3A10F60FC333EC (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// return TreeNodeToSequence(this);
		Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* L_0;
		L_0 = Sequence_TreeNodeToSequence_m1B202FC1531B68F5EDA4C987FE7DF8F68D22F9FA(__this, __this, NULL);
		return L_0;
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_Clear_m35C93BEA7B3A0C5CBB0549ED8F8E295673A6E4E0 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// itemList.Clear();
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___itemList_1;
		NullCheck(L_0);
		VirtualActionInvoker0::Invoke(29 /* System.Void System.Collections.ArrayList::Clear() */, L_0);
		// }
		return;
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::Sort()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence_Sort_m5E7A7055D8E71374A6B96575D61C02C72624EB42 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// itemList.Sort();
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___itemList_1;
		NullCheck(L_0);
		VirtualActionInvoker0::Invoke(42 /* System.Void System.Collections.ArrayList::Sort() */, L_0);
		// }
		return;
	}
}
// openDicom.DataStructure.DataSet.DataElement[] openDicom.DataStructure.DataSet.Sequence::ToArray()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DataElementU5BU5D_tA692899F5BBF2F54DF713616F87C97FDF6F8A3F9* Sequence_ToArray_m3A4AEA91B2DC56D3A59C877A6E8A51A78F633313 (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DataElementU5BU5D_tA692899F5BBF2F54DF713616F87C97FDF6F8A3F9_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return (DataElement[]) itemList.ToArray();
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___itemList_1;
		NullCheck(L_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1;
		L_1 = VirtualFuncInvoker0< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* >::Invoke(44 /* System.Object[] System.Collections.ArrayList::ToArray() */, L_0);
		return ((DataElementU5BU5D_tA692899F5BBF2F54DF713616F87C97FDF6F8A3F9*)Castclass((RuntimeObject*)L_1, DataElementU5BU5D_tA692899F5BBF2F54DF713616F87C97FDF6F8A3F9_il2cpp_TypeInfo_var));
	}
}
// System.Collections.IEnumerator openDicom.DataStructure.DataSet.Sequence::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Sequence_GetEnumerator_m076590366A9A9AA5BADFA65E09C1E656EC36BA1C (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// return itemList.GetEnumerator();
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___itemList_1;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = VirtualFuncInvoker0< RuntimeObject* >::Invoke(35 /* System.Collections.IEnumerator System.Collections.ArrayList::GetEnumerator() */, L_0);
		return L_1;
	}
}
// System.Void openDicom.DataStructure.DataSet.Sequence::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Sequence__cctor_m97BEABBE87FEAFD77A650111605083A647DED40F (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9441854635B34F2C803AA684E62CC57FC4482357);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAB33FE70A8F926088C384248059A27AE458AE755);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static readonly Tag DelimiterTag = new Tag("FFFE", "E0DD");
		Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D* L_0 = (Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D*)il2cpp_codegen_object_new(Tag_t53DA63B621AAD03227B97D5EF513553FEA20FC3D_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Tag__ctor_mD73A46B61F11C5361434F8746E48AE831D088EEF(L_0, _stringLiteralAB33FE70A8F926088C384248059A27AE458AE755, _stringLiteral9441854635B34F2C803AA684E62CC57FC4482357, NULL);
		((Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_StaticFields*)il2cpp_codegen_static_fields_for(Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var))->___DelimiterTag_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_StaticFields*)il2cpp_codegen_static_fields_for(Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C_il2cpp_TypeInfo_var))->___DelimiterTag_0), (void*)L_0);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.UInt32 <PrivateImplementationDetails>::ComputeStringHash(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t U3CPrivateImplementationDetailsU3E_ComputeStringHash_m6EA1F233618497AEFF8902A5EDFA24C74E2F2876 (String_t* ___s0, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		String_t* L_0 = ___s0;
		if (!L_0)
		{
			goto IL_002a;
		}
	}
	{
		V_0 = ((int32_t)-2128831035);
		V_1 = 0;
		goto IL_0021;
	}

IL_000d:
	{
		String_t* L_1 = ___s0;
		int32_t L_2 = V_1;
		NullCheck(L_1);
		Il2CppChar L_3;
		L_3 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_1, L_2, NULL);
		uint32_t L_4 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_multiply(((int32_t)((int32_t)L_3^(int32_t)L_4)), ((int32_t)16777619)));
		int32_t L_5 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_0021:
	{
		int32_t L_6 = V_1;
		String_t* L_7 = ___s0;
		NullCheck(L_7);
		int32_t L_8;
		L_8 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_7, NULL);
		if ((((int32_t)L_6) < ((int32_t)L_8)))
		{
			goto IL_000d;
		}
	}

IL_002a:
	{
		uint32_t L_9 = V_0;
		return L_9;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* Sequence_get_TransferSyntax_m7E9675A0A9220408E4E9EB1AA6BF5314359424E8_inline (Sequence_t488DBB4DF7EC4823ACC248536E2B40CB74C5CA6C* __this, const RuntimeMethod* method) 
{
	{
		// get { return transferSyntax; }
		TransferSyntax_t861F5AE8C252654B3716C862E7E1F358733FF64F* L_0 = __this->___transferSyntax_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength_4;
		return L_0;
	}
}
