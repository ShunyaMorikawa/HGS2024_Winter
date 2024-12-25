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
 117;
 -0.96112;-4.05708;0.75461;,
 -0.33401;-4.05708;1.17543;,
 -0.66803;-4.05708;2.35085;,
 -1.92224;-4.05708;1.50923;,
 0.42068;-4.05708;1.14727;,
 0.84135;-4.05708;2.29454;,
 1.01468;-4.05708;0.68089;,
 2.02936;-4.05708;1.36178;,
 1.22111;-4.05708;-0.04556;,
 2.44223;-4.05708;-0.09112;,
 0.96112;-4.05708;-0.75461;,
 1.92224;-4.05708;-1.50922;,
 0.33401;-4.05708;-1.17543;,
 0.66802;-4.05708;-2.35085;,
 -0.42068;-4.05708;-1.14727;,
 -0.84135;-4.05708;-2.29454;,
 -1.01468;-4.05708;-0.68089;,
 -2.02936;-4.05708;-1.36178;,
 -1.22111;-4.05708;0.04556;,
 -2.44223;-4.05708;0.09112;,
 -1.00204;-4.05708;3.52628;,
 -2.51520;-4.05708;2.25010;,
 1.26203;-4.05708;3.44180;,
 2.58719;-4.05708;2.05972;,
 2.84332;-4.05708;-0.10609;,
 2.71248;-4.05708;-8.24550;,
 0.76550;-4.05708;-9.86574;,
 -1.46648;-4.05708;-8.92129;,
 -2.86726;-4.05708;-6.73607;,
 -2.88518;-4.05708;0.10765;,
 -2.51520;-4.05708;2.25010;,
 -1.00204;-4.05708;3.52628;,
 -1.00204;-2.58569;3.52628;,
 -2.51520;-2.58569;2.25010;,
 1.26203;-4.05708;3.44180;,
 1.26203;-2.58569;3.44180;,
 2.58719;-4.05708;2.05972;,
 2.58719;-2.58569;2.05972;,
 2.84332;-4.05708;-0.10609;,
 2.84332;-2.58569;-0.10609;,
 2.71248;-4.05708;-8.24550;,
 2.71248;-2.58569;-8.24550;,
 0.76550;-4.05708;-9.86574;,
 0.76550;-2.58569;-9.86574;,
 -1.46648;-4.05708;-8.92129;,
 -1.46648;-2.58569;-8.92129;,
 -2.86726;-4.05708;-6.73607;,
 -2.86726;-2.58569;-6.73607;,
 -2.88518;-4.05708;0.10765;,
 -2.88518;-2.58569;0.10765;,
 -2.51520;-4.05708;2.25010;,
 -2.51520;-2.58569;2.25010;,
 -1.00204;-1.64223;3.52628;,
 -2.51520;-1.64223;2.25010;,
 1.26203;-1.64223;3.44180;,
 2.58719;-1.64223;2.05972;,
 2.84332;-1.64223;-0.10609;,
 2.70123;-1.85435;-7.14521;,
 0.83298;-1.85435;-8.05733;,
 -1.41643;-1.85435;-7.57995;,
 -3.16863;-1.85435;-5.38162;,
 -2.88518;-1.64223;0.10765;,
 -2.51520;-1.64223;2.25010;,
 -1.00204;-0.69877;3.52628;,
 -2.51520;-0.69877;2.25010;,
 1.26203;-0.69877;3.44180;,
 2.58719;-0.69877;2.05972;,
 2.84332;-0.69877;-0.10609;,
 2.60080;-0.75392;-4.55007;,
 0.91801;-0.92381;-5.77843;,
 -1.34606;-0.92381;-5.69395;,
 -3.04405;-0.69877;-2.04268;,
 -2.88518;-0.69877;0.10765;,
 -2.51520;-0.69877;2.25010;,
 -1.00204;0.97524;3.52628;,
 -2.51520;0.34439;2.25010;,
 1.26203;0.97524;3.44180;,
 2.58719;0.35785;2.05972;,
 2.84332;0.00000;-0.10609;,
 1.90221;0.61202;-2.22723;,
 1.03758;0.72138;-2.57362;,
 -1.22648;0.72138;-2.48914;,
 -2.44766;0.63361;-1.69367;,
 -2.88518;0.00000;0.10765;,
 -2.51520;0.34439;2.25010;,
 -2.51520;0.34439;2.25010;,
 -1.00204;0.97524;3.52628;,
 -0.66803;0.00000;2.35085;,
 -1.92224;0.00000;1.50923;,
 1.26203;0.97524;3.44180;,
 0.84135;0.00000;2.29454;,
 2.58719;0.35785;2.05972;,
 2.02936;0.00000;1.36178;,
 2.84332;0.00000;-0.10609;,
 2.44223;0.00000;-0.09112;,
 1.90221;0.61202;-2.22723;,
 1.92224;0.00000;-1.50922;,
 1.03758;0.72138;-2.57362;,
 0.66802;0.00000;-2.35085;,
 -1.22648;0.72138;-2.48914;,
 -0.84135;0.00000;-2.29454;,
 -2.44766;0.63361;-1.69367;,
 -2.02936;0.00000;-1.36178;,
 -2.88518;0.00000;0.10765;,
 -2.44223;0.00000;0.09112;,
 -0.33401;0.00000;1.17543;,
 -0.96112;0.00000;0.75461;,
 0.42068;0.00000;1.14727;,
 1.01468;0.00000;0.68089;,
 1.22111;0.00000;-0.04556;,
 0.96112;0.00000;-0.75461;,
 0.33401;0.00000;-1.17543;,
 -0.42068;0.00000;-1.14727;,
 -1.01468;0.00000;-0.68089;,
 -1.22111;0.00000;0.04556;,
 0.00000;-4.05708;-0.00000;,
 0.00000;0.00000;0.00000;;
 
 100;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;16,18,19,17;,
 4;18,0,3,19;,
 4;3,2,20,21;,
 4;2,5,22,20;,
 4;5,7,23,22;,
 4;7,9,24,23;,
 4;9,11,25,24;,
 4;11,13,26,25;,
 4;13,15,27,26;,
 4;15,17,28,27;,
 4;17,19,29,28;,
 4;19,3,21,29;,
 4;30,31,32,33;,
 4;31,34,35,32;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,44,45,43;,
 4;44,46,47,45;,
 4;46,48,49,47;,
 4;48,50,51,49;,
 4;33,32,52,53;,
 4;32,35,54,52;,
 4;35,37,55,54;,
 4;37,39,56,55;,
 4;39,41,57,56;,
 4;41,43,58,57;,
 4;43,45,59,58;,
 4;45,47,60,59;,
 4;47,49,61,60;,
 4;49,51,62,61;,
 4;53,52,63,64;,
 4;52,54,65,63;,
 4;54,55,66,65;,
 4;55,56,67,66;,
 4;56,57,68,67;,
 4;57,58,69,68;,
 4;58,59,70,69;,
 4;59,60,71,70;,
 4;60,61,72,71;,
 4;61,62,73,72;,
 4;64,63,74,75;,
 4;63,65,76,74;,
 4;65,66,77,76;,
 4;66,67,78,77;,
 4;67,68,79,78;,
 4;68,69,80,79;,
 4;69,70,81,80;,
 4;70,71,82,81;,
 4;71,72,83,82;,
 4;72,73,84,83;,
 4;85,86,87,88;,
 4;86,89,90,87;,
 4;89,91,92,90;,
 4;91,93,94,92;,
 4;93,95,96,94;,
 4;95,97,98,96;,
 4;97,99,100,98;,
 4;99,101,102,100;,
 4;101,103,104,102;,
 4;103,85,88,104;,
 4;88,87,105,106;,
 4;87,90,107,105;,
 4;90,92,108,107;,
 4;92,94,109,108;,
 4;94,96,110,109;,
 4;96,98,111,110;,
 4;98,100,112,111;,
 4;100,102,113,112;,
 4;102,104,114,113;,
 4;104,88,106,114;,
 3;1,0,115;,
 3;4,1,115;,
 3;6,4,115;,
 3;8,6,115;,
 3;10,8,115;,
 3;12,10,115;,
 3;14,12,115;,
 3;16,14,115;,
 3;18,16,115;,
 3;0,18,115;,
 3;106,105,116;,
 3;105,107,116;,
 3;107,108,116;,
 3;108,109,116;,
 3;109,110,116;,
 3;110,111,116;,
 3;111,112,116;,
 3;112,113,116;,
 3;113,114,116;,
 3;114,106,116;;
 
 MeshMaterialList {
  1;
  100;
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
  66;
  0.000000;-1.000000;-0.000000;,
  -0.867531;0.000000;0.497382;,
  -0.325626;0.000000;0.945499;,
  0.409456;0.000000;0.912330;,
  0.904306;0.000000;0.426885;,
  0.998722;0.004954;0.050288;,
  0.956687;0.007166;-0.291031;,
  0.315359;0.691222;-0.650200;,
  -0.672548;0.251831;-0.695889;,
  -0.954739;0.137201;-0.263911;,
  -0.994647;-0.048382;0.091306;,
  -0.325626;0.000000;0.945499;,
  0.409456;0.000000;0.912330;,
  0.904306;0.000000;0.426885;,
  0.998735;0.023546;0.044440;,
  0.998480;0.046962;-0.028857;,
  0.074154;0.904142;-0.420748;,
  -0.320632;0.854861;-0.407931;,
  -0.536021;0.754976;-0.377747;,
  -0.992696;-0.054158;0.107802;,
  -0.867532;0.000000;0.497382;,
  0.995938;0.089267;-0.011816;,
  0.973835;0.177273;-0.142195;,
  0.095743;0.900739;-0.423677;,
  -0.296005;0.838454;-0.457577;,
  -0.742424;0.588328;-0.320430;,
  -0.993573;0.048848;0.102111;,
  0.904306;0.000000;0.426885;,
  0.987796;0.142064;-0.063843;,
  0.668409;0.638787;-0.381025;,
  0.122849;0.884078;-0.450904;,
  -0.322394;0.779415;-0.537191;,
  -0.849497;0.432914;-0.301564;,
  -0.990185;0.109634;0.086681;,
  0.085896;0.986331;-0.140618;,
  0.042974;0.957068;-0.286660;,
  -0.068628;0.956061;-0.285023;,
  -0.106077;0.984737;-0.137990;,
  -0.149987;0.987737;0.043357;,
  -0.208002;0.938247;0.276455;,
  -0.165287;0.436877;0.884205;,
  0.265741;0.432726;0.861470;,
  0.245057;0.930903;0.270864;,
  0.147214;0.987766;0.051445;,
  0.000000;1.000000;0.000000;,
  0.998709;0.000000;0.050798;,
  0.902005;0.000000;-0.431726;,
  0.639662;0.000000;-0.768657;,
  -0.389693;0.000000;-0.920945;,
  -0.644621;0.000000;-0.764502;,
  -0.959287;0.000000;-0.282433;,
  -0.996458;0.000000;0.084093;,
  0.283889;0.845797;-0.451703;,
  0.234595;0.878759;-0.415630;,
  -0.127812;0.898350;-0.420276;,
  -0.993141;-0.108147;0.044449;,
  0.222559;0.885540;-0.407783;,
  -0.997710;-0.023247;0.063513;,
  0.170848;0.944766;-0.279693;,
  0.082706;0.829937;-0.551692;,
  -0.131951;0.825996;-0.548015;,
  -0.210646;0.938372;-0.274017;,
  -0.300008;0.949986;0.086724;,
  -0.397618;0.750077;0.528473;,
  0.462409;0.724535;0.511104;,
  0.295583;0.949716;0.103293;;
  100;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;20,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;4,45,5,4;,
  4;45,46,6,5;,
  4;46,47,7,6;,
  4;48,49,8,48;,
  4;49,50,9,8;,
  4;50,51,10,9;,
  4;51,20,1,10;,
  4;1,2,11,1;,
  4;2,3,12,11;,
  4;3,4,13,12;,
  4;4,5,14,13;,
  4;5,6,15,14;,
  4;52,7,16,53;,
  4;7,54,17,16;,
  4;8,9,18,17;,
  4;9,10,19,55;,
  4;10,1,1,19;,
  4;1,11,2,20;,
  4;11,12,12,2;,
  4;12,13,4,12;,
  4;13,14,21,4;,
  4;14,15,22,21;,
  4;53,16,23,56;,
  4;16,17,24,23;,
  4;17,18,25,24;,
  4;55,19,26,57;,
  4;19,1,20,26;,
  4;20,2,2,20;,
  4;2,12,3,2;,
  4;12,4,27,3;,
  4;4,21,28,27;,
  4;21,22,29,28;,
  4;56,23,30,29;,
  4;23,24,31,30;,
  4;24,25,32,31;,
  4;25,26,33,32;,
  4;26,20,20,33;,
  4;58,59,35,34;,
  4;59,60,36,35;,
  4;60,61,37,36;,
  4;61,62,38,37;,
  4;62,63,39,38;,
  4;63,40,40,39;,
  4;40,41,41,40;,
  4;41,64,42,41;,
  4;64,65,43,42;,
  4;65,58,34,43;,
  4;34,35,44,44;,
  4;35,36,44,44;,
  4;36,37,44,44;,
  4;37,38,44,44;,
  4;38,39,44,44;,
  4;39,44,44,44;,
  4;44,44,44,44;,
  4;44,42,44,44;,
  4;42,43,44,44;,
  4;43,34,44,44;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;44,44,44;,
  3;44,44,44;,
  3;44,44,44;,
  3;44,44,44;,
  3;44,44,44;,
  3;44,44,44;,
  3;44,44,44;,
  3;44,44,44;,
  3;44,44,44;,
  3;44,44,44;;
 }
 MeshTextureCoords {
  117;
  0.578402;0.944504;,
  0.573438;0.948111;,
  0.576506;0.957554;,
  0.586435;0.950340;,
  0.567301;0.948111;,
  0.564233;0.957554;,
  0.562336;0.944504;,
  0.554303;0.950340;,
  0.560440;0.938667;,
  0.550511;0.938667;,
  0.562336;0.932831;,
  0.554303;0.926995;,
  0.567301;0.929224;,
  0.564233;0.919781;,
  0.573438;0.929224;,
  0.576506;0.919781;,
  0.578402;0.932831;,
  0.586435;0.926995;,
  0.580299;0.938667;,
  0.590228;0.938667;,
  0.579574;0.966998;,
  0.594468;0.956176;,
  0.561164;0.966998;,
  0.546270;0.956176;,
  0.540581;0.938667;,
  0.546270;0.921158;,
  0.561164;0.910337;,
  0.579574;0.910337;,
  0.594468;0.921158;,
  0.600157;0.938667;,
  0.546539;0.908879;,
  0.551305;0.908879;,
  0.551305;0.890962;,
  0.546539;0.890962;,
  0.556071;0.908879;,
  0.556071;0.890962;,
  0.560837;0.908879;,
  0.560837;0.890962;,
  0.565603;0.908879;,
  0.565603;0.890962;,
  0.570369;0.908879;,
  0.570369;0.890962;,
  0.575136;0.908879;,
  0.575136;0.890962;,
  0.579902;0.908879;,
  0.579902;0.890962;,
  0.584668;0.908879;,
  0.584668;0.890962;,
  0.589434;0.908879;,
  0.589434;0.890962;,
  0.594200;0.908879;,
  0.594200;0.890962;,
  0.551305;0.873044;,
  0.546539;0.873044;,
  0.556071;0.873044;,
  0.560837;0.873044;,
  0.565603;0.873044;,
  0.570369;0.873044;,
  0.575136;0.873044;,
  0.579902;0.873044;,
  0.584668;0.873044;,
  0.589434;0.873044;,
  0.594200;0.873044;,
  0.551305;0.855127;,
  0.546539;0.855127;,
  0.556071;0.855127;,
  0.560837;0.855127;,
  0.565603;0.855127;,
  0.570369;0.855127;,
  0.575136;0.855127;,
  0.579902;0.855127;,
  0.584668;0.855127;,
  0.589434;0.855127;,
  0.594200;0.855127;,
  0.551305;0.837209;,
  0.546539;0.837209;,
  0.556071;0.837209;,
  0.560837;0.837209;,
  0.565603;0.837209;,
  0.570369;0.837209;,
  0.575136;0.837209;,
  0.579902;0.837209;,
  0.584668;0.837209;,
  0.589434;0.837209;,
  0.594200;0.837209;,
  0.594468;0.790091;,
  0.579574;0.779270;,
  0.576506;0.788713;,
  0.586435;0.795928;,
  0.561164;0.779270;,
  0.564233;0.788713;,
  0.546270;0.790091;,
  0.554303;0.795928;,
  0.540581;0.807600;,
  0.550511;0.807600;,
  0.546270;0.825109;,
  0.554303;0.819273;,
  0.561164;0.835930;,
  0.564233;0.826487;,
  0.579574;0.835930;,
  0.576506;0.826487;,
  0.594468;0.825109;,
  0.586435;0.819273;,
  0.600157;0.807600;,
  0.590228;0.807600;,
  0.573438;0.798157;,
  0.578402;0.801764;,
  0.567301;0.798157;,
  0.562336;0.801764;,
  0.560440;0.807600;,
  0.562336;0.813436;,
  0.567301;0.817044;,
  0.573438;0.817044;,
  0.578402;0.813436;,
  0.580299;0.807600;,
  0.570369;0.939859;,
  0.570369;0.808792;;
 }
}
