#pragma once

#include <vector>
#include <map>
#include <string>
#include <cstdint>

#if defined (_WIN32) && defined(HLSLCC_DYNLIB)
    #define HLSLCC_APIENTRY __stdcall
    #if defined(libHLSLcc_EXPORTS)
        #define HLSLCC_API __declspec(dllexport)
    #else
        #define HLSLCC_API __declspec(dllimport)
    #endif
#else
    #define HLSLCC_APIENTRY
    #define HLSLCC_API
#endif

enum GLLang
{
    LANG_DEFAULT,// Depends on the HLSL shader model.
    LANG_ES_100,
    LANG_ES_300,
    LANG_120,
    LANG_130,
    LANG_140,
    LANG_150,
    LANG_330,
    LANG_400,
    LANG_410,
    LANG_420,
    LANG_430,
    LANG_440,
};
const int LANG_ES_310 = 10;

enum {MAX_SHADER_VEC4_OUTPUT = 512};
enum {MAX_SHADER_VEC4_INPUT = 512};
enum {MAX_TEXTURES = 128};
enum {MAX_FORK_PHASES = 2};
enum {MAX_FUNCTION_BODIES = 1024};
enum {MAX_CLASS_TYPES = 1024};
enum {MAX_FUNCTION_POINTERS = 128};

//Reflection
#define MAX_REFLECT_STRING_LENGTH 512
#define MAX_SHADER_VARS 256
#define MAX_CBUFFERS 256
#define MAX_UAV 256
#define MAX_FUNCTION_TABLES 256
#define MAX_RESOURCE_BINDINGS 256

enum SPECIAL_NAME
{
    NAME_UNDEFINED = 0,
    NAME_POSITION = 1,
    NAME_CLIP_DISTANCE = 2,
    NAME_CULL_DISTANCE = 3,
    NAME_RENDER_TARGET_ARRAY_INDEX = 4,
    NAME_VIEWPORT_ARRAY_INDEX = 5,
    NAME_VERTEX_ID = 6,
    NAME_PRIMITIVE_ID = 7,
    NAME_INSTANCE_ID = 8,
    NAME_IS_FRONT_FACE = 9,
    NAME_SAMPLE_INDEX = 10,
    // The following are added for D3D11
    NAME_FINAL_QUAD_U_EQ_0_EDGE_TESSFACTOR = 11, 
    NAME_FINAL_QUAD_V_EQ_0_EDGE_TESSFACTOR = 12, 
    NAME_FINAL_QUAD_U_EQ_1_EDGE_TESSFACTOR = 13, 
    NAME_FINAL_QUAD_V_EQ_1_EDGE_TESSFACTOR = 14, 
    NAME_FINAL_QUAD_U_INSIDE_TESSFACTOR = 15, 
    NAME_FINAL_QUAD_V_INSIDE_TESSFACTOR = 16, 
    NAME_FINAL_TRI_U_EQ_0_EDGE_TESSFACTOR = 17, 
    NAME_FINAL_TRI_V_EQ_0_EDGE_TESSFACTOR = 18, 
    NAME_FINAL_TRI_W_EQ_0_EDGE_TESSFACTOR = 19, 
    NAME_FINAL_TRI_INSIDE_TESSFACTOR = 20, 
    NAME_FINAL_LINE_DETAIL_TESSFACTOR = 21,
    NAME_FINAL_LINE_DENSITY_TESSFACTOR = 22,
};


enum INOUT_COMPONENT_TYPE 
{
  INOUT_COMPONENT_UNKNOWN  = 0,
  INOUT_COMPONENT_UINT32   = 1,
  INOUT_COMPONENT_SINT32   = 2,
  INOUT_COMPONENT_FLOAT32  = 3
};

