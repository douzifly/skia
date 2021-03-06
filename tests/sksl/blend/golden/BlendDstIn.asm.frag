OpCapability Shader
%1 = OpExtInstImport "GLSL.std.450"
OpMemoryModel Logical GLSL450
OpEntryPoint Fragment %main "main" %sk_FragColor %sk_Clockwise %src %dst
OpExecutionMode %main OriginUpperLeft
OpName %sk_FragColor "sk_FragColor"
OpName %sk_Clockwise "sk_Clockwise"
OpName %src "src"
OpName %dst "dst"
OpName %main "main"
OpName %_0_blend_dst_in "_0_blend_dst_in"
OpName %_1_0_blend_src_in "_1_0_blend_src_in"
OpDecorate %sk_FragColor RelaxedPrecision
OpDecorate %sk_FragColor Location 0
OpDecorate %sk_FragColor Index 0
OpDecorate %sk_Clockwise RelaxedPrecision
OpDecorate %sk_Clockwise BuiltIn FrontFacing
OpDecorate %src RelaxedPrecision
OpDecorate %dst RelaxedPrecision
OpDecorate %19 RelaxedPrecision
OpDecorate %20 RelaxedPrecision
OpDecorate %23 RelaxedPrecision
OpDecorate %24 RelaxedPrecision
%float = OpTypeFloat 32
%v4float = OpTypeVector %float 4
%_ptr_Output_v4float = OpTypePointer Output %v4float
%sk_FragColor = OpVariable %_ptr_Output_v4float Output
%bool = OpTypeBool
%_ptr_Input_bool = OpTypePointer Input %bool
%sk_Clockwise = OpVariable %_ptr_Input_bool Input
%_ptr_Input_v4float = OpTypePointer Input %v4float
%src = OpVariable %_ptr_Input_v4float Input
%dst = OpVariable %_ptr_Input_v4float Input
%void = OpTypeVoid
%14 = OpTypeFunction %void
%_ptr_Function_v4float = OpTypePointer Function %v4float
%main = OpFunction %void None %14
%15 = OpLabel
%_0_blend_dst_in = OpVariable %_ptr_Function_v4float Function
%_1_0_blend_src_in = OpVariable %_ptr_Function_v4float Function
%19 = OpLoad %v4float %dst
%20 = OpLoad %v4float %src
%21 = OpCompositeExtract %float %20 3
%22 = OpVectorTimesScalar %v4float %19 %21
OpStore %_1_0_blend_src_in %22
%23 = OpLoad %v4float %_1_0_blend_src_in
OpStore %_0_blend_dst_in %23
%24 = OpLoad %v4float %_0_blend_dst_in
OpStore %sk_FragColor %24
OpReturn
OpFunctionEnd
