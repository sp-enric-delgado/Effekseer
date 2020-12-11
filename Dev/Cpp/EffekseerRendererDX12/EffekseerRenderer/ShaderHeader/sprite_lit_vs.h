#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tvs_4_0 /Emain /Fh ShaderHeader/sprite_lit_vs.h
//    Shader/sprite_lit_vs.fx
//
//
// Buffer Definitions: 
//
// cbuffer VS_ConstantBuffer
// {
//
//   float4x4 _62_mCamera;              // Offset:    0 Size:    64
//   float4x4 _62_mProj;                // Offset:   64 Size:    64
//   float4 _62_mUVInversed;            // Offset:  128 Size:    16
//   float4 _62_mflipbookParameter;     // Offset:  144 Size:    16 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// VS_ConstantBuffer                 cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// TEXCOORD                 0   xyz         0     NONE  float   xyz 
// TEXCOORD                 1   xyzw        1     NONE  float   xyzw
// TEXCOORD                 2   xyzw        2     NONE  float   xyz 
// TEXCOORD                 3   xyzw        3     NONE  float   xyz 
// TEXCOORD                 4   xy          4     NONE  float   xy  
// TEXCOORD                 5   xy          5     NONE  float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// TEXCOORD                 0   xyzw        0     NONE  float   xyzw
// TEXCOORD                 1   xy          1     NONE  float   xy  
// TEXCOORD                 2     zw        1     NONE  float     zw
// TEXCOORD                 3   xyz         2     NONE  float   xyz 
// TEXCOORD                 4   xyz         3     NONE  float   xyz 
// TEXCOORD                 5   xyz         4     NONE  float   xyz 
// TEXCOORD                 6   xyz         5     NONE  float   xyz 
// TEXCOORD                 7   xy          6     NONE  float   xy  
// TEXCOORD                 8   xyzw        7     NONE  float   xyzw
// SV_Position              0   xyzw        8      POS  float   xyzw
//
vs_4_0
dcl_constantbuffer cb0[9], immediateIndexed
dcl_input v0.xyz
dcl_input v1.xyzw
dcl_input v2.xyz
dcl_input v3.xyz
dcl_input v4.xy
dcl_output o0.xyzw
dcl_output o1.xy
dcl_output o1.zw
dcl_output o2.xyz
dcl_output o3.xyz
dcl_output o4.xyz
dcl_output o5.xyz
dcl_output o6.xy
dcl_output o7.xyzw
dcl_output_siv o8.xyzw, position
dcl_temps 3
mov o0.xyzw, v1.xyzw
mad o1.yw, cb0[8].yyyy, v4.yyyy, cb0[8].xxxx
mov o1.xz, v4.xxxx
mov o2.xyz, v0.xyzx
add r0.xyz, v2.xyzx, l(-0.500000, -0.500000, -0.500000, 0.000000)
add r0.xyz, r0.xyzx, r0.xyzx
mov o3.xyz, r0.xyzx
add r1.xyz, v3.xyzx, l(-0.500000, -0.500000, -0.500000, 0.000000)
add r1.xyz, r1.xyzx, r1.xyzx
mov o4.xyz, r1.xyzx
mul r2.xyz, r0.zxyz, r1.yzxy
mad o5.xyz, r0.yzxy, r1.zxyz, -r2.xyzx
mul r0.xyzw, v0.yyyy, cb0[1].xyzw
mad r0.xyzw, cb0[0].xyzw, v0.xxxx, r0.xyzw
mad r0.xyzw, cb0[2].xyzw, v0.zzzz, r0.xyzw
add r0.xyzw, r0.xyzw, cb0[3].xyzw
mul r1.xyzw, r0.yyyy, cb0[5].xyzw
mad r1.xyzw, cb0[4].xyzw, r0.xxxx, r1.xyzw
mad r1.xyzw, cb0[6].xyzw, r0.zzzz, r1.xyzw
mad r0.xyzw, cb0[7].xyzw, r0.wwww, r1.xyzw
div r1.xy, r0.xyxx, r0.wwww
mad r1.xy, r1.xyxx, l(1.000000, -1.000000, 0.000000, 0.000000), l(1.000000, 1.000000, 0.000000, 0.000000)
mul o6.xy, r1.xyxx, l(0.500000, 0.500000, 0.000000, 0.000000)
mov o7.xyzw, r0.xyzw
mov o8.xyzw, r0.xyzw
ret 
// Approximately 26 instruction slots used
#endif