enum MIN_PRECISION 
{ 
  MIN_PRECISION_DEFAULT    = 0,
  MIN_PRECISION_FLOAT_16   = 1,
  MIN_PRECISION_FLOAT_2_8  = 2,
  MIN_PRECISION_RESERVED   = 3,
  MIN_PRECISION_SINT_16    = 4,
  MIN_PRECISION_UINT_16    = 5,
  MIN_PRECISION_ANY_16     = 0xf0,
  MIN_PRECISION_ANY_10     = 0xf1
};

struct InOutSignature
{
    std::string SemanticName;
    uint32_t ui32SemanticIndex;
    SPECIAL_NAME eSystemValueType;
    INOUT_COMPONENT_TYPE eComponentType;
    uint32_t ui32Register;
    uint32_t ui32Mask;
    uint32_t ui32ReadWriteMask;

	uint32_t ui32Stream;
	MIN_PRECISION eMinPrec;
};

enum ResourceType_TAG
{
    RTYPE_CBUFFER,//0
    RTYPE_TBUFFER,//1
    RTYPE_TEXTURE,//2
    RTYPE_SAMPLER,//3
    RTYPE_UAV_RWTYPED,//4
    RTYPE_STRUCTURED,//5
    RTYPE_UAV_RWSTRUCTURED,//6
    RTYPE_BYTEADDRESS,//7
    RTYPE_UAV_RWBYTEADDRESS,//8
    RTYPE_UAV_APPEND_STRUCTURED,//9
    RTYPE_UAV_CONSUME_STRUCTURED,//10
    RTYPE_UAV_RWSTRUCTURED_WITH_COUNTER,//11
};
using ResourceType = ResourceType_TAG;

enum ResourceGroup_TAG 
{
	RGROUP_CBUFFER,
	RGROUP_TEXTURE,
	RGROUP_SAMPLER,
	RGROUP_UAV,
	RGROUP_COUNT,
};
using ResourceGroup = ResourceGroup_TAG;

enum REFLECT_RESOURCE_DIMENSION
{
    REFLECT_RESOURCE_DIMENSION_UNKNOWN = 0,
    REFLECT_RESOURCE_DIMENSION_BUFFER = 1,
    REFLECT_RESOURCE_DIMENSION_TEXTURE1D = 2,
    REFLECT_RESOURCE_DIMENSION_TEXTURE1DARRAY = 3,
    REFLECT_RESOURCE_DIMENSION_TEXTURE2D = 4,
    REFLECT_RESOURCE_DIMENSION_TEXTURE2DARRAY = 5,
    REFLECT_RESOURCE_DIMENSION_TEXTURE2DMS = 6,
    REFLECT_RESOURCE_DIMENSION_TEXTURE2DMSARRAY = 7,
    REFLECT_RESOURCE_DIMENSION_TEXTURE3D = 8,
    REFLECT_RESOURCE_DIMENSION_TEXTURECUBE = 9,
    REFLECT_RESOURCE_DIMENSION_TEXTURECUBEARRAY = 10,
    REFLECT_RESOURCE_DIMENSION_BUFFEREX = 11,
};

struct ResourceBinding_TAG
{
    std::string Name;
    ResourceType eType;
    uint32_t ui32BindPoint;
    uint32_t ui32BindCount;
    uint32_t ui32Flags;
    REFLECT_RESOURCE_DIMENSION eDimension;
    uint32_t ui32ReturnType;
    uint32_t ui32NumSamples;
};
using ResourceBinding = ResourceBinding_TAG;

