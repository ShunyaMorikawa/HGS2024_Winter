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
 248;
 -1.14825;140.23201;-0.46202;,
 14.78835;139.65060;-16.39862;,
 -1.14825;139.65060;-22.99997;,
 -1.14825;140.23201;-0.46202;,
 21.38970;139.65060;-0.46202;,
 -1.14825;140.23201;-0.46202;,
 14.78835;139.65060;15.47488;,
 -1.14825;140.23201;-0.46202;,
 -1.14825;139.65060;22.07593;,
 -1.14825;140.23201;-0.46202;,
 -17.08500;139.65060;15.47488;,
 -1.14825;140.23201;-0.46202;,
 -23.68635;139.65060;-0.46202;,
 -1.14825;140.23201;-0.46202;,
 -17.08500;139.65060;-16.39862;,
 -1.14825;140.23201;-0.46202;,
 -1.14825;139.65060;-22.99997;,
 28.29900;125.26005;-29.90912;,
 -1.14825;125.26005;-42.10667;,
 40.49655;125.26005;-0.46202;,
 28.29900;125.26005;28.98523;,
 -1.14825;125.26005;41.18278;,
 -30.59580;125.26005;28.98523;,
 -42.79335;125.26005;-0.46202;,
 -30.59580;125.26005;-29.90912;,
 -1.14825;125.26005;-42.10667;,
 33.27870;103.72410;-38.05532;,
 -1.14825;103.72410;-56.77442;,
 53.26305;103.72410;-1.10927;,
 37.32630;103.72410;46.33108;,
 -1.14825;103.72410;56.28192;,
 -39.62310;103.72410;46.33108;,
 -55.55985;103.72410;-1.10927;,
 -39.62310;103.72410;-41.65232;,
 -1.14825;103.72410;-56.77442;,
 57.74610;78.32011;-1.10927;,
 35.36835;78.32011;-43.32123;,
 40.49655;78.32011;44.06848;,
 -1.14825;78.32011;57.58182;,
 -42.79335;78.32011;44.68438;,
 -60.04290;78.32011;-1.10927;,
 -38.19270;78.32011;-47.00657;,
 -1.14825;78.32011;-57.29012;,
 -1.14825;78.32011;-57.29012;,
 47.97795;24.51765;-52.39037;,
 -1.14825;24.51765;-67.64192;,
 68.32605;24.51765;-0.75197;,
 47.97795;24.51765;50.88627;,
 -1.14825;24.51765;66.79572;,
 -50.27460;24.51765;50.88627;,
 -70.62285;24.51765;-0.75197;,
 -50.27460;24.51765;-52.39037;,
 -1.14825;24.51765;-67.64192;,
 36.45120;0.69930;-40.27442;,
 -1.14825;0.69930;-56.64512;,
 52.02555;0.69930;-0.75197;,
 36.45120;0.69930;38.77018;,
 -1.14825;0.69930;55.14088;,
 -38.74800;0.69930;38.77018;,
 -54.32235;0.69930;-0.75197;,
 -38.74800;0.69930;-40.27442;,
 -1.14825;0.69930;-56.64512;,
 19.20045;-0.44370;-22.14137;,
 -1.14825;-0.44370;-31.00112;,
 27.62925;-0.44370;-0.75197;,
 19.20045;-0.44370;20.63728;,
 -1.14825;-0.44370;29.49703;,
 -21.49710;-0.44370;20.63728;,
 -29.92575;-0.44370;-0.75197;,
 -21.49710;-0.44370;-22.14137;,
 -1.14825;-0.44370;-31.00112;,
 -1.14825;-0.12149;-0.75197;,
 -1.14825;-0.12149;-0.75197;,
 -1.14825;-0.12149;-0.75197;,
 -1.14825;-0.12149;-0.75197;,
 -1.14825;-0.12149;-0.75197;,
 -1.14825;-0.12149;-0.75197;,
 -1.14825;-0.12149;-0.75197;,
 -1.14825;-0.12149;-0.75197;,
 68.13960;24.27300;0.73528;,
 70.69755;30.44865;0.73528;,
 49.48425;30.44865;-50.47833;,
 47.67555;24.27300;-48.66946;,
 76.87320;33.00660;0.73528;,
 53.85120;33.00660;-54.84482;,
 83.04885;30.44865;0.73528;,
 58.21800;30.44865;-59.21192;,
 85.60680;24.27300;0.73528;,
 60.02670;24.27300;-61.02048;,
 83.04885;18.09735;0.73528;,
 58.21800;18.09735;-59.21192;,
 76.87320;15.53955;0.73528;,
 53.85120;15.53955;-54.84482;,
 70.69755;18.09735;0.73528;,
 49.48425;18.09735;-50.47833;,
 68.13960;24.27300;0.73528;,
 47.67555;24.27300;-48.66946;,
 -1.72920;51.20670;-80.92667;,
 -1.72920;45.03106;-78.36872;,
 -1.72920;53.76450;-80.90192;,
 -1.72920;51.20670;-87.07743;,
 -1.72920;45.03106;-89.63552;,
 -1.72920;38.85540;-87.07743;,
 -1.72920;36.29745;-80.90192;,
 -1.72920;38.85540;-80.92667;,
 -1.72920;45.03106;-78.36872;,
 -52.94280;30.44865;-50.47833;,
 -51.13395;24.27300;-48.66946;,
 -57.30960;33.00660;-54.84482;,
 -61.67640;30.44865;-59.21192;,
 -63.48525;24.27300;-61.02048;,
 -61.67640;18.09735;-59.21192;,
 -57.30960;15.53955;-54.84482;,
 -52.94280;18.09735;-50.47833;,
 -51.13395;24.27300;-48.66946;,
 -74.15610;30.44865;0.73528;,
 -71.59830;24.27300;0.73528;,
 -80.33190;33.00660;0.73528;,
 -86.50740;30.44865;0.73528;,
 -89.06535;24.27300;0.73528;,
 -86.50740;18.09735;0.73528;,
 -80.33190;15.53955;0.73528;,
 -74.15610;18.09735;0.73528;,
 -71.59830;24.27300;0.73528;,
 -52.94280;30.44865;51.94888;,
 -51.13395;24.27300;50.14017;,
 -57.30960;33.00660;56.31552;,
 -61.67640;30.44865;60.68247;,
 -63.48525;24.27300;62.49118;,
 -61.67640;18.09735;60.68247;,
 -57.30960;15.53955;56.31552;,
 -52.94280;18.09735;51.94888;,
 -51.13395;24.27300;50.14017;,
 -1.72920;53.00896;83.05903;,
 -1.72920;46.83331;80.50108;,
 -1.72920;55.56690;84.02563;,
 -1.72920;53.00896;90.20127;,
 -1.72920;46.83331;92.75922;,
 -1.72920;40.65765;90.20127;,
 -1.72920;38.09970;84.02563;,
 -1.72920;40.65765;83.05903;,
 -1.72920;46.83331;80.50108;,
 49.48425;30.44865;51.94888;,
 47.67555;24.27300;50.14017;,
 53.85120;33.00660;56.31552;,
 58.21800;30.44865;60.68233;,
 60.02670;24.27300;62.49118;,
 58.21800;18.09735;60.68233;,
 53.85120;15.53955;56.31552;,
 49.48425;18.09735;51.94888;,
 47.67555;24.27300;50.14017;,
 70.69755;30.44865;0.73528;,
 68.13960;24.27300;0.73528;,
 76.87320;33.00660;0.73528;,
 83.04885;30.44865;0.73528;,
 85.60680;24.27300;0.73528;,
 83.04885;18.09735;0.73528;,
 76.87320;15.53955;0.73528;,
 70.69755;18.09735;0.73528;,
 68.13960;24.27300;0.73528;,
 -1.05900;162.29894;-0.81062;,
 21.25365;156.73501;-23.12372;,
 -1.05900;156.73501;-32.36597;,
 -1.05900;162.29894;-0.81062;,
 30.49605;156.73501;-0.81062;,
 -1.05900;162.29894;-0.81062;,
 21.25365;156.73501;21.50218;,
 -1.05900;162.29894;-0.81062;,
 -1.05915;156.73501;30.74443;,
 -1.05900;162.29894;-0.81062;,
 -23.37225;156.73501;21.50218;,
 -1.05900;162.29894;-0.81062;,
 -32.61465;156.73501;-0.81062;,
 -1.05900;162.29894;-0.81062;,
 -23.37225;156.73501;-23.12372;,
 -1.05900;162.29894;-0.81062;,
 -1.05900;156.73501;-32.36597;,
 40.87545;140.71394;-42.74522;,
 -1.05900;140.71394;-60.11522;,
 58.24515;140.71394;-0.81062;,
 40.87545;140.71394;41.12368;,
 -1.05915;140.71394;58.49368;,
 -42.99375;140.71394;41.12368;,
 -60.36405;140.71394;-0.81062;,
 -42.99375;140.71394;-42.74522;,
 -1.05900;140.71394;-60.11522;,
 55.43940;116.16811;-57.30902;,
 -1.05900;116.16811;-77.72252;,
 78.84150;116.16811;-0.81062;,
 55.43940;116.16811;55.68748;,
 -1.05915;116.16811;79.08987;,
 -57.55800;116.16811;55.68748;,
 -80.96010;116.16811;-0.81062;,
 -57.55800;116.16811;-57.30902;,
 -1.05900;116.16811;-77.72252;,
 63.18840;86.05875;-65.05832;,
 -1.05900;86.05875;-86.04588;,
 89.80050;86.05875;-0.81062;,
 63.18840;86.05875;63.43678;,
 -1.05915;86.05875;90.04903;,
 -65.30700;86.05875;63.43678;,
 -91.91910;86.05875;-0.81062;,
 -65.30700;86.05875;-65.05832;,
 -1.05900;86.05875;-86.04588;,
 63.18840;54.01680;-65.05832;,
 -1.05900;54.01680;-86.34543;,
 89.80050;54.01680;-0.81062;,
 63.18840;54.01680;63.43678;,
 -1.05915;54.01680;90.04903;,
 -65.30700;54.01680;63.43678;,
 -91.91910;54.01680;-0.81062;,
 -65.30700;54.01680;-65.05832;,
 -1.05900;54.01680;-86.34543;,
 55.43940;23.90701;-57.30902;,
 -1.05900;41.04270;-80.71142;,
 78.84150;23.90701;-0.81062;,
 55.43940;23.90701;55.68748;,
 -1.05915;41.04270;79.08987;,
 -57.55800;23.90701;55.68748;,
 -80.96010;23.90701;-0.81062;,
 -57.55800;23.90701;-57.30902;,
 -1.05900;41.04270;-80.71142;,
 40.87545;38.75325;-42.74522;,
 -1.05900;38.75325;-60.11522;,
 58.24515;21.61771;-0.81062;,
 40.87545;38.75325;41.12368;,
 -1.05915;38.75325;58.49368;,
 -42.99375;21.61771;41.12368;,
 -60.36405;21.61771;-0.81062;,
 -42.99375;21.61771;-42.74522;,
 -1.05900;38.75325;-60.11522;,
 21.25380;39.83566;-23.12372;,
 -1.05900;39.83566;-32.36612;,
 30.49605;39.83566;-0.81062;,
 21.25380;39.83566;21.50218;,
 -1.05915;39.83566;30.74458;,
 -23.37225;39.83566;21.50218;,
 -32.61465;39.83566;-0.81062;,
 -23.37225;39.83566;-23.12372;,
 -1.05900;39.83566;-32.36612;,
 -1.05900;38.74800;-0.81062;,
 -1.05900;38.74800;-0.81062;,
 -1.05900;38.74800;-0.81062;,
 -1.05900;38.74800;-0.81062;,
 -1.05900;38.74800;-0.81062;,
 -1.05900;38.74800;-0.81062;,
 -1.05900;38.74800;-0.81062;,
 -1.05900;38.74800;-0.81062;;
 
 199;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;26,28,35,36;,
 4;28,29,37,35;,
 4;29,30,38,37;,
 4;30,31,39,38;,
 4;31,32,40,39;,
 4;32,33,41,40;,
 4;33,34,42,41;,
 4;43,36,44,45;,
 4;36,35,46,44;,
 4;35,37,47,46;,
 4;37,38,48,47;,
 4;38,39,49,48;,
 4;39,40,50,49;,
 4;40,41,51,50;,
 4;41,42,52,51;,
 4;45,44,53,54;,
 4;44,46,55,53;,
 4;46,47,56,55;,
 4;47,48,57,56;,
 4;48,49,58,57;,
 4;49,50,59,58;,
 4;50,51,60,59;,
 4;51,52,61,60;,
 4;54,53,62,63;,
 4;53,55,64,62;,
 4;55,56,65,64;,
 4;56,57,66,65;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;60,61,70,69;,
 3;63,62,71;,
 3;62,64,72;,
 3;64,65,73;,
 3;65,66,74;,
 3;66,67,75;,
 3;67,68,76;,
 3;68,69,77;,
 3;69,70,78;,
 4;79,80,81,82;,
 4;80,83,84,81;,
 4;83,85,86,84;,
 4;85,87,88,86;,
 4;87,89,90,88;,
 4;89,91,92,90;,
 4;91,93,94,92;,
 4;93,95,96,94;,
 4;82,81,97,98;,
 4;81,84,99,97;,
 4;84,86,100,99;,
 4;86,88,101,100;,
 4;88,90,102,101;,
 4;90,92,103,102;,
 4;92,94,104,103;,
 4;94,96,105,104;,
 4;98,97,106,107;,
 4;97,99,108,106;,
 4;99,100,109,108;,
 4;100,101,110,109;,
 4;101,102,111,110;,
 4;102,103,112,111;,
 4;103,104,113,112;,
 4;104,105,114,113;,
 4;107,106,115,116;,
 4;106,108,117,115;,
 4;108,109,118,117;,
 4;109,110,119,118;,
 4;110,111,120,119;,
 4;111,112,121,120;,
 4;112,113,122,121;,
 4;113,114,123,122;,
 4;116,115,124,125;,
 4;115,117,126,124;,
 4;117,118,127,126;,
 4;118,119,128,127;,
 4;119,120,129,128;,
 4;120,121,130,129;,
 4;121,122,131,130;,
 4;122,123,132,131;,
 4;125,124,133,134;,
 4;124,126,135,133;,
 4;126,127,136,135;,
 4;127,128,137,136;,
 4;128,129,138,137;,
 4;129,130,139,138;,
 4;130,131,140,139;,
 4;131,132,141,140;,
 4;134,133,142,143;,
 4;133,135,144,142;,
 4;135,136,145,144;,
 4;136,137,146,145;,
 4;137,138,147,146;,
 4;138,139,148,147;,
 4;139,140,149,148;,
 4;140,141,150,149;,
 4;143,142,151,152;,
 4;142,144,153,151;,
 4;144,145,154,153;,
 4;145,146,155,154;,
 4;146,147,156,155;,
 4;147,148,157,156;,
 4;148,149,158,157;,
 4;149,150,159,158;,
 3;160,161,162;,
 3;163,164,161;,
 3;165,166,164;,
 3;167,168,166;,
 3;169,170,168;,
 3;171,172,170;,
 3;173,174,172;,
 3;175,176,174;,
 4;162,161,177,178;,
 4;161,164,179,177;,
 4;164,166,180,179;,
 4;166,168,181,180;,
 4;168,170,182,181;,
 4;170,172,183,182;,
 4;172,174,184,183;,
 4;174,176,185,184;,
 4;178,177,186,187;,
 4;177,179,188,186;,
 4;179,180,189,188;,
 4;180,181,190,189;,
 4;181,182,191,190;,
 4;182,183,192,191;,
 4;183,184,193,192;,
 4;184,185,194,193;,
 4;187,186,195,196;,
 4;186,188,197,195;,
 4;188,189,198,197;,
 4;189,190,199,198;,
 4;190,191,200,199;,
 4;191,192,201,200;,
 4;192,193,202,201;,
 4;193,194,203,202;,
 4;196,195,204,205;,
 4;195,197,206,204;,
 4;197,198,207,206;,
 4;198,199,208,207;,
 4;199,200,209,208;,
 4;200,201,210,209;,
 4;201,202,211,210;,
 4;202,203,212,211;,
 4;205,204,213,214;,
 4;204,206,215,213;,
 4;206,207,216,215;,
 4;207,208,217,216;,
 4;208,209,218,217;,
 4;209,210,219,218;,
 4;210,211,220,219;,
 4;211,212,221,220;,
 4;214,213,222,223;,
 4;213,215,224,222;,
 4;215,216,225,224;,
 4;216,217,226,225;,
 4;217,218,227,226;,
 4;218,219,228,227;,
 4;219,220,229,228;,
 4;220,221,230,229;,
 4;223,222,231,232;,
 4;222,224,233,231;,
 4;224,225,234,233;,
 4;225,226,235,234;,
 4;226,227,236,235;,
 4;227,228,237,236;,
 4;228,229,238,237;,
 4;229,230,239,238;,
 3;232,231,240;,
 3;231,233,241;,
 3;233,234,242;,
 3;234,235,243;,
 3;235,236,244;,
 3;236,237,245;,
 3;237,238,246;,
 3;238,239,247;;
 
 MeshMaterialList {
  6;
  199;
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  1,
  5,
  5,
  1,
  1,
  5,
  5,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  5,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  5,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  5,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  5,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  5,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  5,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  5,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  5,
  5,
  3,
  3,
  3,
  3,
  3,
  3,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  5,
  5,
  1,
  1,
  1,
  1,
  1,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.279200;0.279200;0.279200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.552000;0.150400;0.417600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.674510;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  211;
  0.000000;1.000000;-0.000000;,
  0.000001;0.945769;-0.324841;,
  0.229698;0.945768;-0.229698;,
  0.324840;0.945769;-0.000001;,
  0.229697;0.945768;0.229699;,
  0.000001;0.945768;0.324843;,
  -0.229696;0.945769;0.229698;,
  -0.324838;0.945769;-0.000001;,
  -0.229696;0.945769;-0.229698;,
  0.017995;0.680564;-0.732467;,
  0.539105;0.648228;-0.537743;,
  0.746408;0.665069;-0.023616;,
  0.497851;0.710698;0.497045;,
  0.000001;0.723507;0.690317;,
  -0.497849;0.710699;0.497045;,
  -0.735343;0.677669;-0.005905;,
  -0.515474;0.687599;-0.511365;,
  -0.089592;0.397769;-0.913101;,
  0.725858;0.366255;-0.582226;,
  0.940180;0.335315;-0.060206;,
  0.648393;0.359905;0.670861;,
  0.001780;0.344107;0.938929;,
  -0.646446;0.363964;0.670550;,
  -0.940986;0.337636;-0.023400;,
  -0.650398;0.343859;-0.677306;,
  -0.095077;0.163510;-0.981950;,
  0.739027;0.209433;-0.640294;,
  0.980899;0.188118;-0.049476;,
  0.679206;0.130245;0.722299;,
  0.003287;0.086732;0.996226;,
  -0.677318;0.132389;0.723680;,
  -0.985841;0.165542;-0.026692;,
  -0.659781;0.158541;-0.734543;,
  0.011934;-0.155114;-0.987824;,
  0.671798;-0.167161;-0.721627;,
  0.980763;-0.194641;-0.014769;,
  0.677545;-0.196194;0.708830;,
  0.001696;-0.175960;0.984396;,
  -0.676361;-0.198494;0.709320;,
  -0.979775;-0.199839;-0.010280;,
  -0.664886;-0.181790;-0.724485;,
  0.000000;-0.858203;-0.513311;,
  0.338417;-0.873388;-0.350238;,
  0.476138;-0.879371;0.000000;,
  0.338449;-0.874494;0.347437;,
  0.000000;-0.861593;0.507600;,
  -0.338450;-0.874493;0.347438;,
  -0.476139;-0.879370;0.000001;,
  -0.338416;-0.873388;-0.350239;,
  0.000000;-0.999856;-0.016942;,
  0.012592;-0.999849;-0.011980;,
  0.017807;-0.999841;0.000000;,
  0.012592;-0.999849;0.011980;,
  0.000000;-0.999856;0.016942;,
  -0.012592;-0.999849;0.011980;,
  -0.017807;-0.999841;0.000000;,
  -0.012592;-0.999849;-0.011980;,
  -0.000000;-1.000000;-0.000000;,
  -1.000000;-0.000000;-0.000000;,
  -0.698872;0.715246;0.000000;,
  -0.000000;1.000000;0.000001;,
  0.698873;0.715246;0.000000;,
  1.000000;-0.000000;-0.000001;,
  0.698865;-0.715254;0.000000;,
  -0.000000;-1.000000;0.000001;,
  -0.698864;-0.715254;0.000000;,
  -0.756837;0.003135;0.653596;,
  -0.514772;0.593129;0.619037;,
  0.155957;0.983692;-0.089597;,
  0.591856;0.683877;-0.426637;,
  0.722394;-0.000810;-0.691481;,
  0.416612;-0.729114;-0.542979;,
  -0.036036;-0.984916;-0.169241;,
  -0.640297;-0.583042;0.500081;,
  -0.000001;0.006946;0.999976;,
  -0.000001;0.447436;0.894316;,
  -0.000000;0.506088;0.862482;,
  0.495742;0.661342;-0.562909;,
  0.000000;-0.001668;-0.999999;,
  0.000000;-0.674740;-0.738055;,
  0.000000;-0.884215;-0.467081;,
  -0.576310;-0.454227;0.679371;,
  0.756836;0.003134;0.653597;,
  0.514771;0.593130;0.619038;,
  0.334172;0.769009;0.544935;,
  -0.591855;0.683879;-0.426636;,
  -0.722394;-0.000810;-0.691482;,
  -0.416611;-0.729115;-0.542979;,
  0.036035;-0.984916;-0.169242;,
  0.640297;-0.583042;0.500082;,
  1.000000;-0.000000;-0.000000;,
  0.698872;0.715247;0.000000;,
  -0.000001;1.000000;0.000000;,
  -0.698871;0.715248;-0.000000;,
  -1.000000;-0.000000;-0.000001;,
  -0.698863;-0.715255;-0.000000;,
  -0.000001;-1.000000;0.000000;,
  0.698864;-0.715255;0.000000;,
  0.759921;0.003576;-0.650006;,
  0.489786;0.633108;-0.599403;,
  -0.092143;0.983193;-0.157612;,
  -0.603459;0.679246;0.417686;,
  -0.729952;-0.001317;0.683498;,
  -0.416831;-0.729044;0.542906;,
  0.196667;-0.980455;-0.005583;,
  0.643265;-0.610771;-0.461702;,
  0.234782;0.145503;-0.961096;,
  -0.000001;0.519738;-0.854326;,
  -0.000000;0.636539;-0.771245;,
  -0.521268;0.655128;0.546888;,
  -0.195959;-0.137717;0.970894;,
  0.000001;-0.674539;0.738239;,
  0.000002;-0.882740;0.469863;,
  0.593047;-0.516244;-0.617889;,
  -0.759921;0.003577;-0.650005;,
  -0.489787;0.633107;-0.599403;,
  -0.054604;0.953461;-0.296532;,
  0.603460;0.679245;0.417686;,
  0.729953;-0.001318;0.683497;,
  0.416832;-0.729044;0.542906;,
  -0.040402;-0.984591;0.170141;,
  -0.643267;-0.610770;-0.461701;,
  0.000001;1.000000;0.000001;,
  0.000001;0.940247;-0.340493;,
  0.240765;0.940247;-0.240764;,
  0.340493;0.940247;0.000001;,
  0.240765;0.940247;0.240766;,
  0.000001;0.940247;0.340494;,
  -0.240763;0.940247;0.240766;,
  -0.340491;0.940248;0.000001;,
  -0.240763;0.940247;-0.240766;,
  0.000001;0.752329;-0.658787;,
  0.453108;0.761819;-0.462952;,
  0.640966;0.767570;0.000001;,
  0.453231;0.767569;0.453231;,
  0.000001;0.767569;0.640966;,
  -0.453230;0.767569;0.453233;,
  -0.640964;0.767571;0.000001;,
  -0.453106;0.761819;-0.462954;,
  0.000001;0.458063;-0.888919;,
  0.601289;0.486540;-0.633822;,
  0.865029;0.501722;0.000001;,
  0.611668;0.501723;0.611667;,
  0.000001;0.501724;0.865028;,
  -0.611667;0.501723;0.611668;,
  -0.865029;0.501722;0.000001;,
  -0.601287;0.486541;-0.633823;,
  0.000001;0.151525;-0.988453;,
  0.671953;0.167265;-0.721458;,
  0.984675;0.174398;0.000001;,
  0.696271;0.174400;0.696270;,
  0.000001;0.174401;0.984675;,
  -0.696270;0.174400;0.696270;,
  -0.984675;0.174398;0.000001;,
  -0.671952;0.167265;-0.721459;,
  0.000001;-0.181236;-0.983440;,
  0.668188;-0.183383;-0.721038;,
  0.984676;-0.174396;0.000001;,
  0.687073;-0.218151;0.693066;,
  0.000001;-0.257840;0.966188;,
  -0.687073;-0.218151;0.693067;,
  -0.984676;-0.174396;0.000001;,
  -0.668187;-0.183383;-0.721039;,
  0.090371;-0.624788;-0.775547;,
  0.633423;-0.361073;-0.684398;,
  0.939694;-0.342016;0.000001;,
  0.634019;-0.425533;0.645710;,
  0.087911;-0.700452;0.708265;,
  -0.509112;-0.706182;0.492049;,
  -0.939694;-0.342016;0.000001;,
  -0.633422;-0.361073;-0.684399;,
  0.073608;-0.993158;0.090657;,
  -0.265370;-0.962070;0.063242;,
  -0.384550;-0.923104;-0.000000;,
  -0.265370;-0.962070;-0.063242;,
  0.073608;-0.993158;-0.090657;,
  0.258389;-0.964035;-0.062216;,
  0.228732;-0.973489;-0.000000;,
  0.258389;-0.964036;0.062215;,
  0.076994;-0.994710;0.068003;,
  -0.102528;-0.994710;-0.006358;,
  -0.205990;-0.978554;-0.000000;,
  -0.102528;-0.994710;0.006358;,
  0.076994;-0.994710;-0.068003;,
  0.210047;-0.969977;-0.122577;,
  0.266017;-0.963968;-0.000000;,
  0.210047;-0.969977;0.122577;,
  0.000000;-1.000000;0.000000;,
  -0.232463;0.492224;0.838855;,
  -0.000000;0.962434;-0.271516;,
  -0.561664;-0.555458;0.613188;,
  -0.495742;0.661344;-0.562907;,
  -0.403238;0.892675;-0.201324;,
  0.561664;-0.555454;0.613192;,
  0.576309;-0.454228;0.679371;,
  0.000000;0.965647;0.259857;,
  0.564900;-0.666743;-0.486150;,
  0.521269;0.655128;0.546887;,
  0.451453;0.861642;0.231869;,
  0.514584;0.352469;0.781645;,
  -0.564900;-0.666746;-0.486146;,
  -0.593048;-0.516243;-0.617890;,
  -0.596999;-0.344677;-0.724423;,
  -0.257744;-0.934348;0.246093;,
  -0.298494;-0.947659;0.113333;,
  -0.333511;-0.942746;0.000000;,
  -0.298493;-0.947659;-0.113333;,
  -0.257744;-0.934348;-0.246093;,
  0.235901;-0.942494;0.236760;,
  -0.110470;-0.993879;0.000000;,
  0.064058;-0.987484;-0.144127;;
  199;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,25,33,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,33,41,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,41,49,56;,
  3;49,50,57;,
  3;50,51,57;,
  3;51,52,57;,
  3;52,53,57;,
  3;53,54,57;,
  3;54,55,57;,
  3;55,56,57;,
  3;56,49,57;,
  4;58,59,67,66;,
  4;59,60,68,67;,
  4;60,61,69,68;,
  4;61,62,70,69;,
  4;62,63,71,70;,
  4;63,64,72,71;,
  4;64,65,73,72;,
  4;65,58,66,73;,
  4;66,67,75,74;,
  4;67,188,76,75;,
  4;68,69,77,189;,
  4;69,70,78,77;,
  4;70,71,79,78;,
  4;71,72,80,79;,
  4;190,73,81,190;,
  4;73,66,74,81;,
  4;74,75,83,82;,
  4;75,76,84,83;,
  4;189,191,85,192;,
  4;191,78,86,85;,
  4;78,79,87,86;,
  4;79,80,88,87;,
  4;193,194,89,193;,
  4;194,74,82,89;,
  4;82,83,91,90;,
  4;83,84,92,91;,
  4;192,85,93,92;,
  4;85,86,94,93;,
  4;86,87,95,94;,
  4;87,88,96,95;,
  4;88,89,97,96;,
  4;89,82,90,97;,
  4;90,91,99,98;,
  4;91,92,100,99;,
  4;92,93,101,100;,
  4;93,94,102,101;,
  4;94,95,103,102;,
  4;95,96,104,103;,
  4;96,97,105,104;,
  4;97,90,98,105;,
  4;98,99,107,106;,
  4;99,100,108,107;,
  4;100,101,109,195;,
  4;101,102,110,109;,
  4;102,103,111,110;,
  4;103,104,112,111;,
  4;104,105,113,196;,
  4;105,98,106,113;,
  4;106,107,115,114;,
  4;107,108,116,115;,
  4;195,197,117,198;,
  4;197,199,118,117;,
  4;110,111,119,118;,
  4;111,112,120,119;,
  4;200,201,121,200;,
  4;201,202,114,121;,
  4;114,115,59,58;,
  4;115,116,60,59;,
  4;116,117,61,60;,
  4;117,118,62,61;,
  4;118,119,63,62;,
  4;119,120,64,63;,
  4;120,121,65,64;,
  4;121,114,58,65;,
  3;122,124,123;,
  3;122,125,124;,
  3;122,126,125;,
  3;122,127,126;,
  3;122,128,127;,
  3;122,129,128;,
  3;122,130,129;,
  3;122,123,130;,
  4;123,124,132,131;,
  4;124,125,133,132;,
  4;125,126,134,133;,
  4;126,127,135,134;,
  4;127,128,136,135;,
  4;128,129,137,136;,
  4;129,130,138,137;,
  4;130,123,131,138;,
  4;131,132,140,139;,
  4;132,133,141,140;,
  4;133,134,142,141;,
  4;134,135,143,142;,
  4;135,136,144,143;,
  4;136,137,145,144;,
  4;137,138,146,145;,
  4;138,131,139,146;,
  4;139,140,148,147;,
  4;140,141,149,148;,
  4;141,142,150,149;,
  4;142,143,151,150;,
  4;143,144,152,151;,
  4;144,145,153,152;,
  4;145,146,154,153;,
  4;146,139,147,154;,
  4;147,148,156,155;,
  4;148,149,157,156;,
  4;149,150,158,157;,
  4;150,151,159,158;,
  4;151,152,160,159;,
  4;152,153,161,160;,
  4;153,154,162,161;,
  4;154,147,155,162;,
  4;155,156,164,163;,
  4;156,157,165,164;,
  4;157,158,166,165;,
  4;158,159,167,166;,
  4;159,160,168,167;,
  4;160,161,169,168;,
  4;161,162,170,169;,
  4;162,155,163,170;,
  4;203,204,172,171;,
  4;204,205,173,172;,
  4;205,206,174,173;,
  4;206,207,175,174;,
  4;167,208,176,175;,
  4;168,209,177,176;,
  4;209,210,178,177;,
  4;210,163,171,178;,
  4;171,172,180,179;,
  4;172,173,181,180;,
  4;173,174,182,181;,
  4;174,175,183,182;,
  4;175,176,184,183;,
  4;176,177,185,184;,
  4;177,178,186,185;,
  4;178,171,179,186;,
  3;179,180,187;,
  3;180,181,187;,
  3;181,182,187;,
  3;182,183,187;,
  3;183,184,187;,
  3;184,185,187;,
  3;185,186,187;,
  3;186,179,187;;
 }
 MeshTextureCoords {
  248;
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.250000;0.500000;,
  0.125000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.000000;0.000000;,
  0.000000;0.125000;,
  0.125000;0.125000;,
  0.125000;0.000000;,
  0.000000;0.250000;,
  0.125000;0.250000;,
  0.000000;0.375000;,
  0.125000;0.375000;,
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.000000;0.625000;,
  0.125000;0.625000;,
  0.000000;0.750000;,
  0.125000;0.750000;,
  0.000000;0.875000;,
  0.125000;0.875000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.250000;0.125000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.250000;0.375000;,
  0.250000;0.500000;,
  0.250000;0.625000;,
  0.250000;0.750000;,
  0.250000;0.875000;,
  0.250000;1.000000;,
  0.375000;0.125000;,
  0.375000;0.000000;,
  0.375000;0.250000;,
  0.375000;0.375000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.375000;0.750000;,
  0.375000;0.875000;,
  0.375000;1.000000;,
  0.500000;0.125000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.500000;0.375000;,
  0.500000;0.500000;,
  0.500000;0.625000;,
  0.500000;0.750000;,
  0.500000;0.875000;,
  0.500000;1.000000;,
  0.625000;0.125000;,
  0.625000;0.000000;,
  0.625000;0.250000;,
  0.625000;0.375000;,
  0.625000;0.500000;,
  0.625000;0.625000;,
  0.625000;0.750000;,
  0.625000;0.875000;,
  0.625000;1.000000;,
  0.750000;0.125000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  0.750000;0.375000;,
  0.750000;0.500000;,
  0.750000;0.625000;,
  0.750000;0.750000;,
  0.750000;0.875000;,
  0.750000;1.000000;,
  0.875000;0.125000;,
  0.875000;0.000000;,
  0.875000;0.250000;,
  0.875000;0.375000;,
  0.875000;0.500000;,
  0.875000;0.625000;,
  0.875000;0.750000;,
  0.875000;0.875000;,
  0.875000;1.000000;,
  1.000000;0.125000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  1.000000;0.375000;,
  1.000000;0.500000;,
  1.000000;0.625000;,
  1.000000;0.750000;,
  1.000000;0.875000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.125000;0.111110;,
  0.000000;0.111110;,
  0.187500;0.000000;,
  0.250000;0.111110;,
  0.312500;0.000000;,
  0.375000;0.111110;,
  0.437500;0.000000;,
  0.500000;0.111110;,
  0.562500;0.000000;,
  0.625000;0.111110;,
  0.687500;0.000000;,
  0.750000;0.111110;,
  0.812500;0.000000;,
  0.875000;0.111110;,
  0.937500;0.000000;,
  1.000000;0.111110;,
  0.125000;0.222220;,
  0.000000;0.222220;,
  0.250000;0.222220;,
  0.375000;0.222220;,
  0.500000;0.222220;,
  0.625000;0.222220;,
  0.750000;0.222220;,
  0.875000;0.222220;,
  1.000000;0.222220;,
  0.125000;0.333330;,
  0.000000;0.333330;,
  0.250000;0.333330;,
  0.375000;0.333330;,
  0.500000;0.333330;,
  0.625000;0.333330;,
  0.750000;0.333330;,
  0.875000;0.333330;,
  1.000000;0.333330;,
  0.125000;0.444440;,
  0.000000;0.444440;,
  0.250000;0.444440;,
  0.375000;0.444440;,
  0.500000;0.444440;,
  0.625000;0.444440;,
  0.750000;0.444440;,
  0.875000;0.444440;,
  1.000000;0.444440;,
  0.125000;0.555560;,
  0.000000;0.555560;,
  0.250000;0.555560;,
  0.375000;0.555560;,
  0.500000;0.555560;,
  0.625000;0.555560;,
  0.750000;0.555560;,
  0.875000;0.555560;,
  1.000000;0.555560;,
  0.125000;0.666670;,
  0.000000;0.666670;,
  0.250000;0.666670;,
  0.375000;0.666670;,
  0.500000;0.666670;,
  0.625000;0.666670;,
  0.750000;0.666670;,
  0.875000;0.666670;,
  1.000000;0.666670;,
  0.125000;0.777780;,
  0.000000;0.777780;,
  0.250000;0.777780;,
  0.375000;0.777780;,
  0.500000;0.777780;,
  0.625000;0.777780;,
  0.750000;0.777780;,
  0.875000;0.777780;,
  1.000000;0.777780;,
  0.125000;0.888890;,
  0.000000;0.888890;,
  0.250000;0.888890;,
  0.375000;0.888890;,
  0.500000;0.888890;,
  0.625000;0.888890;,
  0.750000;0.888890;,
  0.875000;0.888890;,
  1.000000;0.888890;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