const BYTE g_main[] =
{
     68,  88,  66,  67,  36, 207, 
     82, 195, 245,  69, 186, 185, 
     43,  52,  87, 231, 124,  73, 
    184,  68,   1,   0,   0,   0, 
    228,   7,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    148,   1,   0,   0,  64,   2, 
      0,   0,  88,   3,   0,   0, 
    104,   7,   0,   0,  82,  68, 
     69,  70,  88,   1,   0,   0, 
      1,   0,   0,   0,  80,   0, 
      0,   0,   1,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    254, 255,  16,   1,   0,   0, 
     39,   1,   0,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     86,  83,  95,  67, 111, 110, 
    115, 116,  97, 110, 116,  66, 
    117, 102, 102, 101, 114,   0, 
    171, 171,  60,   0,   0,   0, 
      4,   0,   0,   0, 104,   0, 
      0,   0, 160,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 200,   0,   0,   0, 
      0,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    212,   0,   0,   0,   0,   0, 
      0,   0, 228,   0,   0,   0, 
     64,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    212,   0,   0,   0,   0,   0, 
      0,   0, 238,   0,   0,   0, 
    128,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   1,   0,   0,   0,   0, 
      0,   0,  16,   1,   0,   0, 
    144,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,   0,   0, 
      0,   0,  95,  54,  50,  95, 
    109,  67,  97, 109, 101, 114, 
     97,   0,   3,   0,   3,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     95,  54,  50,  95, 109,  80, 
    114, 111, 106,   0,  95,  54, 
     50,  95, 109,  85,  86,  73, 
    110, 118, 101, 114, 115, 101, 
    100,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  95,  54,  50,  95, 
    109, 102, 108, 105, 112,  98, 
    111, 111, 107,  80,  97, 114, 
     97, 109, 101, 116, 101, 114, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  57,  46,  57, 
     53,  50,  46,  51,  49,  49, 
     49,   0,  73,  83,  71,  78, 
    164,   0,   0,   0,   6,   0, 
      0,   0,   8,   0,   0,   0, 
    152,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   7,   0,   0, 
    152,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,  15,   0,   0, 
    152,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,  15,   7,   0,   0, 
    152,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,  15,   7,   0,   0, 
    152,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   3,   3,   0,   0, 
    152,   0,   0,   0,   5,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,   3,   0,   0,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171, 171, 171, 
     79,  83,  71,  78,  16,   1, 
      0,   0,  10,   0,   0,   0, 
      8,   0,   0,   0, 248,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0, 248,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      3,  12,   0,   0, 248,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     12,   3,   0,   0, 248,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      7,   8,   0,   0, 248,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   8,   0,   0, 248,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
      7,   8,   0,   0, 248,   0, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
      7,   8,   0,   0, 248,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
      3,  12,   0,   0, 248,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
     15,   0,   0,   0,   1,   1, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
     15,   0,   0,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  83,  86,  95,  80, 111, 
    115, 105, 116, 105, 111, 110, 
      0, 171, 171, 171,  83,  72, 
     68,  82,   8,   4,   0,   0, 
     64,   0,   1,   0,   2,   1, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   0,   0,   0,   0, 
     95,   0,   0,   3, 242,  16, 
     16,   0,   1,   0,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   2,   0,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   3,   0,   0,   0, 
     95,   0,   0,   3,  50,  16, 
     16,   0,   4,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    101,   0,   0,   3,  50,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 194,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   3,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   4,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   5,   0,   0,   0, 
    101,   0,   0,   3,  50,  32, 
     16,   0,   6,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   7,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   8,   0,   0,   0, 
      1,   0,   0,   0, 104,   0, 
      0,   2,   3,   0,   0,   0, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  30,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  11, 
    162,  32,  16,   0,   1,   0, 
      0,   0,  86, 133,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  86,  21,  16,   0, 
      4,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  54,   0, 
      0,   5,  82,  32,  16,   0, 
      1,   0,   0,   0,   6,  16, 
     16,   0,   4,   0,   0,   0, 
     54,   0,   0,   5, 114,  32, 
     16,   0,   2,   0,   0,   0, 
     70,  18,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0, 191, 
      0,   0,   0, 191,   0,   0, 
      0, 191,   0,   0,   0,   0, 
      0,   0,   0,   7, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 114,  32,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,  10, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  18,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0, 191,   0,   0, 
      0, 191,   0,   0,   0, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   7, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   5, 
    114,  32,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      2,   0,   0,   0,  38,   9, 
     16,   0,   0,   0,   0,   0, 
    150,   4,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    114,  32,  16,   0,   5,   0, 
      0,   0, 150,   4,  16,   0, 
      0,   0,   0,   0,  38,   9, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     86,  21,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,  16,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
    166,  26,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   8, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      7,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  14,   0,   0,   7, 
     50,   0,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  15,  50,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128, 191,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     56,   0,   0,  10,  50,  32, 
     16,   0,   6,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  63,   0,   0, 
      0,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 242,  32,  16,   0, 
      7,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   8,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     83,  84,  65,  84, 116,   0, 
      0,   0,  26,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     10,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};