enum SHADER_VARIABLE_TYPE 
{
  SVT_VOID                         = 0,
  SVT_BOOL                         = 1,
  SVT_INT                          = 2,
  SVT_FLOAT                        = 3,
  SVT_STRING                       = 4,
  SVT_TEXTURE                      = 5,
  SVT_TEXTURE1D                    = 6,
  SVT_TEXTURE2D                    = 7,
  SVT_TEXTURE3D                    = 8,
  SVT_TEXTURECUBE                  = 9,
  SVT_SAMPLER                      = 10,
  SVT_PIXELSHADER                  = 15,
  SVT_VERTEXSHADER                 = 16,
  SVT_UINT                         = 19,
  SVT_UINT8                        = 20,
  SVT_GEOMETRYSHADER               = 21,
  SVT_RASTERIZER                   = 22,
  SVT_DEPTHSTENCIL                 = 23,
  SVT_BLEND                        = 24,
  SVT_BUFFER                       = 25,
  SVT_CBUFFER                      = 26,
  SVT_TBUFFER                      = 27,
  SVT_TEXTURE1DARRAY               = 28,
  SVT_TEXTURE2DARRAY               = 29,
  SVT_RENDERTARGETVIEW             = 30,
  SVT_DEPTHSTENCILVIEW             = 31,
  SVT_TEXTURE2DMS                  = 32,
  SVT_TEXTURE2DMSARRAY             = 33,
  SVT_TEXTURECUBEARRAY             = 34,
  SVT_HULLSHADER                   = 35,
  SVT_DOMAINSHADER                 = 36,
  SVT_INTERFACE_POINTER            = 37,
  SVT_COMPUTESHADER                = 38,
  SVT_DOUBLE                       = 39,
  SVT_RWTEXTURE1D                  = 40,
  SVT_RWTEXTURE1DARRAY             = 41,
  SVT_RWTEXTURE2D                  = 42,
  SVT_RWTEXTURE2DARRAY             = 43,
  SVT_RWTEXTURE3D                  = 44,
  SVT_RWBUFFER                     = 45,
  SVT_BYTEADDRESS_BUFFER           = 46,
  SVT_RWBYTEADDRESS_BUFFER         = 47,
  SVT_STRUCTURED_BUFFER            = 48,
  SVT_RWSTRUCTURED_BUFFER          = 49,
  SVT_APPEND_STRUCTURED_BUFFER     = 50,
  SVT_CONSUME_STRUCTURED_BUFFER    = 51,

  SVT_FORCE_DWORD                  = 0x7fffffff
};

enum SHADER_VARIABLE_CLASS 
{
  SVC_SCALAR               = 0,
  SVC_VECTOR               = ( SVC_SCALAR + 1 ),
  SVC_MATRIX_ROWS          = ( SVC_VECTOR + 1 ),
  SVC_MATRIX_COLUMNS       = ( SVC_MATRIX_ROWS + 1 ),
  SVC_OBJECT               = ( SVC_MATRIX_COLUMNS + 1 ),
  SVC_STRUCT               = ( SVC_OBJECT + 1 ),
  SVC_INTERFACE_CLASS      = ( SVC_STRUCT + 1 ),
  SVC_INTERFACE_POINTER    = ( SVC_INTERFACE_CLASS + 1 ),
  SVC_FORCE_DWORD          = 0x7fffffff
};

struct ShaderVarType 
{
    SHADER_VARIABLE_CLASS Class{};
    SHADER_VARIABLE_TYPE  Type{};
    uint32_t              Rows{};
    uint32_t              Columns{};
    uint32_t              Elements{};
    uint32_t              MemberCount{};
    uint32_t              Offset{};
    uint32_t              ParentCount{};
    ShaderVarType*        Parent = nullptr;
    ShaderVarType*        Members = nullptr;

    std::string           Name;
    std::string           FullName;

    ShaderVarType() = default;
    ~ShaderVarType()
    {
        delete[] Members;
    }
};

struct ShaderVar
{
    std::string Name;
    std::vector<uint32_t> pui32DefaultValues;
	//Offset/Size in bytes.
    uint32_t ui32StartOffset;
    uint32_t ui32Size;

    ShaderVarType sType;
    bool haveDefaultValue;
};

struct ConstantBuffer
{
    std::string Name;

    std::vector<ShaderVar> asVars;

    uint32_t ui32TotalSizeInBytes;

	int iUnsized;
};

struct ClassType
{
    std::string Name;
    uint16_t ui16ID;
    uint16_t ui16ConstBufStride;
    uint16_t ui16Texture;
    uint16_t ui16Sampler;
};

