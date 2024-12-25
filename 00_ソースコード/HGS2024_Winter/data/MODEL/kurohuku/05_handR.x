xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 186;
 2.10712;0.02921;-2.26333;,
 2.87300;-0.24429;-2.05490;,
 2.68689;-0.76948;-1.91595;,
 1.93194;-0.48812;-2.32621;,
 3.21278;-1.50281;-2.48953;,
 1.79350;-0.67256;-2.51049;,
 3.16158;-1.70180;-2.90941;,
 1.72415;-0.88462;-2.59605;,
 3.25703;-1.47099;-3.30455;,
 1.80035;-0.66763;-2.63669;,
 3.44307;-0.94601;-3.44350;,
 1.94659;-0.47759;-2.59580;,
 3.61086;-0.43401;-3.24486;,
 2.11396;0.03413;-2.38954;,
 3.66202;-0.23513;-2.82498;,
 2.18218;0.24526;-2.28393;,
 2.87300;-0.24429;-2.05490;,
 2.10712;0.02921;-2.26333;,
 4.21577;-0.68886;-2.40330;,
 4.02964;-1.21404;-2.26435;,
 3.86194;-1.72581;-2.46299;,
 3.81072;-1.92483;-2.88287;,
 3.90619;-1.69401;-3.27801;,
 4.09221;-1.16904;-3.41697;,
 4.26002;-0.65703;-3.21832;,
 4.31117;-0.45817;-2.79845;,
 4.21577;-0.68886;-2.40330;,
 6.51255;-1.35439;-1.42956;,
 6.52572;-2.13582;-1.39697;,
 6.48249;-2.68986;-1.60550;,
 6.73220;-2.98985;-2.04896;,
 7.12839;-2.86062;-2.46777;,
 7.43912;-2.37729;-2.61652;,
 7.48220;-1.82369;-2.40808;,
 7.23253;-1.52351;-1.96453;,
 6.51255;-1.35439;-1.42956;,
 6.78787;-1.72491;0.28383;,
 6.48600;-2.20147;0.27079;,
 6.43406;-2.76185;0.22414;,
 6.66258;-3.07709;0.17123;,
 7.03753;-2.96308;0.14304;,
 7.33949;-2.48609;0.15610;,
 7.39133;-1.92614;0.20272;,
 6.73332;-1.47991;0.64136;,
 6.78787;-1.72491;0.28383;,
 1.93194;-0.48812;-2.32621;,
 1.94510;-0.47866;-2.56821;,
 2.10712;0.02921;-2.26333;,
 1.79350;-0.67256;-2.51049;,
 1.72415;-0.88462;-2.59605;,
 1.80035;-0.66763;-2.63669;,
 1.94659;-0.47759;-2.59580;,
 2.11396;0.03413;-2.38954;,
 2.18218;0.24526;-2.28393;,
 6.78787;-1.72491;0.28383;,
 6.89191;-2.35881;0.59805;,
 6.48600;-2.20147;0.27079;,
 6.43406;-2.76185;0.22414;,
 6.66258;-3.07709;0.17123;,
 7.03753;-2.96308;0.14304;,
 7.33949;-2.48609;0.15610;,
 7.39133;-1.92614;0.20272;,
 6.73332;-1.47991;0.64136;,
 2.43620;1.57377;-0.43860;,
 1.73634;1.45993;-0.98738;,
 2.69277;1.36799;-1.62387;,
 2.93841;1.57264;-0.77256;,
 5.81690;1.24908;-2.18102;,
 3.54093;1.56478;-0.74761;,
 6.02676;1.20847;-0.95261;,
 4.01367;1.55323;-0.37328;,
 5.98819;0.99062;0.27467;,
 4.17600;1.54234;0.20745;,
 5.92445;1.17227;1.50678;,
 3.96600;1.53636;0.77276;,
 5.61328;1.17697;2.71418;,
 3.46379;1.53749;1.10672;,
 2.54605;1.31602;1.90328;,
 2.86126;1.54533;1.08177;,
 1.64566;1.42782;1.19252;,
 2.38853;1.55686;0.70744;,
 1.33684;1.44847;0.08790;,
 2.22619;1.56775;0.12671;,
 1.73634;1.45993;-0.98738;,
 2.43620;1.57377;-0.43860;,
 1.17536;1.12387;-1.42677;,
 2.49013;1.12087;-2.30109;,
 6.42227;0.99092;-2.13943;,
 6.59513;1.08777;-0.94855;,
 6.51721;0.90818;0.29538;,
 6.49136;1.05107;1.54623;,
 6.22032;0.91944;2.71528;,
 2.28816;1.04939;2.55362;,
 1.05055;1.07965;1.57361;,
 0.62551;1.10809;0.05324;,
 1.17536;1.12387;-1.42677;,
 0.81290;0.25231;-1.71858;,
 2.35848;0.24883;-2.74641;,
 6.86391;0.05247;-2.18539;,
 6.94125;0.12150;-0.98778;,
 6.93115;0.13381;0.30120;,
 6.83420;0.08360;1.58563;,
 6.65777;-0.02052;2.77013;,
 2.12108;0.16478;2.96064;,
 0.66616;0.20036;1.80857;,
 0.16649;0.23380;0.02126;,
 0.81290;0.25231;-1.71858;,
 0.67966;-0.72037;-1.82938;,
 2.30480;-0.72402;-2.91011;,
 7.26084;-0.84037;-2.21184;,
 7.32616;-0.77349;-0.98220;,
 7.35128;-0.74781;0.30569;,
 7.21935;-0.81132;1.58573;,
 7.05222;-0.91423;2.80320;,
 2.05517;-0.81240;3.09064;,
 4.45111;-0.86123;2.95282;,
 0.52538;-0.77499;1.87928;,
 0.00000;-0.73982;0.00000;,
 0.67966;-0.72037;-1.82938;,
 0.78873;-1.69898;-1.74833;,
 2.33432;-1.70244;-2.77615;,
 6.45393;-2.20333;-2.29497;,
 6.46914;-2.20849;-1.02588;,
 6.57330;-2.26696;0.24095;,
 6.36057;-2.25615;1.49544;,
 6.23634;-2.29884;2.75782;,
 4.50067;-0.87455;2.89479;,
 2.09691;-1.78650;2.93090;,
 0.64200;-1.75092;1.77883;,
 0.14233;-1.71748;-0.00848;,
 0.78873;-1.69898;-1.74833;,
 1.12941;-2.58771;-1.48334;,
 2.43378;-1.82267;-2.34692;,
 5.57385;-1.75690;-2.28966;,
 5.22287;-2.48774;-1.02388;,
 5.27473;-2.57908;0.17913;,
 5.11953;-2.53309;1.37582;,
 4.90403;-2.46900;2.66232;,
 4.51521;-0.89418;2.65273;,
 2.24223;-2.66215;2.49704;,
 1.00460;-2.63189;1.51703;,
 0.57955;-2.60346;-0.00334;,
 1.12941;-2.58771;-1.48334;,
 1.66836;-3.29957;-1.06037;,
 2.60448;-1.89287;-1.67590;,
 5.76762;-1.84970;-2.28560;,
 4.80549;-1.77875;-1.04310;,
 4.77313;-1.84456;0.17122;,
 4.70091;-1.82465;1.38543;,
 4.53721;-1.50748;2.67668;,
 4.51327;-0.96762;2.44579;,
 2.47685;-3.35368;1.83155;,
 1.57767;-3.33168;1.11953;,
 1.26887;-3.31102;0.01492;,
 1.66836;-3.29957;-1.06037;,
 4.63776;-1.49171;-0.37680;,
 5.13995;-1.49282;-0.71076;,
 5.74249;-1.50068;-0.68581;,
 6.21521;-1.51224;-0.31148;,
 6.37757;-1.52310;0.26925;,
 6.16753;-1.52911;0.83456;,
 5.66535;-1.52798;1.16852;,
 5.06280;-1.52014;1.14357;,
 4.59009;-1.50859;0.76924;,
 4.42774;-1.49773;0.18851;,
 4.63776;-1.49171;-0.37680;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 3.20461;1.59308;0.16781;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;,
 5.41305;-1.34413;0.23176;;
 
 155;
 4;3,2,1,0;,
 4;5,4,2,3;,
 4;7,6,4,5;,
 4;9,8,6,7;,
 4;11,10,8,9;,
 4;13,12,10,11;,
 4;15,14,12,13;,
 4;17,16,14,15;,
 4;2,19,18,1;,
 4;4,20,19,2;,
 4;6,21,20,4;,
 4;8,22,21,6;,
 4;10,23,22,8;,
 4;12,24,23,10;,
 4;14,25,24,12;,
 4;16,26,25,14;,
 4;19,28,27,18;,
 4;20,29,28,19;,
 4;21,30,29,20;,
 4;22,31,30,21;,
 4;23,32,31,22;,
 4;24,33,32,23;,
 4;25,34,33,24;,
 4;26,35,34,25;,
 4;28,37,36,27;,
 4;29,38,37,28;,
 4;30,39,38,29;,
 4;31,40,39,30;,
 4;32,41,40,31;,
 4;33,42,41,32;,
 4;34,43,42,33;,
 4;35,44,43,34;,
 3;47,46,45;,
 3;45,46,48;,
 3;48,46,49;,
 3;49,46,50;,
 3;50,46,51;,
 3;51,46,52;,
 3;52,46,53;,
 3;53,46,47;,
 3;56,55,54;,
 3;57,55,56;,
 3;58,55,57;,
 3;59,55,58;,
 3;60,55,59;,
 3;61,55,60;,
 3;62,55,61;,
 3;54,55,62;,
 4;66,65,64,63;,
 4;68,67,65,66;,
 4;70,69,67,68;,
 4;72,71,69,70;,
 4;74,73,71,72;,
 4;76,75,73,74;,
 4;78,77,75,76;,
 4;80,79,77,78;,
 4;82,81,79,80;,
 4;84,83,81,82;,
 4;65,86,85,64;,
 4;67,87,86,65;,
 4;69,88,87,67;,
 4;71,89,88,69;,
 4;73,90,89,71;,
 4;75,91,90,73;,
 4;77,92,91,75;,
 4;79,93,92,77;,
 4;81,94,93,79;,
 4;83,95,94,81;,
 4;86,97,96,85;,
 4;87,98,97,86;,
 4;88,99,98,87;,
 4;89,100,99,88;,
 4;90,101,100,89;,
 4;91,102,101,90;,
 4;92,103,102,91;,
 4;93,104,103,92;,
 4;94,105,104,93;,
 4;95,106,105,94;,
 4;97,108,107,96;,
 4;98,109,108,97;,
 4;99,110,109,98;,
 4;100,111,110,99;,
 4;101,112,111,100;,
 4;102,113,112,101;,
 3;115,103,114;,
 3;115,102,103;,
 3;115,113,102;,
 4;104,116,114,103;,
 4;105,117,116,104;,
 4;106,118,117,105;,
 4;108,120,119,107;,
 4;109,121,120,108;,
 4;110,122,121,109;,
 4;111,123,122,110;,
 4;112,124,123,111;,
 4;113,125,124,112;,
 4;115,126,125,113;,
 4;116,128,127,114;,
 4;117,129,128,116;,
 4;118,130,129,117;,
 4;120,132,131,119;,
 4;121,133,132,120;,
 4;122,134,133,121;,
 4;123,135,134,122;,
 4;124,136,135,123;,
 4;125,137,136,124;,
 4;126,138,137,125;,
 4;128,140,139,127;,
 4;129,141,140,128;,
 4;130,142,141,129;,
 4;132,144,143,131;,
 4;133,145,144,132;,
 4;134,146,145,133;,
 4;135,147,146,134;,
 4;136,148,147,135;,
 4;137,149,148,136;,
 4;138,150,149,137;,
 4;140,152,151,139;,
 4;141,153,152,140;,
 4;142,154,153,141;,
 4;144,156,155,143;,
 4;145,157,156,144;,
 4;146,158,157,145;,
 4;147,159,158,146;,
 4;148,160,159,147;,
 4;149,161,160,148;,
 3;162,150,151;,
 3;162,149,150;,
 3;162,161,149;,
 4;152,163,162,151;,
 4;153,164,163,152;,
 4;154,165,164,153;,
 3;63,166,66;,
 3;66,167,68;,
 3;68,168,70;,
 3;70,169,72;,
 3;72,170,74;,
 3;74,171,76;,
 3;76,172,78;,
 3;78,173,80;,
 3;80,174,82;,
 3;82,175,84;,
 3;156,176,155;,
 3;157,177,156;,
 3;158,178,157;,
 3;159,179,158;,
 3;160,180,159;,
 3;161,181,160;,
 3;162,182,161;,
 3;163,183,162;,
 3;164,184,163;,
 3;165,185,164;,
 4;115,114,127,126;,
 4;126,127,139,138;,
 4;138,139,151,150;;
 
 MeshMaterialList {
  1;
  155;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\kurohuku.jpg";
   }
  }
 }
 MeshNormals {
  189;
  -0.098434;0.380585;0.919492;,
  -0.413341;-0.266122;0.870821;,
  -0.369083;-0.628799;0.684390;,
  -0.304964;-0.608070;0.732972;,
  -0.457705;-0.115903;-0.881518;,
  -0.358093;0.303614;-0.882943;,
  -0.205262;0.597977;-0.774785;,
  -0.064817;0.729127;-0.681302;,
  0.117381;0.468885;0.875425;,
  -0.148861;-0.228962;0.961986;,
  -0.288274;-0.663058;0.690835;,
  -0.312147;-0.739683;0.596182;,
  -0.323770;-0.349907;-0.879055;,
  -0.160709;0.179312;-0.970577;,
  0.014472;0.627509;-0.778475;,
  0.125000;0.808623;-0.574894;,
  0.141865;0.609614;0.779901;,
  -0.129286;-0.107688;0.985743;,
  -0.321118;-0.644018;0.694352;,
  -0.329030;-0.942618;-0.056657;,
  -0.097898;-0.601193;-0.793084;,
  0.142607;0.008356;-0.989744;,
  0.320191;0.613070;-0.722235;,
  0.333092;0.942840;-0.010156;,
  -0.303412;0.188234;0.934082;,
  -0.357673;-0.035795;0.933161;,
  -0.616707;-0.634784;0.465534;,
  -0.327596;-0.943354;-0.052566;,
  0.331073;-0.829187;-0.450376;,
  0.230551;-0.022520;-0.972799;,
  0.551711;0.691440;-0.466396;,
  0.466395;0.884568;0.003790;,
  -0.896933;0.369762;0.242460;,
  -0.869404;0.186757;0.457448;,
  -0.839252;-0.271586;0.471059;,
  -0.807113;-0.588566;-0.046466;,
  0.562797;-0.704903;0.431707;,
  0.857452;-0.315726;0.406315;,
  0.863916;0.159663;0.477658;,
  0.741845;0.437691;0.508028;,
  -0.899304;0.437043;-0.015673;,
  -0.166071;-0.139553;0.976189;,
  -0.060969;0.996284;-0.060840;,
  -0.015387;0.993186;-0.115521;,
  0.048064;0.995809;-0.077803;,
  0.110733;0.993831;0.006127;,
  0.138741;0.990120;0.020346;,
  0.109647;0.993446;0.032298;,
  0.040208;0.993032;0.110773;,
  -0.026178;0.989377;0.142998;,
  -0.067049;0.994135;0.084849;,
  -0.079965;0.996733;0.011374;,
  -0.208666;0.960343;-0.184931;,
  -0.065909;0.902683;-0.425230;,
  0.122348;0.939634;-0.319561;,
  0.208556;0.977483;0.032126;,
  0.204008;0.978702;0.022890;,
  0.209291;0.977753;0.014049;,
  0.094227;0.929652;0.356186;,
  -0.102135;0.889824;0.444727;,
  -0.224502;0.954735;0.195140;,
  -0.285174;0.958473;0.002265;,
  -0.528288;0.737022;-0.421557;,
  -0.159325;0.597490;-0.785889;,
  0.154201;0.682182;-0.714738;,
  0.648291;0.761367;0.006330;,
  0.622104;0.782042;0.037387;,
  0.645638;0.760438;0.069906;,
  0.355646;0.652978;0.668682;,
  -0.224785;0.574237;0.787225;,
  -0.562384;0.724940;0.397726;,
  -0.689675;0.723895;-0.018023;,
  -0.741461;0.327843;-0.585453;,
  -0.217284;0.275336;-0.936471;,
  0.113378;0.204518;-0.972275;,
  0.915307;0.400866;-0.038968;,
  0.911975;0.407886;0.043942;,
  0.908422;0.398424;0.126604;,
  0.902628;0.387906;0.186525;,
  -0.224000;0.225296;0.948191;,
  -0.787915;0.311398;0.531246;,
  -0.946113;0.321982;-0.034617;,
  -0.783827;0.019169;-0.620683;,
  -0.226172;0.023247;-0.973810;,
  0.127785;0.023994;-0.991512;,
  0.997788;-0.050586;-0.043124;,
  0.998352;-0.040467;0.040684;,
  0.990897;-0.052762;0.123853;,
  0.989235;-0.064022;0.131589;,
  -0.273377;-0.122710;0.954048;,
  -0.832683;0.001871;0.553747;,
  -0.999059;0.013003;-0.041370;,
  -0.716060;-0.393259;-0.576719;,
  -0.262005;-0.353836;-0.897860;,
  0.119266;-0.077101;-0.989864;,
  0.705615;-0.706805;-0.050340;,
  0.600986;-0.799185;0.010939;,
  0.580825;-0.810784;0.072602;,
  0.565405;-0.822981;0.054945;,
  -0.180934;-0.546748;0.817514;,
  -0.795582;-0.307844;0.521805;,
  -0.953781;-0.297256;-0.044055;,
  -0.438538;-0.740000;-0.509984;,
  -0.029450;-0.788348;-0.614524;,
  -0.115277;-0.983964;-0.136112;,
  0.044269;-0.985799;-0.161988;,
  0.224629;-0.974405;-0.008744;,
  0.196009;-0.979671;0.042726;,
  0.170496;-0.984927;0.029166;,
  -0.045641;-0.740646;0.670343;,
  -0.680379;-0.587092;0.438644;,
  -0.814867;-0.578095;-0.042411;,
  0.390026;-0.887752;-0.244491;,
  0.150456;-0.931273;-0.331805;,
  -0.036080;-0.979460;-0.198383;,
  -0.400840;0.915438;-0.036061;,
  -0.842937;-0.536005;-0.046429;,
  -0.871976;-0.484576;-0.069590;,
  -0.961277;-0.234140;0.145342;,
  0.035992;-0.788888;0.613482;,
  -0.597554;-0.705643;0.380785;,
  -0.715192;-0.697781;-0.040027;,
  0.274121;-0.961436;0.022319;,
  0.110604;-0.991607;0.066952;,
  -0.040974;-0.984297;0.171698;,
  -0.276458;0.952685;0.126338;,
  -0.202732;0.979201;0.008041;,
  -0.281614;0.931445;-0.230442;,
  -0.350891;0.843758;-0.406138;,
  0.235596;-0.968716;-0.078001;,
  0.297142;-0.926384;-0.231344;,
  0.330429;-0.943831;-0.000253;,
  0.012453;0.999806;0.015242;,
  -0.013160;-0.999797;-0.015271;,
  0.083674;-0.195231;0.977181;,
  0.023923;-0.660308;0.750614;,
  -0.584733;-0.275307;0.763081;,
  -0.642083;0.006904;0.766604;,
  -0.705198;0.033522;-0.708218;,
  -0.394882;-0.618522;-0.679337;,
  0.124939;0.559601;0.819290;,
  0.228681;0.712798;0.663042;,
  -0.203907;0.965999;0.158958;,
  -0.958062;0.274480;0.082324;,
  -0.982567;0.183373;0.030595;,
  -0.995697;0.090142;-0.021487;,
  0.289989;-0.851121;0.437605;,
  0.945964;-0.323606;0.020758;,
  0.995244;-0.092152;0.031585;,
  -0.549208;0.835001;-0.033821;,
  -0.879553;0.474900;-0.029266;,
  -0.945035;0.324680;-0.038640;,
  -0.796595;0.544882;-0.261803;,
  -0.807973;0.515461;0.285446;,
  -0.742863;0.365869;0.560619;,
  -0.879585;0.474852;-0.029087;,
  -0.945067;0.324606;-0.038456;,
  -0.945057;0.324629;-0.038522;,
  -0.347365;-0.394585;0.850671;,
  0.640032;-0.259933;0.723045;,
  -0.983933;-0.176091;-0.029456;,
  0.915216;0.383843;-0.122657;,
  0.914522;0.392123;-0.099441;,
  0.038581;0.138308;0.989637;,
  0.996754;-0.062062;-0.051290;,
  0.040930;-0.314455;0.948389;,
  0.859712;-0.510557;-0.015068;,
  -0.238756;-0.610812;0.754920;,
  -0.084796;-0.880674;0.466071;,
  -0.120514;-0.985535;0.119150;,
  -0.140248;-0.959689;-0.243574;,
  -0.767433;-0.364617;0.527352;,
  -0.595602;0.720832;-0.354485;,
  -0.495867;0.864093;-0.086365;,
  -0.843566;-0.536250;-0.028851;,
  -0.687723;-0.676773;-0.262709;,
  -0.345377;0.918906;0.190595;,
  0.583073;-0.629759;0.513255;,
  0.552575;-0.656919;0.512951;,
  -0.931425;-0.177245;-0.317854;,
  -0.013165;-0.999906;0.003744;,
  -0.043016;-0.992160;-0.117335;,
  0.395877;-0.754660;-0.523230;,
  0.455998;-0.819958;-0.346027;,
  0.497505;-0.867427;0.007728;,
  -0.153188;-0.985063;0.078635;,
  -0.181567;-0.983132;-0.022026;,
  -0.144923;-0.982139;-0.119998;,
  0.434193;-0.722767;0.537666;;
  155;
  4;1,9,8,0;,
  4;2,10,9,1;,
  4;3,11,10,2;,
  4;4,12,139,138;,
  4;5,13,12,4;,
  4;6,14,13,5;,
  4;7,15,14,6;,
  4;0,8,141,140;,
  4;9,17,16,8;,
  4;10,18,17,9;,
  4;11,19,18,10;,
  4;12,20,19,139;,
  4;13,21,20,12;,
  4;14,22,21,13;,
  4;15,23,22,14;,
  4;8,16,23,141;,
  4;17,25,24,16;,
  4;18,26,25,17;,
  4;19,27,26,18;,
  4;20,28,27,19;,
  4;21,29,28,20;,
  4;22,30,29,21;,
  4;23,31,30,22;,
  4;16,142,31,23;,
  4;144,33,32,143;,
  4;145,34,33,144;,
  4;27,35,34,26;,
  4;28,36,146,27;,
  4;147,37,36,28;,
  4;148,38,37,147;,
  4;31,39,38,30;,
  4;142,32,149,149;,
  3;151,40,150;,
  3;150,40,152;,
  3;152,40,138;,
  3;154,40,153;,
  3;153,40,155;,
  3;155,40,156;,
  3;156,40,157;,
  3;157,40,151;,
  3;33,41,32;,
  3;34,41,33;,
  3;158,41,34;,
  3;36,41,146;,
  3;37,159,36;,
  3;38,159,37;,
  3;39,41,38;,
  3;32,160,160;,
  4;43,53,52,42;,
  4;44,54,53,43;,
  4;45,55,54,44;,
  4;46,56,55,45;,
  4;47,57,56,46;,
  4;48,58,57,47;,
  4;49,59,58,48;,
  4;50,60,59,49;,
  4;51,61,60,50;,
  4;42,52,61,51;,
  4;53,63,62,52;,
  4;54,64,63,53;,
  4;55,65,64,54;,
  4;56,66,65,55;,
  4;57,67,66,56;,
  4;58,68,67,57;,
  4;59,69,68,58;,
  4;60,70,69,59;,
  4;61,71,70,60;,
  4;52,62,71,61;,
  4;63,73,72,62;,
  4;64,74,73,63;,
  4;65,75,162,161;,
  4;66,76,75,65;,
  4;67,77,76,66;,
  4;68,78,77,67;,
  4;69,79,163,68;,
  4;70,80,79,69;,
  4;71,81,80,70;,
  4;62,72,81,71;,
  4;73,83,82,72;,
  4;74,84,83,73;,
  4;75,85,164,162;,
  4;76,86,85,75;,
  4;77,87,86,76;,
  4;78,88,87,77;,
  3;134,79,89;,
  3;134,163,79;,
  3;134,165,163;,
  4;80,90,89,79;,
  4;81,91,90,80;,
  4;72,82,91,81;,
  4;83,93,92,82;,
  4;84,94,93,83;,
  4;85,95,166,164;,
  4;86,96,95,85;,
  4;87,97,96,86;,
  4;88,98,97,87;,
  4;134,135,167,165;,
  4;90,100,99,89;,
  4;91,101,100,90;,
  4;82,92,101,91;,
  4;93,103,102,92;,
  4;169,104,168,168;,
  4;170,105,104,169;,
  4;96,106,105,95;,
  4;97,107,106,96;,
  4;98,108,107,97;,
  4;135,136,171,167;,
  4;100,110,109,99;,
  4;101,111,110,100;,
  4;92,102,111,101;,
  4;103,113,112,102;,
  4;104,114,113,103;,
  4;172,115,173,172;,
  4;116,116,174,174;,
  4;117,117,116,116;,
  4;171,118,117,117;,
  4;136,137,118,171;,
  4;110,120,119,109;,
  4;111,121,120,110;,
  4;102,175,121,111;,
  4;113,123,122,112;,
  4;114,124,123,113;,
  4;115,125,176,173;,
  4;126,126,125,115;,
  4;127,127,126,126;,
  4;128,128,127,127;,
  3;129,178,177;,
  3;179,118,179;,
  3;129,181,180;,
  4;183,130,129,182;,
  4;184,131,130,183;,
  4;112,122,131,184;,
  3;42,132,43;,
  3;43,132,44;,
  3;44,132,45;,
  3;45,132,46;,
  3;46,132,47;,
  3;47,132,48;,
  3;48,132,49;,
  3;49,132,50;,
  3;50,132,51;,
  3;51,132,42;,
  3;123,133,122;,
  3;124,133,123;,
  3;185,133,124;,
  3;186,133,185;,
  3;187,133,186;,
  3;181,133,187;,
  3;129,133,181;,
  3;130,133,129;,
  3;131,133,130;,
  3;122,133,131;,
  4;134,89,99,135;,
  4;135,99,109,188;,
  4;188,109,119,178;;
 }
 MeshTextureCoords {
  186;
  0.218041;0.125673;,
  0.218041;0.113180;,
  0.222195;0.113180;,
  0.222195;0.125673;,
  0.226349;0.113180;,
  0.226349;0.125673;,
  0.230503;0.113180;,
  0.230503;0.125673;,
  0.234657;0.113180;,
  0.234657;0.125673;,
  0.238811;0.113180;,
  0.238811;0.125673;,
  0.242964;0.113180;,
  0.242964;0.125673;,
  0.247118;0.113180;,
  0.247118;0.125673;,
  0.251272;0.113180;,
  0.251272;0.125673;,
  0.218041;0.100687;,
  0.222195;0.100687;,
  0.226349;0.100687;,
  0.230503;0.100687;,
  0.234657;0.100687;,
  0.238811;0.100687;,
  0.242964;0.100687;,
  0.247118;0.100687;,
  0.251272;0.100687;,
  0.218041;0.088194;,
  0.222195;0.088194;,
  0.226349;0.088194;,
  0.230503;0.088194;,
  0.234657;0.088194;,
  0.238811;0.088194;,
  0.242964;0.088194;,
  0.247118;0.088194;,
  0.251272;0.088194;,
  0.218041;0.075701;,
  0.222195;0.075701;,
  0.226349;0.075701;,
  0.230503;0.075701;,
  0.234657;0.075701;,
  0.238811;0.075701;,
  0.242964;0.075701;,
  0.247118;0.075701;,
  0.251272;0.075701;,
  0.234657;0.167211;,
  0.234657;0.147273;,
  0.249343;0.161128;,
  0.219971;0.161128;,
  0.213887;0.146442;,
  0.219971;0.131756;,
  0.234657;0.125673;,
  0.249343;0.131756;,
  0.255426;0.146442;,
  0.249343;0.040371;,
  0.234657;0.055888;,
  0.234657;0.034288;,
  0.219971;0.040371;,
  0.213887;0.055057;,
  0.219971;0.069743;,
  0.234657;0.075826;,
  0.249343;0.069743;,
  0.255426;0.055057;,
  0.162074;0.176871;,
  0.162074;0.163578;,
  0.175367;0.163578;,
  0.175367;0.176871;,
  0.188659;0.163578;,
  0.188659;0.176871;,
  0.201951;0.163578;,
  0.201951;0.176871;,
  0.215244;0.163578;,
  0.215244;0.176871;,
  0.228536;0.163578;,
  0.228536;0.176871;,
  0.241829;0.163578;,
  0.241829;0.176871;,
  0.255121;0.163578;,
  0.255121;0.176871;,
  0.268413;0.163578;,
  0.268413;0.176871;,
  0.281706;0.163578;,
  0.281706;0.176871;,
  0.294998;0.163578;,
  0.294998;0.176871;,
  0.162074;0.150286;,
  0.175367;0.150286;,
  0.188659;0.150286;,
  0.201951;0.150286;,
  0.215244;0.150286;,
  0.228536;0.150286;,
  0.241829;0.150286;,
  0.255121;0.150286;,
  0.268413;0.150286;,
  0.281706;0.150286;,
  0.294998;0.150286;,
  0.162074;0.136993;,
  0.175367;0.136993;,
  0.188659;0.136993;,
  0.201951;0.136993;,
  0.215244;0.136993;,
  0.228536;0.136993;,
  0.241829;0.136993;,
  0.255121;0.136993;,
  0.268413;0.136993;,
  0.281706;0.136993;,
  0.294998;0.136993;,
  0.162074;0.123701;,
  0.175367;0.123701;,
  0.188659;0.123701;,
  0.201951;0.123701;,
  0.215244;0.123701;,
  0.228536;0.123701;,
  0.241829;0.123701;,
  0.255121;0.123701;,
  0.248748;0.123701;,
  0.268413;0.123701;,
  0.281706;0.123701;,
  0.294998;0.123701;,
  0.162074;0.110409;,
  0.175367;0.110409;,
  0.188659;0.110409;,
  0.201951;0.110409;,
  0.215244;0.110409;,
  0.228536;0.110409;,
  0.241829;0.110409;,
  0.249057;0.110409;,
  0.255121;0.110409;,
  0.268413;0.110409;,
  0.281706;0.110409;,
  0.294998;0.110409;,
  0.162074;0.097116;,
  0.175367;0.097116;,
  0.188659;0.097116;,
  0.201951;0.097116;,
  0.215244;0.097116;,
  0.228536;0.097116;,
  0.241829;0.097116;,
  0.247838;0.097116;,
  0.255121;0.097116;,
  0.268413;0.097116;,
  0.281706;0.097116;,
  0.294998;0.097116;,
  0.162074;0.083824;,
  0.175367;0.083824;,
  0.188659;0.083824;,
  0.201951;0.083824;,
  0.215244;0.083824;,
  0.228536;0.083824;,
  0.241829;0.083824;,
  0.246256;0.083824;,
  0.255121;0.083824;,
  0.268413;0.083824;,
  0.281706;0.083824;,
  0.294998;0.083824;,
  0.162074;0.070532;,
  0.175367;0.070532;,
  0.188659;0.070532;,
  0.201951;0.070532;,
  0.215244;0.070532;,
  0.228536;0.070532;,
  0.241829;0.070532;,
  0.255121;0.070532;,
  0.268413;0.070532;,
  0.281706;0.070532;,
  0.294998;0.070532;,
  0.168721;0.190163;,
  0.182013;0.190163;,
  0.195305;0.190163;,
  0.208598;0.190163;,
  0.221890;0.190163;,
  0.235182;0.190163;,
  0.248475;0.190163;,
  0.261767;0.190163;,
  0.275059;0.190163;,
  0.288352;0.190163;,
  0.168721;0.057239;,
  0.182013;0.057239;,
  0.195305;0.057239;,
  0.208598;0.057239;,
  0.221890;0.057239;,
  0.235182;0.057239;,
  0.248475;0.057239;,
  0.261767;0.057239;,
  0.275059;0.057239;,
  0.288352;0.057239;;
 }
}
