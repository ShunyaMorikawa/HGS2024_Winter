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
 0.74268;-25.70868;1.15086;,
 1.48538;-24.66717;1.69046;,
 0.56736;-24.66717;2.35743;,
 0.28368;-25.70868;1.48435;,
 -0.56736;-24.66717;2.35743;,
 -0.28368;-25.70868;1.48435;,
 -1.48538;-24.66717;1.69046;,
 -0.74268;-25.70868;1.15086;,
 -1.83602;-24.66717;0.61127;,
 -0.91801;-25.70868;0.61127;,
 -1.48538;-24.66717;-0.46792;,
 -0.74268;-25.70868;0.07168;,
 -0.56736;-24.66717;-1.13489;,
 -0.28368;-25.70868;-0.26181;,
 0.56736;-24.66717;-1.13489;,
 0.28368;-25.70868;-0.26181;,
 1.48538;-24.66717;-0.46792;,
 0.74268;-25.70868;0.07168;,
 1.83602;-24.66717;0.61127;,
 0.91801;-25.70868;0.61127;,
 2.59850;-22.49574;2.49919;,
 0.99254;-22.49574;3.66599;,
 -0.99254;-22.49574;3.66599;,
 -2.59850;-22.49574;2.49919;,
 -3.21192;-22.49574;0.61127;,
 -2.59850;-22.49574;-1.27665;,
 -0.99254;-22.49574;-2.44345;,
 0.99254;-22.49574;-2.44345;,
 2.59850;-22.49574;-1.27665;,
 3.21192;-22.49574;0.61127;,
 2.59850;-22.49574;2.49919;,
 2.69128;-18.25409;2.56660;,
 1.02798;-18.25409;3.77506;,
 0.99254;-22.49574;3.66599;,
 -1.02798;-18.25409;3.77506;,
 -0.99254;-22.49574;3.66599;,
 -2.69129;-18.25409;2.56660;,
 -2.59850;-22.49574;2.49919;,
 -3.32661;-18.25409;0.61127;,
 -3.21192;-22.49574;0.61127;,
 -2.69128;-18.25409;-1.34406;,
 -2.59850;-22.49574;-1.27665;,
 -1.02798;-18.25409;-2.55252;,
 -0.99254;-22.49574;-2.44345;,
 1.02798;-18.25409;-2.55252;,
 0.99254;-22.49574;-2.44345;,
 2.69128;-18.25409;-1.34406;,
 2.59850;-22.49574;-1.27665;,
 3.32660;-18.25409;0.61127;,
 3.21192;-22.49574;0.61127;,
 2.69128;-18.25409;2.56660;,
 2.59850;-22.49574;2.49919;,
 2.73497;-15.75035;2.59834;,
 1.04466;-15.75035;3.82642;,
 -1.04466;-15.75035;3.82642;,
 -2.73497;-15.75035;2.59834;,
 -3.38060;-15.75035;0.61127;,
 -2.73497;-15.75035;-1.37580;,
 -1.04466;-15.75035;-2.60388;,
 1.04466;-15.75035;-2.60388;,
 2.73497;-15.75035;-1.37580;,
 3.38060;-15.75035;0.61127;,
 2.73497;-15.75035;2.59834;,
 2.97778;-2.82293;2.77475;,
 1.13741;-2.82293;4.11186;,
 -1.13741;-2.82293;4.11186;,
 -2.97778;-2.82293;2.77475;,
 -3.68073;-2.82293;0.61127;,
 -2.97778;-2.82293;-1.55222;,
 -1.13741;-2.82293;-2.88932;,
 1.13741;-2.82293;-2.88932;,
 2.97778;-2.82293;-1.55221;,
 3.68073;-2.82293;0.61127;,
 2.97778;-2.82293;2.77475;,
 2.95496;-0.00028;2.75817;,
 1.12869;-0.00028;4.08504;,
 -1.12869;-0.00028;4.08504;,
 -2.95496;-0.00028;2.75817;,
 -3.65253;-0.00028;0.61127;,
 -2.95496;-0.00028;-1.53564;,
 -1.12869;-0.00028;-2.86250;,
 1.12869;-0.00028;-2.86250;,
 2.95496;-0.00028;-1.53564;,
 3.65253;-0.00028;0.61127;,
 2.95496;-0.00028;2.75817;,
 2.95496;-0.00028;2.75817;,
 2.15071;2.07183;2.17385;,
 0.82150;2.07183;3.13958;,
 1.12869;-0.00028;4.08504;,
 -0.82150;2.07183;3.13958;,
 -1.12869;-0.00028;4.08504;,
 -2.15071;2.07183;2.17385;,
 -2.95496;-0.00028;2.75817;,
 -2.65841;2.07183;0.61127;,
 -3.65253;-0.00028;0.61127;,
 -2.15071;2.07183;-0.95131;,
 -2.95496;-0.00028;-1.53564;,
 -0.82150;2.07183;-1.91704;,
 -1.12869;-0.00028;-2.86250;,
 0.82150;2.07183;-1.91704;,
 1.12869;-0.00028;-2.86250;,
 2.15071;2.07183;-0.95131;,
 2.95496;-0.00028;-1.53564;,
 2.65841;2.07183;0.61127;,
 3.65253;-0.00028;0.61127;,
 1.07535;2.79182;1.39256;,
 0.41075;2.79182;1.87542;,
 -0.41075;2.79182;1.87542;,
 -1.07535;2.79182;1.39256;,
 -1.32921;2.79182;0.61127;,
 -1.07535;2.79182;-0.17002;,
 -0.41075;2.79182;-0.65288;,
 0.41075;2.79182;-0.65288;,
 1.07535;2.79182;-0.17002;,
 1.32921;2.79182;0.61127;,
 0.00000;-25.70868;0.61127;,
 0.00000;2.79182;0.61127;;
 
 100;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;9,8,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;17,16,18,19;,
 4;19,18,1,0;,
 4;1,20,21,2;,
 4;2,21,22,4;,
 4;4,22,23,6;,
 4;6,23,24,8;,
 4;8,24,25,10;,
 4;10,25,26,12;,
 4;12,26,27,14;,
 4;14,27,28,16;,
 4;16,28,29,18;,
 4;18,29,20,1;,
 4;30,31,32,33;,
 4;33,32,34,35;,
 4;35,34,36,37;,
 4;37,36,38,39;,
 4;39,38,40,41;,
 4;41,40,42,43;,
 4;43,42,44,45;,
 4;45,44,46,47;,
 4;47,46,48,49;,
 4;49,48,50,51;,
 4;31,52,53,32;,
 4;32,53,54,34;,
 4;34,54,55,36;,
 4;36,55,56,38;,
 4;38,56,57,40;,
 4;40,57,58,42;,
 4;42,58,59,44;,
 4;44,59,60,46;,
 4;46,60,61,48;,
 4;48,61,62,50;,
 4;52,63,64,53;,
 4;53,64,65,54;,
 4;54,65,66,55;,
 4;55,66,67,56;,
 4;56,67,68,57;,
 4;57,68,69,58;,
 4;58,69,70,59;,
 4;59,70,71,60;,
 4;60,71,72,61;,
 4;61,72,73,62;,
 4;63,74,75,64;,
 4;64,75,76,65;,
 4;65,76,77,66;,
 4;66,77,78,67;,
 4;67,78,79,68;,
 4;68,79,80,69;,
 4;69,80,81,70;,
 4;70,81,82,71;,
 4;71,82,83,72;,
 4;72,83,84,73;,
 4;85,86,87,88;,
 4;88,87,89,90;,
 4;90,89,91,92;,
 4;92,91,93,94;,
 4;94,93,95,96;,
 4;96,95,97,98;,
 4;98,97,99,100;,
 4;100,99,101,102;,
 4;102,101,103,104;,
 4;104,103,86,85;,
 4;86,105,106,87;,
 4;87,106,107,89;,
 4;89,107,108,91;,
 4;91,108,109,93;,
 4;93,109,110,95;,
 4;95,110,111,97;,
 4;97,111,112,99;,
 4;99,112,113,101;,
 4;101,113,114,103;,
 4;103,114,105,86;,
 3;3,115,0;,
 3;5,115,3;,
 3;7,115,5;,
 3;9,115,7;,
 3;11,115,9;,
 3;13,115,11;,
 3;15,115,13;,
 3;17,115,15;,
 3;19,115,17;,
 3;0,115,19;,
 3;105,116,106;,
 3;106,116,107;,
 3;107,116,108;,
 3;108,116,109;,
 3;109,116,110;,
 3;110,116,111;,
 3;111,116,112;,
 3;112,116,113;,
 3;113,116,114;,
 3;114,116,105;;
 
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
  92;
  0.328150;-0.914044;0.238415;,
  0.125343;-0.914043;0.385765;,
  -0.125343;-0.914043;0.385765;,
  -0.328150;-0.914044;0.238415;,
  -0.405616;-0.914044;-0.000000;,
  -0.328150;-0.914044;-0.238415;,
  -0.125342;-0.914043;-0.385764;,
  0.125342;-0.914043;-0.385764;,
  0.328150;-0.914044;-0.238415;,
  0.405616;-0.914044;-0.000000;,
  0.647011;-0.600333;0.470081;,
  0.247136;-0.600332;0.760608;,
  -0.247136;-0.600332;0.760608;,
  -0.647011;-0.600333;0.470081;,
  -0.799750;-0.600333;-0.000000;,
  -0.647012;-0.600333;-0.470081;,
  -0.247136;-0.600333;-0.760608;,
  0.247136;-0.600333;-0.760608;,
  0.647012;-0.600333;-0.470081;,
  0.799750;-0.600333;-0.000000;,
  0.773405;-0.293431;0.561910;,
  0.295414;-0.293432;0.909191;,
  -0.295413;-0.293432;0.909191;,
  -0.773404;-0.293432;0.561910;,
  -0.955980;-0.293431;-0.000001;,
  -0.773404;-0.293431;-0.561911;,
  -0.295414;-0.293431;-0.909191;,
  0.295414;-0.293431;-0.909191;,
  0.773405;-0.293431;-0.561910;,
  0.955980;-0.293430;-0.000000;,
  0.808779;-0.024295;0.587611;,
  0.308926;-0.024296;0.950776;,
  -0.308925;-0.024295;0.950776;,
  -0.808779;-0.024295;0.587611;,
  -0.999705;-0.024295;-0.000001;,
  -0.808778;-0.024295;-0.587612;,
  -0.308926;-0.024296;-0.950776;,
  0.308926;-0.024296;-0.950776;,
  0.808779;-0.024295;-0.587611;,
  0.999705;-0.024295;-0.000000;,
  0.808815;-0.022387;0.587637;,
  0.308940;-0.022387;0.950818;,
  -0.308939;-0.022386;0.950818;,
  -0.808815;-0.022385;0.587637;,
  -0.999749;-0.022385;-0.000000;,
  -0.808815;-0.022386;-0.587637;,
  -0.308939;-0.022387;-0.950818;,
  0.308940;-0.022387;-0.950818;,
  0.808815;-0.022387;-0.587637;,
  0.999749;-0.022387;0.000000;,
  0.809000;-0.006610;0.587771;,
  0.309011;-0.006611;0.951036;,
  -0.309011;-0.006611;0.951036;,
  -0.809000;-0.006610;0.587771;,
  -0.999978;-0.006611;0.000001;,
  -0.809000;-0.006610;-0.587772;,
  -0.309009;-0.006611;-0.951036;,
  0.309010;-0.006611;-0.951036;,
  0.809000;-0.006611;-0.587771;,
  0.999978;-0.006611;0.000000;,
  0.787777;0.227645;0.572351;,
  0.300904;0.227645;0.926085;,
  -0.300904;0.227645;0.926085;,
  -0.787777;0.227645;0.572351;,
  -0.973744;0.227645;0.000001;,
  -0.787776;0.227646;-0.572351;,
  -0.300903;0.227645;-0.926086;,
  0.300904;0.227645;-0.926086;,
  0.787777;0.227645;-0.572351;,
  0.973744;0.227645;0.000000;,
  0.583274;0.692972;0.423771;,
  0.222791;0.692973;0.685677;,
  -0.222791;0.692973;0.685677;,
  -0.583274;0.692972;0.423771;,
  -0.720965;0.692972;0.000000;,
  -0.583273;0.692973;-0.423771;,
  -0.222790;0.692973;-0.685677;,
  0.222790;0.692973;-0.685677;,
  0.583273;0.692973;-0.423771;,
  0.720965;0.692972;0.000000;,
  0.197576;0.969721;0.143547;,
  0.075467;0.969721;0.232263;,
  -0.075467;0.969721;0.232263;,
  -0.197576;0.969721;0.143547;,
  -0.244217;0.969721;0.000000;,
  -0.197576;0.969721;-0.143547;,
  -0.075467;0.969721;-0.232263;,
  0.075467;0.969721;-0.232263;,
  0.197576;0.969721;-0.143547;,
  0.244217;0.969721;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;;
  100;
  4;0,10,11,1;,
  4;1,11,12,2;,
  4;2,12,13,3;,
  4;3,13,14,4;,
  4;4,14,15,5;,
  4;5,15,16,6;,
  4;6,16,17,7;,
  4;7,17,18,8;,
  4;8,18,19,9;,
  4;9,19,10,0;,
  4;10,20,21,11;,
  4;11,21,22,12;,
  4;12,22,23,13;,
  4;13,23,24,14;,
  4;14,24,25,15;,
  4;15,25,26,16;,
  4;16,26,27,17;,
  4;17,27,28,18;,
  4;18,28,29,19;,
  4;19,29,20,10;,
  4;20,30,31,21;,
  4;21,31,32,22;,
  4;22,32,33,23;,
  4;23,33,34,24;,
  4;24,34,35,25;,
  4;25,35,36,26;,
  4;26,36,37,27;,
  4;27,37,38,28;,
  4;28,38,39,29;,
  4;29,39,30,20;,
  4;30,40,41,31;,
  4;31,41,42,32;,
  4;32,42,43,33;,
  4;33,43,44,34;,
  4;34,44,45,35;,
  4;35,45,46,36;,
  4;36,46,47,37;,
  4;37,47,48,38;,
  4;38,48,49,39;,
  4;39,49,40,30;,
  4;40,50,51,41;,
  4;41,51,52,42;,
  4;42,52,53,43;,
  4;43,53,54,44;,
  4;44,54,55,45;,
  4;45,55,56,46;,
  4;46,56,57,47;,
  4;47,57,58,48;,
  4;48,58,59,49;,
  4;49,59,50,40;,
  4;50,60,61,51;,
  4;51,61,62,52;,
  4;52,62,63,53;,
  4;53,63,64,54;,
  4;54,64,65,55;,
  4;55,65,66,56;,
  4;56,66,67,57;,
  4;57,67,68,58;,
  4;58,68,69,59;,
  4;59,69,60,50;,
  4;60,70,71,61;,
  4;61,71,72,62;,
  4;62,72,73,63;,
  4;63,73,74,64;,
  4;64,74,75,65;,
  4;65,75,76,66;,
  4;66,76,77,67;,
  4;67,77,78,68;,
  4;68,78,79,69;,
  4;69,79,70,60;,
  4;70,80,81,71;,
  4;71,81,82,72;,
  4;72,82,83,73;,
  4;73,83,84,74;,
  4;74,84,85,75;,
  4;75,85,86,76;,
  4;76,86,87,77;,
  4;77,87,88,78;,
  4;78,88,89,79;,
  4;79,89,80,70;,
  3;1,90,0;,
  3;2,90,1;,
  3;3,90,2;,
  3;4,90,3;,
  3;5,90,4;,
  3;6,90,5;,
  3;7,90,6;,
  3;8,90,7;,
  3;9,90,8;,
  3;0,90,9;,
  3;80,91,81;,
  3;81,91,82;,
  3;82,91,83;,
  3;83,91,84;,
  3;84,91,85;,
  3;85,91,86;,
  3;86,91,87;,
  3;87,91,88;,
  3;88,91,89;,
  3;89,91,80;;
 }
 MeshTextureCoords {
  117;
  0.950444;0.941585;,
  0.962616;0.950429;,
  0.947570;0.961360;,
  0.942920;0.947051;,
  0.928972;0.961360;,
  0.933621;0.947051;,
  0.913926;0.950429;,
  0.926098;0.941585;,
  0.908178;0.932741;,
  0.923225;0.932741;,
  0.913926;0.915053;,
  0.926098;0.923897;,
  0.928972;0.904121;,
  0.933621;0.918431;,
  0.947570;0.904121;,
  0.942920;0.918431;,
  0.962616;0.915053;,
  0.950444;0.923897;,
  0.968364;0.932741;,
  0.953317;0.932741;,
  0.974789;0.959273;,
  0.952220;0.975670;,
  0.924322;0.975670;,
  0.901753;0.959273;,
  0.893132;0.932741;,
  0.901753;0.906209;,
  0.924322;0.889811;,
  0.952220;0.889811;,
  0.974789;0.906209;,
  0.983410;0.932741;,
  0.902160;0.887602;,
  0.902160;0.860451;,
  0.909382;0.860451;,
  0.909382;0.887602;,
  0.916604;0.860451;,
  0.916604;0.887602;,
  0.923826;0.860451;,
  0.923826;0.887602;,
  0.931049;0.860451;,
  0.931049;0.887602;,
  0.938271;0.860451;,
  0.938271;0.887602;,
  0.945493;0.860451;,
  0.945493;0.887602;,
  0.952715;0.860451;,
  0.952715;0.887602;,
  0.959938;0.860451;,
  0.959938;0.887602;,
  0.967160;0.860451;,
  0.967160;0.887602;,
  0.974382;0.860451;,
  0.974382;0.887602;,
  0.902160;0.833299;,
  0.909382;0.833299;,
  0.916604;0.833299;,
  0.923826;0.833299;,
  0.931049;0.833299;,
  0.938271;0.833299;,
  0.945493;0.833299;,
  0.952715;0.833299;,
  0.959938;0.833299;,
  0.967160;0.833299;,
  0.974382;0.833299;,
  0.902160;0.806148;,
  0.909382;0.806148;,
  0.916604;0.806148;,
  0.923826;0.806148;,
  0.931049;0.806148;,
  0.938271;0.806148;,
  0.945493;0.806148;,
  0.952715;0.806148;,
  0.959938;0.806148;,
  0.967160;0.806148;,
  0.974382;0.806148;,
  0.902160;0.778997;,
  0.909382;0.778997;,
  0.916604;0.778997;,
  0.923826;0.778997;,
  0.931049;0.778997;,
  0.938271;0.778997;,
  0.945493;0.778997;,
  0.952715;0.778997;,
  0.959938;0.778997;,
  0.967160;0.778997;,
  0.974382;0.778997;,
  0.974789;0.707597;,
  0.962616;0.716442;,
  0.947570;0.705510;,
  0.952220;0.691200;,
  0.928972;0.705510;,
  0.924322;0.691200;,
  0.913926;0.716442;,
  0.901753;0.707597;,
  0.908178;0.734129;,
  0.893132;0.734129;,
  0.913926;0.751817;,
  0.901753;0.760661;,
  0.928972;0.762749;,
  0.924322;0.777059;,
  0.947570;0.762749;,
  0.952220;0.777059;,
  0.962616;0.751817;,
  0.974789;0.760661;,
  0.968364;0.734129;,
  0.983410;0.734129;,
  0.950444;0.725286;,
  0.942920;0.719820;,
  0.933621;0.719820;,
  0.926098;0.725286;,
  0.923225;0.734129;,
  0.926098;0.742973;,
  0.933621;0.748439;,
  0.942920;0.748439;,
  0.950444;0.742973;,
  0.953317;0.734129;,
  0.938271;0.934546;,
  0.938271;0.735935;;
 }
}