struct ClassInstance_TAG
{
    std::string Name;
    uint16_t ui16ID;
    uint16_t ui16ConstBuf;
    uint16_t ui16ConstBufOffset;
    uint16_t ui16Texture;
    uint16_t ui16Sampler;
};
using ClassInstance = ClassInstance_TAG;

enum TESSELLATOR_PARTITIONING
{
    TESSELLATOR_PARTITIONING_UNDEFINED       = 0,
    TESSELLATOR_PARTITIONING_INTEGER         = 1,
    TESSELLATOR_PARTITIONING_POW2            = 2,
    TESSELLATOR_PARTITIONING_FRACTIONAL_ODD  = 3,
    TESSELLATOR_PARTITIONING_FRACTIONAL_EVEN = 4
};

enum TESSELLATOR_OUTPUT_PRIMITIVE
{
    TESSELLATOR_OUTPUT_UNDEFINED     = 0,
    TESSELLATOR_OUTPUT_POINT         = 1,
    TESSELLATOR_OUTPUT_LINE          = 2,
    TESSELLATOR_OUTPUT_TRIANGLE_CW   = 3,
    TESSELLATOR_OUTPUT_TRIANGLE_CCW  = 4
};

struct ShaderInfo
{
    uint32_t ui32MajorVersion;
    uint32_t ui32MinorVersion;

    uint32_t ui32NumInputSignatures;
    InOutSignature* psInputSignatures;

    uint32_t ui32NumOutputSignatures;
    InOutSignature* psOutputSignatures;

	uint32_t ui32NumPatchConstantSignatures;
    InOutSignature* psPatchConstantSignatures;

    uint32_t ui32NumResourceBindings;
    ResourceBinding* psResourceBindings;

    uint32_t ui32NumConstantBuffers;
    ConstantBuffer* psConstantBuffers;
    ConstantBuffer* psThisPointerConstBuffer;

    uint32_t ui32NumClassTypes;
    ClassType* psClassTypes;

    uint32_t ui32NumClassInstances;
    ClassInstance* psClassInstances;

    //Func table ID to class name ID.
    std::map<int, uint32_t> aui32TableIDToTypeID;

    std::map<int, uint32_t> aui32ResourceMap[RGROUP_COUNT];

    TESSELLATOR_PARTITIONING eTessPartitioning;
    TESSELLATOR_OUTPUT_PRIMITIVE eTessOutPrim;

	ShaderInfo() :
		ui32MajorVersion(0),
		ui32MinorVersion(0),
		ui32NumInputSignatures(0),
		psInputSignatures(0),
		ui32NumOutputSignatures(0),
		psOutputSignatures(0), 
		ui32NumPatchConstantSignatures(0),
		psPatchConstantSignatures(0),
		ui32NumResourceBindings(0),
		psResourceBindings(0),
		ui32NumConstantBuffers(0),
		psConstantBuffers(0),
		psThisPointerConstBuffer(0),
		ui32NumClassTypes(0),
		psClassTypes(0),
		ui32NumClassInstances(0),
		psClassInstances(0),
		aui32TableIDToTypeID(),
		aui32ResourceMap(),
        eTessPartitioning(),
        eTessOutPrim()
	{
	}
};

enum INTERPOLATION_MODE
{
    INTERPOLATION_UNDEFINED = 0,
    INTERPOLATION_CONSTANT = 1,
    INTERPOLATION_LINEAR = 2,
    INTERPOLATION_LINEAR_CENTROID = 3,
    INTERPOLATION_LINEAR_NOPERSPECTIVE = 4,
    INTERPOLATION_LINEAR_NOPERSPECTIVE_CENTROID = 5,
    INTERPOLATION_LINEAR_SAMPLE = 6,
    INTERPOLATION_LINEAR_NOPERSPECTIVE_SAMPLE = 7,
};

