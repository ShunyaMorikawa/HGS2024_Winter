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
 177;
 -0.74760;133.43024;0.40152;,
 16.24335;126.15747;-31.97209;,
 -0.74760;126.15747;-36.15994;,
 -0.74760;133.43024;0.40152;,
 29.34165;126.15747;-20.36779;,
 -0.74760;133.43024;0.40152;,
 35.54715;126.15747;-4.00563;,
 -0.74760;133.43024;0.40152;,
 33.43785;126.15747;13.36617;,
 -0.74760;133.43024;0.40152;,
 23.49705;126.15747;27.76797;,
 -0.74760;133.43024;0.40152;,
 8.00205;126.15747;35.90036;,
 -0.74760;133.43024;0.40152;,
 -9.49725;126.15747;35.90036;,
 -0.74760;133.43024;0.40152;,
 -24.99240;126.15747;27.76797;,
 -0.74760;133.43024;0.40152;,
 -34.93305;126.15747;13.36617;,
 -0.74760;133.43024;0.40152;,
 -37.04250;126.15747;-4.00563;,
 -0.74760;133.43024;0.40152;,
 -30.83700;126.15747;-20.36779;,
 -0.74760;133.43024;0.40152;,
 -17.73855;126.15747;-31.97209;,
 -0.74760;133.43024;0.40152;,
 -0.74760;126.15747;-36.15994;,
 30.64740;105.44701;-59.41696;,
 -0.74760;105.44701;-67.15517;,
 54.85020;105.44701;-37.97508;,
 66.31635;105.44701;-7.74153;,
 62.41890;105.44701;24.35727;,
 44.05065;105.44701;50.96817;,
 15.41985;105.44701;65.99488;,
 -16.91505;105.44701;65.99488;,
 -45.54585;105.44701;50.96817;,
 -63.91410;105.44701;24.35727;,
 -67.81170;105.44701;-7.74168;,
 -56.34555;105.44701;-37.97508;,
 -32.14275;105.44701;-59.41696;,
 -0.74760;105.44701;-67.15517;,
 32.85930;65.17740;-62.93056;,
 -0.74760;65.17740;-73.04102;,
 59.96535;65.17740;-42.34143;,
 72.88275;74.45160;-10.23798;,
 67.79040;74.45160;25.83372;,
 46.72335;74.45160;54.05218;,
 20.37615;74.45160;78.97678;,
 -21.87135;74.45160;78.97678;,
 -48.94710;74.45160;55.86043;,
 -69.28080;74.45160;26.11946;,
 -74.37315;74.45160;-10.23798;,
 -59.39205;65.17740;-43.60083;,
 -32.72085;65.17740;-62.93056;,
 -0.74760;65.17740;-73.04102;,
 17.30835;51.28817;-69.37006;,
 -0.74760;51.28817;-72.89552;,
 65.95050;51.28817;-46.47287;,
 80.10225;37.89062;-11.11458;,
 74.59035;37.89062;28.41252;,
 51.54600;37.89062;59.49569;,
 22.11645;37.89062;86.03788;,
 -23.61180;37.89062;86.03788;,
 -53.76975;37.89062;61.30393;,
 -76.08075;37.89062;28.69841;,
 -81.59265;37.89062;-11.11458;,
 -65.37720;51.28817;-47.73196;,
 -15.86775;51.28817;-69.37006;,
 -0.74760;51.28817;-72.89552;,
 18.93705;1.32931;-77.75507;,
 -0.74760;1.32931;-80.38427;,
 71.89455;1.32931;-49.73986;,
 86.87565;1.32931;-10.23798;,
 81.78330;1.32931;31.70127;,
 57.78405;1.32931;66.47008;,
 20.37615;1.32931;86.10343;,
 -21.87135;1.32931;86.10343;,
 -59.27925;1.32931;66.47008;,
 -83.27850;1.32931;31.70127;,
 -88.37085;1.32931;-10.23798;,
 -73.38990;1.32931;-49.73986;,
 -15.52425;1.32931;-77.75507;,
 -0.74760;1.32931;-80.38427;,
 30.64740;0.24482;-59.41696;,
 -0.74760;0.24482;-67.15517;,
 54.85020;0.24482;-37.97508;,
 66.31635;0.24482;-7.74153;,
 62.41890;0.24482;24.35727;,
 44.05065;0.24482;50.96817;,
 15.41985;0.24482;65.99488;,
 -16.91505;0.24482;65.99488;,
 -45.54585;0.24482;50.96817;,
 -63.91410;0.24482;24.35727;,
 -67.81170;0.24482;-7.74168;,
 -56.34555;0.24482;-37.97508;,
 -32.14275;0.24482;-59.41696;,
 -0.74760;0.24482;-67.15517;,
 16.24335;0.67740;-31.97209;,
 -0.74760;0.67740;-36.15994;,
 29.34165;0.67740;-20.36779;,
 35.54715;0.67740;-4.00563;,
 33.43785;0.67740;13.36617;,
 23.49705;0.67740;27.76797;,
 8.00205;0.67740;35.90036;,
 -9.49725;0.67740;35.90036;,
 -24.99240;0.67740;27.76797;,
 -34.93305;0.67740;13.36617;,
 -37.04250;0.67740;-4.00563;,
 -30.83700;0.67740;-20.36779;,
 -17.73855;0.67740;-31.97209;,
 -0.74760;0.67740;-36.15994;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 -0.74760;0.61201;0.40152;,
 2.61750;32.64062;168.21186;,
 2.41545;49.32331;154.89726;,
 16.19970;55.03231;154.79751;,
 16.59705;38.59276;167.94456;,
 21.90945;68.81431;154.55706;,
 22.26930;52.68226;167.44641;,
 16.19970;82.59675;154.31631;,
 16.31130;66.65536;167.00977;,
 2.41545;88.30546;154.21686;,
 2.21355;72.32657;166.89021;,
 -11.36895;82.59675;154.31631;,
 -11.76615;66.37471;167.15751;,
 -17.07855;68.81431;154.55706;,
 -17.43855;52.28522;167.65536;,
 -11.36895;55.03231;154.79751;,
 -11.48055;38.31212;168.09216;,
 2.41545;49.32331;154.89726;,
 2.61750;32.64062;168.21186;,
 2.41545;63.78406;132.34356;,
 16.11105;69.45601;132.24471;,
 21.78390;83.14950;132.00591;,
 16.11105;96.84297;131.76651;,
 2.41545;102.51480;131.66751;,
 -11.28015;96.84297;131.76651;,
 -16.95300;83.14950;132.00591;,
 -11.28015;69.45601;132.24471;,
 2.41545;63.78406;132.34356;,
 2.41545;83.20846;101.40694;,
 14.81235;88.34281;101.31754;,
 19.94715;100.73772;101.10109;,
 14.81235;113.13254;100.88478;,
 2.41545;118.26691;100.79509;,
 -9.98145;113.13254;100.88478;,
 -15.11625;100.73772;101.10109;,
 -9.98145;88.34281;101.31754;,
 2.41545;83.20846;101.40694;,
 2.41545;100.12560;66.04289;,
 2.41545;100.12560;66.04289;,
 2.41545;100.12560;66.04289;,
 2.41545;100.12560;66.04289;,
 2.41545;100.12560;66.04289;,
 2.41545;100.12560;66.04289;,
 2.41545;100.12560;66.04289;,
 2.41545;100.12560;66.04289;,
 2.41545;52.48382;167.55111;,
 2.61750;32.64062;168.21186;,
 16.59705;38.59276;167.94456;,
 22.26930;52.68226;167.44641;,
 16.31130;66.65536;167.00977;,
 2.21355;72.32657;166.89021;,
 -11.76615;66.37471;167.15751;,
 -17.43855;52.28522;167.65536;,
 -11.48055;38.31212;168.09216;;
 
 144;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 3;17,18,16;,
 3;19,20,18;,
 3;21,22,20;,
 3;23,24,22;,
 3;25,26,24;,
 4;2,1,27,28;,
 4;1,4,29,27;,
 4;4,6,30,29;,
 4;6,8,31,30;,
 4;8,10,32,31;,
 4;10,12,33,32;,
 4;12,14,34,33;,
 4;14,16,35,34;,
 4;16,18,36,35;,
 4;18,20,37,36;,
 4;20,22,38,37;,
 4;22,24,39,38;,
 4;24,26,40,39;,
 4;28,27,41,42;,
 4;27,29,43,41;,
 4;29,30,44,43;,
 4;30,31,45,44;,
 4;31,32,46,45;,
 4;32,33,47,46;,
 4;33,34,48,47;,
 4;34,35,49,48;,
 4;35,36,50,49;,
 4;36,37,51,50;,
 4;37,38,52,51;,
 4;38,39,53,52;,
 4;39,40,54,53;,
 4;42,41,55,56;,
 4;41,43,57,55;,
 4;43,44,58,57;,
 4;44,45,59,58;,
 4;45,46,60,59;,
 4;46,47,61,60;,
 4;47,48,62,61;,
 4;48,49,63,62;,
 4;49,50,64,63;,
 4;50,51,65,64;,
 4;51,52,66,65;,
 4;52,53,67,66;,
 4;53,54,68,67;,
 4;56,55,69,70;,
 4;55,57,71,69;,
 4;57,58,72,71;,
 4;58,59,73,72;,
 4;59,60,74,73;,
 4;60,61,75,74;,
 4;61,62,76,75;,
 4;62,63,77,76;,
 4;63,64,78,77;,
 4;64,65,79,78;,
 4;65,66,80,79;,
 4;66,67,81,80;,
 4;67,68,82,81;,
 4;70,69,83,84;,
 4;69,71,85,83;,
 4;71,72,86,85;,
 4;72,73,87,86;,
 4;73,74,88,87;,
 4;74,75,89,88;,
 4;75,76,90,89;,
 4;76,77,91,90;,
 4;77,78,92,91;,
 4;78,79,93,92;,
 4;79,80,94,93;,
 4;80,81,95,94;,
 4;81,82,96,95;,
 4;84,83,97,98;,
 4;83,85,99,97;,
 4;85,86,100,99;,
 4;86,87,101,100;,
 4;87,88,102,101;,
 4;88,89,103,102;,
 4;89,90,104,103;,
 4;90,91,105,104;,
 4;91,92,106,105;,
 4;92,93,107,106;,
 4;93,94,108,107;,
 4;94,95,109,108;,
 4;95,96,110,109;,
 3;98,97,111;,
 3;97,99,112;,
 3;99,100,113;,
 3;100,101,114;,
 3;101,102,115;,
 3;102,103,116;,
 3;103,104,117;,
 3;104,105,118;,
 3;105,106,119;,
 3;106,107,120;,
 3;107,108,121;,
 3;108,109,122;,
 3;109,110,123;,
 4;124,125,126,127;,
 4;127,126,128,129;,
 4;129,128,130,131;,
 4;131,130,132,133;,
 4;133,132,134,135;,
 4;135,134,136,137;,
 4;137,136,138,139;,
 4;139,138,140,141;,
 4;125,142,143,126;,
 4;126,143,144,128;,
 4;128,144,145,130;,
 4;130,145,146,132;,
 4;132,146,147,134;,
 4;134,147,148,136;,
 4;136,148,149,138;,
 4;138,149,150,140;,
 4;142,151,152,143;,
 4;143,152,153,144;,
 4;144,153,154,145;,
 4;145,154,155,146;,
 4;146,155,156,147;,
 4;147,156,157,148;,
 4;148,157,158,149;,
 4;149,158,159,150;,
 3;151,160,152;,
 3;152,161,153;,
 3;153,162,154;,
 3;154,163,155;,
 3;155,164,156;,
 3;156,165,157;,
 3;157,166,158;,
 3;158,167,159;,
 3;168,169,170;,
 3;168,170,171;,
 3;168,171,172;,
 3;168,172,173;,
 3;168,173,174;,
 3;168,174,175;,
 3;168,175,176;,
 3;168,176,169;;
 
 MeshMaterialList {
  6;
  144;
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
  0,
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
  3,
  0,
  0,
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
  0,
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
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
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
  150;
  0.000000;1.000000;0.000000;,
  0.000000;0.924187;-0.381940;,
  0.177497;0.924187;-0.338191;,
  0.314332;0.924187;-0.216967;,
  0.379155;0.924187;-0.046039;,
  0.357121;0.924187;0.135438;,
  0.253274;0.924187;0.285886;,
  0.091405;0.924187;0.370842;,
  -0.091404;0.924187;0.370842;,
  -0.253274;0.924187;0.285886;,
  -0.357121;0.924187;0.135438;,
  -0.379155;0.924187;-0.046038;,
  -0.314330;0.924187;-0.216968;,
  -0.177497;0.924187;-0.338191;,
  -0.001927;0.528801;-0.848744;,
  0.391279;0.529190;-0.752900;,
  0.678072;0.546765;-0.491190;,
  0.822273;0.559210;-0.105598;,
  0.778790;0.548790;0.303834;,
  0.571704;0.561170;0.598534;,
  0.222168;0.620481;0.752094;,
  -0.214479;0.625962;0.749780;,
  -0.564597;0.575114;0.592008;,
  -0.777490;0.554371;0.296956;,
  -0.823467;0.556591;-0.110035;,
  -0.677354;0.540230;-0.499343;,
  -0.391619;0.524334;-0.756114;,
  -0.008163;0.082712;-0.996540;,
  0.416043;0.129022;-0.900146;,
  0.769620;0.219612;-0.599546;,
  0.967956;0.226897;-0.107607;,
  0.911726;0.182940;0.367816;,
  0.711052;0.196617;0.675090;,
  0.324990;0.270479;0.906213;,
  -0.306925;0.277777;0.910295;,
  -0.706651;0.213462;0.674595;,
  -0.916217;0.189749;0.352904;,
  -0.966949;0.224379;-0.121095;,
  -0.757414;0.211247;-0.617819;,
  -0.415779;0.117065;-0.901900;,
  -0.016288;0.102410;-0.994609;,
  0.340701;0.140126;-0.929671;,
  0.742785;0.214945;-0.634090;,
  0.971197;0.217482;-0.097354;,
  0.908173;0.205120;0.364893;,
  0.710785;0.180226;0.679929;,
  0.327811;0.130498;0.935687;,
  -0.312266;0.121448;0.942200;,
  -0.710491;0.167511;0.683478;,
  -0.914703;0.198667;0.351922;,
  -0.968738;0.222297;-0.110138;,
  -0.724636;0.215756;-0.654486;,
  -0.343138;0.129207;-0.930356;,
  -0.019719;0.157958;-0.987249;,
  0.304708;0.149668;-0.940613;,
  0.737642;0.153620;-0.657484;,
  0.978593;0.175068;-0.108201;,
  0.908962;0.214725;0.357324;,
  0.690250;0.172689;0.702662;,
  0.297104;0.061620;0.952855;,
  -0.288080;0.043949;0.956597;,
  -0.692787;0.145080;0.706398;,
  -0.914577;0.202726;0.349929;,
  -0.976419;0.182737;-0.114947;,
  -0.721480;0.156328;-0.674557;,
  -0.308824;0.141130;-0.940590;,
  -0.000636;-0.999497;-0.031722;,
  0.010632;-0.999524;-0.028966;,
  0.017204;-0.999708;-0.016976;,
  0.019038;-0.999816;-0.002312;,
  0.017932;-0.999816;0.006801;,
  0.012718;-0.999816;0.014355;,
  0.004590;-0.999816;0.018621;,
  -0.004590;-0.999816;0.018621;,
  -0.012718;-0.999816;0.014355;,
  -0.017932;-0.999816;0.006801;,
  -0.019038;-0.999816;-0.002312;,
  -0.017666;-0.999664;-0.018959;,
  -0.011730;-0.999429;-0.031691;,
  -0.000000;-0.999982;0.006084;,
  -0.002827;-0.999982;0.005387;,
  -0.005007;-0.999982;0.003456;,
  -0.006039;-0.999982;0.000733;,
  -0.005688;-0.999982;-0.002157;,
  -0.004034;-0.999982;-0.004554;,
  -0.001456;-0.999982;-0.005907;,
  0.001456;-0.999982;-0.005907;,
  0.004034;-0.999982;-0.004554;,
  0.005688;-0.999982;-0.002157;,
  0.006039;-0.999982;0.000733;,
  0.005007;-0.999982;0.003456;,
  0.002827;-0.999982;0.005387;,
  0.000000;-1.000000;0.000000;,
  0.001079;-0.622436;-0.782670;,
  0.566805;-0.506623;-0.649666;,
  0.818964;-0.346570;-0.457371;,
  0.305713;0.291859;0.906288;,
  0.001635;0.340863;0.940112;,
  -0.305268;0.292155;0.906343;,
  -0.835918;0.352520;0.420679;,
  -0.562707;-0.511056;-0.649756;,
  0.000555;-0.740693;-0.671844;,
  0.619203;-0.575102;-0.534645;,
  0.976115;-0.129314;-0.174577;,
  0.622572;0.580504;0.524804;,
  -0.000989;0.743419;0.668825;,
  -0.626476;0.579793;0.520930;,
  -0.979370;0.131687;0.153274;,
  -0.617073;-0.577302;-0.534737;,
  0.000000;-0.844371;-0.535759;,
  0.657371;-0.632125;-0.410221;,
  0.999508;0.002186;-0.031287;,
  0.671476;0.648021;0.359427;,
  0.000000;0.869216;0.494432;,
  -0.671477;0.648021;0.359426;,
  -0.999508;0.002186;-0.031289;,
  -0.657372;-0.632124;-0.410222;,
  0.000000;-0.875828;-0.482623;,
  0.644030;-0.636156;-0.424889;,
  0.965241;-0.002092;-0.261354;,
  0.712479;0.697242;-0.078910;,
  0.000000;0.999991;-0.004248;,
  -0.712479;0.697242;-0.078910;,
  -0.965241;-0.002092;-0.261354;,
  -0.644030;-0.636156;-0.424889;,
  0.632464;-0.640158;-0.436104;,
  0.004924;0.033337;0.999432;,
  -0.001270;-0.997004;-0.077338;,
  0.027731;-0.997145;-0.070235;,
  0.045875;-0.998070;-0.041861;,
  0.051912;-0.998632;-0.006303;,
  0.048895;-0.998632;0.018543;,
  0.034677;-0.998632;0.039142;,
  0.012515;-0.998632;0.050773;,
  -0.012515;-0.998632;0.050773;,
  -0.034677;-0.998632;0.039142;,
  -0.048895;-0.998632;0.018543;,
  -0.051912;-0.998632;-0.006303;,
  -0.046801;-0.997853;-0.045826;,
  -0.029921;-0.996684;-0.075670;,
  0.826809;0.358084;0.433776;,
  -0.814488;-0.353543;-0.460017;,
  0.632462;0.624547;-0.458184;,
  -0.632462;0.624547;-0.458184;,
  -0.632464;-0.640158;-0.436104;,
  0.004921;0.033330;0.999432;,
  0.004928;0.033339;0.999432;,
  0.004937;0.033343;0.999432;,
  0.004915;0.033337;0.999432;,
  0.004918;0.033334;0.999432;;
  144;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,9,8;,
  3;0,10,9;,
  3;0,11,10;,
  3;0,12,11;,
  3;0,13,12;,
  3;0,1,13;,
  4;1,2,15,14;,
  4;2,3,16,15;,
  4;3,4,17,16;,
  4;4,5,18,17;,
  4;5,6,19,18;,
  4;6,7,20,19;,
  4;7,8,21,20;,
  4;8,9,22,21;,
  4;9,10,23,22;,
  4;10,11,24,23;,
  4;11,12,25,24;,
  4;12,13,26,25;,
  4;13,1,14,26;,
  4;14,15,28,27;,
  4;15,16,29,28;,
  4;16,17,30,29;,
  4;17,18,31,30;,
  4;18,19,32,31;,
  4;19,20,33,32;,
  4;20,21,34,33;,
  4;21,22,35,34;,
  4;22,23,36,35;,
  4;23,24,37,36;,
  4;24,25,38,37;,
  4;25,26,39,38;,
  4;26,14,27,39;,
  4;27,28,41,40;,
  4;28,29,42,41;,
  4;29,30,43,42;,
  4;30,31,44,43;,
  4;31,32,45,44;,
  4;32,33,46,45;,
  4;33,34,47,46;,
  4;34,35,48,47;,
  4;35,36,49,48;,
  4;36,37,50,49;,
  4;37,38,51,50;,
  4;38,39,52,51;,
  4;39,27,40,52;,
  4;40,41,54,53;,
  4;41,42,55,54;,
  4;42,43,56,55;,
  4;43,44,57,56;,
  4;44,45,58,57;,
  4;45,46,59,58;,
  4;46,47,60,59;,
  4;47,48,61,60;,
  4;48,49,62,61;,
  4;49,50,63,62;,
  4;50,51,64,63;,
  4;51,52,65,64;,
  4;52,40,53,65;,
  4;127,128,67,66;,
  4;128,129,68,67;,
  4;129,130,69,68;,
  4;130,131,70,69;,
  4;131,132,71,70;,
  4;132,133,72,71;,
  4;133,134,73,72;,
  4;134,135,74,73;,
  4;135,136,75,74;,
  4;136,137,76,75;,
  4;137,138,77,76;,
  4;138,139,78,77;,
  4;139,127,66,78;,
  4;66,67,80,79;,
  4;67,68,81,80;,
  4;68,69,82,81;,
  4;69,70,83,82;,
  4;70,71,84,83;,
  4;71,72,85,84;,
  4;72,73,86,85;,
  4;73,74,87,86;,
  4;74,75,88,87;,
  4;75,76,89,88;,
  4;76,77,90,89;,
  4;77,78,91,90;,
  4;78,66,79,91;,
  3;79,80,92;,
  3;80,81,92;,
  3;81,82,92;,
  3;82,83,92;,
  3;83,84,92;,
  3;84,85,92;,
  3;85,86,92;,
  3;86,87,92;,
  3;87,88,92;,
  3;88,89,92;,
  3;89,90,92;,
  3;90,91,92;,
  3;91,79,92;,
  4;93,101,102,94;,
  4;94,102,103,95;,
  4;140,140,104,96;,
  4;96,104,105,97;,
  4;97,105,106,98;,
  4;98,106,107,99;,
  4;141,141,108,100;,
  4;100,108,101,93;,
  4;101,109,110,102;,
  4;102,110,111,103;,
  4;103,111,112,104;,
  4;104,112,113,105;,
  4;105,113,114,106;,
  4;106,114,115,107;,
  4;107,115,116,108;,
  4;108,116,109,101;,
  4;109,117,118,110;,
  4;110,118,119,111;,
  4;111,119,120,112;,
  4;112,120,121,113;,
  4;113,121,122,114;,
  4;114,122,123,115;,
  4;115,123,124,116;,
  4;116,124,117,109;,
  3;117,125,118;,
  3;118,125,119;,
  3;119,142,120;,
  3;120,142,121;,
  3;121,143,122;,
  3;122,143,123;,
  3;123,144,124;,
  3;124,144,117;,
  3;126,145,146;,
  3;126,146,147;,
  3;126,147,96;,
  3;126,96,97;,
  3;126,97,98;,
  3;126,98,148;,
  3;126,148,149;,
  3;126,149,145;;
 }
 MeshTextureCoords {
  177;
  0.038460;0.000000;,
  0.076920;0.125000;,
  0.000000;0.125000;,
  0.115380;0.000000;,
  0.153850;0.125000;,
  0.192310;0.000000;,
  0.230770;0.125000;,
  0.269230;0.000000;,
  0.307690;0.125000;,
  0.346150;0.000000;,
  0.384620;0.125000;,
  0.423080;0.000000;,
  0.461540;0.125000;,
  0.500000;0.000000;,
  0.538460;0.125000;,
  0.576920;0.000000;,
  0.615380;0.125000;,
  0.653850;0.000000;,
  0.692310;0.125000;,
  0.730770;0.000000;,
  0.769230;0.125000;,
  0.807690;0.000000;,
  0.846150;0.125000;,
  0.884620;0.000000;,
  0.923080;0.125000;,
  0.961540;0.000000;,
  1.000000;0.125000;,
  0.076920;0.250000;,
  0.000000;0.250000;,
  0.153850;0.250000;,
  0.230770;0.250000;,
  0.307690;0.250000;,
  0.384620;0.250000;,
  0.461540;0.250000;,
  0.538460;0.250000;,
  0.615380;0.250000;,
  0.692310;0.250000;,
  0.769230;0.250000;,
  0.846150;0.250000;,
  0.923080;0.250000;,
  1.000000;0.250000;,
  0.076920;0.375000;,
  0.000000;0.375000;,
  0.153850;0.375000;,
  0.230770;0.375000;,
  0.307690;0.375000;,
  0.384620;0.375000;,
  0.461540;0.375000;,
  0.538460;0.375000;,
  0.615380;0.375000;,
  0.692310;0.375000;,
  0.769230;0.375000;,
  0.846150;0.375000;,
  0.923080;0.375000;,
  1.000000;0.375000;,
  0.076920;0.500000;,
  0.000000;0.500000;,
  0.153850;0.500000;,
  0.230770;0.500000;,
  0.307690;0.500000;,
  0.384620;0.500000;,
  0.461540;0.500000;,
  0.538460;0.500000;,
  0.615380;0.500000;,
  0.692310;0.500000;,
  0.769230;0.500000;,
  0.846150;0.500000;,
  0.923080;0.500000;,
  1.000000;0.500000;,
  0.076920;0.625000;,
  0.000000;0.625000;,
  0.153850;0.625000;,
  0.230770;0.625000;,
  0.307690;0.625000;,
  0.384620;0.625000;,
  0.461540;0.625000;,
  0.538460;0.625000;,
  0.615380;0.625000;,
  0.692310;0.625000;,
  0.769230;0.625000;,
  0.846150;0.625000;,
  0.923080;0.625000;,
  1.000000;0.625000;,
  0.076920;0.750000;,
  0.000000;0.750000;,
  0.153850;0.750000;,
  0.230770;0.750000;,
  0.307690;0.750000;,
  0.384620;0.750000;,
  0.461540;0.750000;,
  0.538460;0.750000;,
  0.615380;0.750000;,
  0.692310;0.750000;,
  0.769230;0.750000;,
  0.846150;0.750000;,
  0.923080;0.750000;,
  1.000000;0.750000;,
  0.076920;0.875000;,
  0.000000;0.875000;,
  0.153850;0.875000;,
  0.230770;0.875000;,
  0.307690;0.875000;,
  0.384620;0.875000;,
  0.461540;0.875000;,
  0.538460;0.875000;,
  0.615380;0.875000;,
  0.692310;0.875000;,
  0.769230;0.875000;,
  0.846150;0.875000;,
  0.923080;0.875000;,
  1.000000;0.875000;,
  0.038460;1.000000;,
  0.115380;1.000000;,
  0.192310;1.000000;,
  0.269230;1.000000;,
  0.346150;1.000000;,
  0.423080;1.000000;,
  0.500000;1.000000;,
  0.576920;1.000000;,
  0.653850;1.000000;,
  0.730770;1.000000;,
  0.807690;1.000000;,
  0.884620;1.000000;,
  0.961540;1.000000;,
  0.000000;1.000000;,
  0.000000;0.750000;,
  0.125000;0.750000;,
  0.125000;1.000000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.375000;0.750000;,
  0.375000;1.000000;,
  0.500000;0.750000;,
  0.500000;1.000000;,
  0.625000;0.750000;,
  0.625000;1.000000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  0.875000;0.750000;,
  0.875000;1.000000;,
  1.000000;0.750000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.250000;,
  0.125000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
