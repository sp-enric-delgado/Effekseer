struct VS_Input
{
    float3 Pos;
    float3 Normal;
    float3 Binormal;
    float3 Tangent;
    float2 UV;
    float4 Color;
    uint Index;
};

struct VS_Output
{
    float4 PosVS;
    float2 UV;
    float4 ProjBinormal;
    float4 ProjTangent;
    float4 PosP;
    float4 Color;
};

static const VS_Output _57 = { 0.0f.xxxx, 0.0f.xx, 0.0f.xxxx, 0.0f.xxxx, 0.0f.xxxx, 0.0f.xxxx };

cbuffer VS_ConstantBuffer : register(b0)
{
    column_major float4x4 _31_mCameraProj : packoffset(c0);
    column_major float4x4 _31_mModel[40] : packoffset(c4);
    float4 _31_fUV[40] : packoffset(c164);
    float4 _31_fModelColor[40] : packoffset(c204);
    float4 _31_fLightDirection : packoffset(c244);
    float4 _31_fLightColor : packoffset(c245);
    float4 _31_fLightAmbient : packoffset(c246);
    float4 _31_mUVInversed : packoffset(c247);
};


static float4 gl_Position;
static int gl_InstanceIndex;
static float3 Input_Pos;
static float3 Input_Normal;
static float3 Input_Binormal;
static float3 Input_Tangent;
static float2 Input_UV;
static float4 Input_Color;
static float2 _entryPointOutput_UV;
static float4 _entryPointOutput_ProjBinormal;
static float4 _entryPointOutput_ProjTangent;
static float4 _entryPointOutput_PosP;
static float4 _entryPointOutput_Color;

struct SPIRV_Cross_Input
{
    float3 Input_Pos : TEXCOORD0;
    float3 Input_Normal : TEXCOORD1;
    float3 Input_Binormal : TEXCOORD2;
    float3 Input_Tangent : TEXCOORD3;
    float2 Input_UV : TEXCOORD4;
    float4 Input_Color : TEXCOORD5;
    uint gl_InstanceIndex : SV_InstanceID;
};

struct SPIRV_Cross_Output
{
    centroid float2 _entryPointOutput_UV : TEXCOORD0;
    float4 _entryPointOutput_ProjBinormal : TEXCOORD1;
    float4 _entryPointOutput_ProjTangent : TEXCOORD2;
    float4 _entryPointOutput_PosP : TEXCOORD3;
    centroid float4 _entryPointOutput_Color : TEXCOORD4;
    float4 gl_Position : SV_Position;
};

VS_Output _main(VS_Input Input)
{
    uint index = Input.Index;
    float4x4 matModel = _31_mModel[index];
    float4 uv = _31_fUV[index];
    float4 modelColor = _31_fModelColor[index] * Input.Color;
    VS_Output Output = _57;
    float4 localPosition = float4(Input.Pos.x, Input.Pos.y, Input.Pos.z, 1.0f);
    localPosition = mul(matModel, localPosition);
    Output.PosVS = mul(_31_mCameraProj, localPosition);
    Output.Color = modelColor;
    Output.UV.x = (Input.UV.x * uv.z) + uv.x;
    Output.UV.y = (Input.UV.y * uv.w) + uv.y;
    float4 localNormal = float4(Input.Normal.x, Input.Normal.y, Input.Normal.z, 0.0f);
    float4 localBinormal = float4(Input.Binormal.x, Input.Binormal.y, Input.Binormal.z, 0.0f);
    float4 localTangent = float4(Input.Tangent.x, Input.Tangent.y, Input.Tangent.z, 0.0f);
    localNormal = mul(matModel, localNormal);
    localBinormal = mul(matModel, localBinormal);
    localTangent = mul(matModel, localTangent);
    localNormal = normalize(localNormal);
    localBinormal = normalize(localBinormal);
    localTangent = normalize(localTangent);
    localBinormal = localPosition + localBinormal;
    localTangent = localPosition + localTangent;
    Output.ProjBinormal = mul(_31_mCameraProj, localBinormal);
    Output.ProjTangent = mul(_31_mCameraProj, localTangent);
    Output.UV.y = _31_mUVInversed.x + (_31_mUVInversed.y * Output.UV.y);
    Output.PosP = Output.PosVS;
    return Output;
}

void vert_main()
{
    VS_Input Input;
    Input.Pos = Input_Pos;
    Input.Normal = Input_Normal;
    Input.Binormal = Input_Binormal;
    Input.Tangent = Input_Tangent;
    Input.UV = Input_UV;
    Input.Color = Input_Color;
    Input.Index = uint(gl_InstanceIndex);
    VS_Output flattenTemp = _main(Input);
    gl_Position = flattenTemp.PosVS;
    _entryPointOutput_UV = flattenTemp.UV;
    _entryPointOutput_ProjBinormal = flattenTemp.ProjBinormal;
    _entryPointOutput_ProjTangent = flattenTemp.ProjTangent;
    _entryPointOutput_PosP = flattenTemp.PosP;
    _entryPointOutput_Color = flattenTemp.Color;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    gl_InstanceIndex = int(stage_input.gl_InstanceIndex);
    Input_Pos = stage_input.Input_Pos;
    Input_Normal = stage_input.Input_Normal;
    Input_Binormal = stage_input.Input_Binormal;
    Input_Tangent = stage_input.Input_Tangent;
    Input_UV = stage_input.Input_UV;
    Input_Color = stage_input.Input_Color;
    vert_main();
    SPIRV_Cross_Output stage_output;
    stage_output.gl_Position = gl_Position;
    stage_output._entryPointOutput_UV = _entryPointOutput_UV;
    stage_output._entryPointOutput_ProjBinormal = _entryPointOutput_ProjBinormal;
    stage_output._entryPointOutput_ProjTangent = _entryPointOutput_ProjTangent;
    stage_output._entryPointOutput_PosP = _entryPointOutput_PosP;
    stage_output._entryPointOutput_Color = _entryPointOutput_Color;
    return stage_output;
}
