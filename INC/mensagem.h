/* 
  PROJETO USPDesigner
  MODULO: MEM (Virtual Memory Manipulation)
  Copyright (C) 1989 a 2008, Marcos Tsuzuki, All rights reserved
  Universidade de Sao Paulo, EPUSP-PMR

   NOME DO ARQUIVO: mensagem.h
   Coded by Marcos Tsuzuki

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote 
        products derived from this software without specific prior written 
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   email: mtsuzuki at usp.br (remove space)
*/

#ifndef EXTERN
 #ifdef _DVS_
  #define EXTERN
 #else
  #define EXTERN    extern
 #endif
#endif

#ifdef _DVS_
const char *NAM_Area            = "AnaArea";
const char *NAM_AreaProjetada   = "AnaAreaProjetada";
const char *NAM_CentroCarena    = "AnaCentroCarena";
const char *NAM_CentroGravidade = "AnaCentroGravidade";
const char *NAM_DensAbs         = "AnaDensidadeAbsoluta";
const char *NAM_DensRel         = "AnaDensidadeRelativa";
const char *NAM_Massa           = "AnaMassa";
const char *NAM_Inercia         = "AnaInercia";
const char *NAM_Volume          = "AnaVolume";

const char *NAM_RovCirculo   = "RovCirculo";
const char *NAM_RovCone      = "RovCone";
const char *NAM_RovCubo      = "RovCubo";
const char *NAM_RovEsfera    = "RovEsfera";
const char *NAM_RovPerfilI   = "RovPerfilI";
const char *NAM_RovPerfilL   = "RovPerfilL";
const char *NAM_RovPerfilT   = "RovPerfilT";
const char *NAM_RovPiramide  = "RovPiramide";
const char *NAM_RovPlaca     = "RovPlaca";
const char *NAM_RovPrisma    = "RovPrisma";
const char *NAM_RovQuadrado  = "RovQuadrado";
const char *NAM_RovRetangulo = "RovRetangulo";
const char *NAM_RovTriangulo = "RovTriangulo";
const char *NAM_RovTranslate = "RovTranslate";
const char *NAM_RovRotate    = "RovRotate";
const char *NAM_DimPrinc     = "RovDimensaoPrincipal";
const char *NAM_RovOrdena    = "RovOrdena";

const char *NAM_AlteraCamaraCorrente        = "AltCamCor";
const char *NAM_AlteraCamara                = "AltCam";
const char *NAM_CopyCamara                  = "CpyCam";
const char *NAM_GetCamaraCorrenteParametros = "GetCamCorPar";
const char *NAM_ListCamara              = "LstCam";
const char *NAM_CreateCamara            = "CrtCam";
const char *NAM_RemoveCamara            = "DelCam";
const char *NAM_RenameCamara            = "RenCam";
const char *NAM_SetCamaraCorrente       = "SetCamCor";
const char *NAM_TranslateCamaraCorrente = "TrnCamCor";

const char *NAM_DisplayCoordinates = "DisCoo";
const char *NAM_SetFrameColor      = "FrmCol";
const char *NAM_SetDefaultColor    = "DftCol";
const char *NAM_SetElementColor    = "ElmCol";
const char *NAM_Display            = "Disp";
const char *NAM_DisplayFile        = "DisFle";
const char *NAM_DisplayEdge        = "DisEdg";
const char *NAM_Monitor            = "Monit";

const char *NAM_AddEulerOperator = "AddOp";
const char *NAM_KEF           = "kef";
const char *NAM_KEF2          = "kef2";
const char *NAM_KEMR          = "kemr";
const char *NAM_KEV           = "kev";
const char *NAM_KEV2          = "kev2";
const char *NAM_JVKE          = "jvke";
const char *NAM_JEKV          = "jekv";
const char *NAM_KFMRH         = "kfmrh";
const char *NAM_KSFMR         = "ksfmr";
const char *NAM_KVSF          = "kvsf";
const char *NAM_MEF           = "mef";
const char *NAM_MEF2          = "mef2";
const char *NAM_MEKR          = "mekr";
const char *NAM_MEKR2         = "mekr2";
const char *NAM_MEV           = "mev";
const char *NAM_SEMV          = "semv";
const char *NAM_SVME          = "svme";
const char *NAM_SVME2         = "svme2";
const char *NAM_SVME3         = "svme3";
const char *NAM_MFKRH         = "mfkrh";
const char *NAM_MFKRH2        = "mfkrh2";
const char *NAM_ModifyEulerOp = "ModEul";
const char *NAM_MSFKR         = "msfkr";
const char *NAM_MSFKR2        = "msfkr2";
const char *NAM_MVSF          = "mvsf";
const char *NAM_PrintEulerOp  = "PrtEul";
const char *NAM_ScanEulerOp   = "ScnEul";
const char *NAM_ApplyEulerOp  = "AppEul";
const char *NAM_Color         = "Color";
const char *NAM_Name          = "Nome";
const char *NAM_GetHE         = "GetHe";
const char *NAM_GetMate       = "GetMate";
const char *NAM_GetNext       = "GetNext";
const char *NAM_GetPrev       = "GetPrev";
const char *NAM_DoMEV         = "DoMEV";
const char *NAM_DoMEF         = "DoMEF";
const char *NAM_DoNewLoc      = "DoNewVertexLocation";
const char *NAM_DoPutTag      = "DoPutTag";
const char *NAM_DoEvalEdge    = "DoEvaluateEdge";
const char *NAM_AddLPoint     = "AddPoint";
const char *NAM_RemLPoint     = "RemPoint";
const char *NAM_EvalEdge      = "EvaluateEdge";
const char *NAM_KillCTag      = "KillCurveTag";
const char *NAM_KillPolyLine  = "KillPolyLine";
const char *NAM_NewLine       = "NewLine";
const char *NAM_NewPolyLine   = "NewPolyLine";
const char *NAM_LengthPoly    = "LengthPoly";
const char *NAM_PutCTag       = "PutCurveTag";
const char *NAM_Round         = "Round";
const char *NAM_RoundAll      = "RoundAll";

const char *NAM_AssociaAxisElemento    = "AssAxs";
const char *NAM_DesassociaAxisElemento = "DesAxs";
const char *NAM_CopySolid               = "CpySol";
const char *NAM_ListFaceAdjacency       = "LstFacAdj";
const char *NAM_AssociaGrupoElemento    = "AssGrp";
const char *NAM_DesassociaGrupoElemento = "DesGrp";
const char *NAM_LoadSolido              = "LodSol";
const char *NAM_RenameSolido            = "RenSol";
const char *NAM_SaveSolido              = "SavSol";

const char *NAM_AssociaAxisGroup        = "AssAxsGrp";
const char *NAM_AssociaAxisSolid        = "AssAxsSol";
const char *NAM_AssociaGroupGroup       = "AssGrpGrp";
const char *NAM_AssociaGroupSolid       = "AssGrpSol";
const char *NAM_CreateAxisOfTranslation = "CrtAxsTrn";
const char *NAM_CreateAxisOfRotation    = "CrtAxsRot";
const char *NAM_ListAxis              = "LstAxs";
const char *NAM_MoveAxis              = "MovAxs";
const char *NAM_RemoveAxis            = "RemAxs";
const char *NAM_RenameAxis            = "RenAxs";
const char *NAM_RotateAxis            = "RotAxs";
const char *NAM_TransformUsingAxis    = "TrfAxs";
const char *NAM_DesassociaAxisGroup   = "DesAxsGrp";
const char *NAM_DesassociaAxisSolid   = "DesAxsSol";
const char *NAM_DesassociaGroupGroup  = "DesGrpGrp";
const char *NAM_DesassociaGroupSolid  = "DesGrpSol";
const char *NAM_CreateGroup           = "CrtGrp";
const char *NAM_CreateGroupSetCurrent = "CrtGrpCur";
const char *NAM_CopyGroup             = "CpyGrp";
const char *NAM_ListGroup             = "LstGrp";
const char *NAM_MoveGroup             = "MovGrp";
const char *NAM_RemoveOneGroup        = "RemOneGrp";
const char *NAM_RemoveGroup           = "RemGrp";
const char *NAM_RenameGroup           = "RenGrp";
const char *NAM_RotateGroup           = "RotGrp";
const char *NAM_SetCurrentGroup       = "SetCurGrp";
const char *NAM_TransferGroup         = "TrnGrp";

const char *NAM_AffineSolid     = "AffSol";
const char *NAM_TransformSolid  = "TrfSol";
const char *NAM_RotateSolid     = "RotSol";
const char *NAM_RotateSolidAxis = "RotSolAxs";
const char *NAM_ScaleSolid      = "SclSol";
const char *NAM_TranslateSolid  = "TrnSol";
const char *NAM_SetDifference   = "SetDif";
const char *NAM_SetIntersection = "SetInt";
const char *NAM_SetUnion        = "SetUni";
const char *NAM_MakeCylinder    = "MakCyl";
const char *NAM_MakeCone        = "MakCon";
const char *NAM_MakePrism       = "MakPrm";
const char *NAM_MakePyramid     = "MakPyr";
const char *NAM_MakeRevolve     = "MakRev";
const char *NAM_MakeSphere      = "MakSph";
const char *NAM_MakeSweep       = "MakSwp";
const char *NAM_MakeTorus       = "MakTor";
const char *NAM_MakeCube        = "MakCub";
const char *NAM_SplitSolid      = "Spl";
const char *NAM_CleanSolid      = "clean";
const char *NAM_Detach          = "detach";
const char *NAM_Glue            = "glue";
const char *NAM_MergeSolid      = "merge";
const char *NAM_ModifyIds       = "modify";
const char *NAM_NewLocation     = "newloc";
const char *NAM_HardRemove      = "hard";
const char *NAM_SoftRemove      = "soft";
const char *NAM_Revert          = "revert";
const char *NAM_RingMove        = "rmove";
const char *NAM_AllRingMove     = "armove";

const char *MEN_PerguntaNovoAntigo    = "%s: antigo novo\n";
const char *MEN_PerguntaId            = "%s: id\n";
const char *MEN_PerguntaNome          = "%s: nome\n";
const char *MEN_CamaraParametros      = "%s: %s Ex Ey Ez Rx Ry Rz scala modo processo pontilhada paralelas\n";
const char *MEN_CoordenadasParametros = "%s: -a comp cor\n-m x/y/z = const comp espacamento cor_eixo cor_malha\n";

const char *MEN_NenhumaCamaraCorrente    = "%s: nenhuma camera corrente!\n";
const char *MEN_CamaraNomeNaoEncontrada  = "%s: camera %s nao foi encontrada!\n";
const char *MEN_CamaraIdNaoEncontrada    = "%s: camera %d nao foi encontrada!\n";
const char *MEN_CamaraParametroIncorreto = "%s: parametros da camera estao incorretos!\n";
const char *MEN_CamaraJaExiste           = "%s: camera %s ja existe!\n";
const char *MEN_CamaraNomeCorrente       = "%s: camera %s e camera corrente!\n";
const char *MEN_CamaraIdCorrente         = "%s: camera %d e camera corrente!\n";
const char *MEN_NenhumaCamaraMonitora    = "%s: nenhuma camera monitora!\n";
const char *MEN_CorInvalida              = "%s: cor invalida!\n";
const char *MEN_ParametrosIncorretos     = "%s: parametros incorretos!\n";
const char *MEN_ElementoNaoEncontrado    = "%s: elemento %s nao foi encontrado!\n";
const char *MEN_NaoAbriuArquivo          = "%s: nao conseguiu abrir arquivo %s!\n";
const char *MEN_NaoEncontrouAresta       = "%s: nao encontrou aresta %d em %d!\n";
const char *MEN_NaoPossuiMemoria         = "%s: nao possui memoria suficiente!\n";
const char *MEN_MSDAbortou               = "%s: programa abortado!\n";
const char *MEN_NaoEncontrouSolido       = "%s: nao encontrou solido %d!\n";
const char *MEN_NaoEncontrouFace         = "%s: nao encontrou face %d em solido %s!\n";
const char *MEN_NaoEncontrouArestaV      = "%s: nao encontrou aresta %d-%d em solido %s!\n";
const char *MEN_NaoEncontrouArestaF      = "%s: nao encontrou aresta %d-%d (%d-%d) em solido %d!\n";
const char *MEN_NaoEncontrouVertice      = "%s: nao encontrou vertice %d em solido %s!\n";
const char *MEN_NaoArestaPonte           = "%s: %d-%d nao e aresta-ponte ou aresta-strut, solido %d!\n";
const char *MEN_NaoVerticeTerminal       = "%s: vertice %d nao e terminal, solido %d!\n";
const char *MEN_ArestaCircular           = "%s: %d-%d e aresta circular, solido %d!\n";
const char *MEN_FaceSemLoop              = "%s: face %d nao pode possuir loop, solido %d!\n";
const char *MEN_FaceSemVertice           = "%s: face %d deve possuir apenas um vertice, solido %d!\n";
const char *MEN_VerticesEmLoopsDistintos = "%s: vertices %d e %d devem estar em loops distintos, solido %d!\n";

const char *MEN_NaoEncontrouAxisNome      = "%s: nao encontrou eixo %s!\n";
const char *MEN_NaoEncontrouGroupNome     = "%s: nao encontrou grupo %s!\n";
const char *MEN_SolidoJaExiste            = "%s: solido %s ja existe!\n";
const char *MEN_NaoEncontrouSolidNome     = "%s: nao encontrou solido %s!\n";
const char *MEN_NaoEncontrouGroupId       = "%s: nao encontrou grupo %d!\n";
const char *MEN_NaoEncontrouAxisId        = "%s: nao encontrou eixo %d!\n";
const char *MEN_PonteirosNulos            = "%s: ponteiros nulos!\n";
const char *MEN_AxisJaExiste              = "%s: eixo %s ja existe!\n";
const char *MEN_GroupJaExiste             = "%s: grupo %s ja existe!\n";
const char *MEN_GrupoCorrenteEliminado    = "%s: grupo corrente pertence ao grupo eliminado!\n";
const char *MEN_NaoPossuiAncestral        = "%s: grupo corrente nao possui ancestral!\n";
const char *MEN_GroupAncestralGroup       = "%s: grupo %d e ancestral do group %d!\n";
const char *MEN_FatorEscalaNulo           = "%s: fator de escala e nulo!\n";
const char *MEN_NaoEncontrouShell         = "%s: nao encontrou shell %d em solido %d!\n";
const char *MEN_MemoriaInvalida           = "%s: memoria %d nao e valida!\n";
const char *MEN_NaoEncontrouTag           = "%s: nao encontrou tag %d em solido %d!\n";
const char *MEN_NumeroDeSegmentosInvalido = "%s: numero de segmentos deve ser maior que 2!\n";
const char *MEN_OperacaoNaoRealizada      = "%s: operacao nao foi realizada!\n";
const char *MEN_NaoEncontrouEdgeNo        = "%s: nao encontrou aresta %d em solido %d!\n";
#else
EXTERN const char *NAM_Area;                        /* = "AnaArea"*/
EXTERN const char *NAM_AreaProjetada;               /* = "AnaAreaProjetada"*/
EXTERN const char *NAM_CentroCarena;                /* = "AnaCentroCarena"*/
EXTERN const char *NAM_CentroGravidade;             /* = "AnaCentroGravidade"*/
EXTERN const char *NAM_DensAbs;                     /* = "AnaDensidadeAbsoluta"*/
EXTERN const char *NAM_DensRel;                     /* = "AnaDensidadeRelativa"*/
EXTERN const char *NAM_Massa;                       /* = "AnaMassa"*/
EXTERN const char *NAM_Inercia;                     /* = "AnaInercia"*/
EXTERN const char *NAM_Volume;                      /* = "AnaVolume"*/

EXTERN const char *NAM_RovCirculo;                  /* = "RovCirculo"*/
EXTERN const char *NAM_RovCone;                     /* = "RovCone"*/
EXTERN const char *NAM_RovCubo;                     /* = "RovCubo"*/
EXTERN const char *NAM_RovEsfera;                   /* = "RovEsfera"*/
EXTERN const char *NAM_RovPerfilI;                  /* = "RovPerfilI"*/
EXTERN const char *NAM_RovPerfilL;                  /* = "RovPerfilL"*/
EXTERN const char *NAM_RovPerfilT;                  /* = "RovPerfilT"*/
EXTERN const char *NAM_RovPiramide;                 /* = "RovPiramide"*/
EXTERN const char *NAM_RovPlaca;                    /* = "RovPlaca"*/
EXTERN const char *NAM_RovPrisma;                   /* = "RovPrisma"*/
EXTERN const char *NAM_RovQuadrado;                 /* = "RovQuadrado"*/
EXTERN const char *NAM_RovRetangulo;                /* = "RovRetangulo"*/
EXTERN const char *NAM_RovTriangulo;                /* = "RovTriangulo"*/
EXTERN const char *NAM_RovTranslate;                /* = "RovTranslate"*/
EXTERN const char *NAM_RovRotate;                   /* = "RovRotate"*/
EXTERN const char *NAM_DimPrinc;                    /* = "RovDimensaoPrincipal"*/
EXTERN const char *NAM_RovOrdena;                   /* = "RovOrdena"*/

EXTERN const char *NAM_AlteraCamaraCorrente;        /* = "AltCamCor*/
EXTERN const char *NAM_AlteraCamara;                /* = "AltCam*/
EXTERN const char *NAM_CopyCamara;                  /* = "CpyCam*/
EXTERN const char *NAM_GetCamaraCorrenteParametros; /* = "GetCamCorPar*/
EXTERN const char *NAM_ListCamara;                  /* = "LstCam*/
EXTERN const char *NAM_CreateCamara;                /* = "CrtCam*/
EXTERN const char *NAM_RemoveCamara;                /* = "DelCam*/
EXTERN const char *NAM_RenameCamara;                /* = "RenCam*/
EXTERN const char *NAM_SetCamaraCorrente;           /* = "SetCamCor*/
EXTERN const char *NAM_TranslateCamaraCorrente;     /* = "TrnCamCor*/

EXTERN const char *NAM_DisplayCoordinates;          /* = "DisCoo*/
EXTERN const char *NAM_SetFrameColor;               /* = "FrmCol*/
EXTERN const char *NAM_SetDefaultColor;             /* = "DftCol*/
EXTERN const char *NAM_SetElementColor;             /* = "ElmCol*/
EXTERN const char *NAM_Display;                     /* = "Disp*/
EXTERN const char *NAM_DisplayFile;                 /* = "DisFle*/
EXTERN const char *NAM_DisplayEdge;                 /* = "DisEdg*/
EXTERN const char *NAM_Monitor;                     /* = "Monit*/

EXTERN const char *NAM_AddEulerOperator;            /* = "AddOp*/
EXTERN const char *NAM_KEF;                         /* = "kef*/
EXTERN const char *NAM_KEF2;                        /* = "kef2*/
EXTERN const char *NAM_KEMR;                        /* = "kemr*/
EXTERN const char *NAM_KEV;                         /* = "kev*/
EXTERN const char *NAM_KEV2;                        /* = "kev2*/
EXTERN const char *NAM_JVKE;                        /* = "jvke*/
EXTERN const char *NAM_JEKV;                        /* = "jekv*/
EXTERN const char *NAM_KFMRH;                       /* = "kfmrh*/
EXTERN const char *NAM_KSFMR;                       /* = "ksfmr*/
EXTERN const char *NAM_KVSF;                        /* = "kvsf*/
EXTERN const char *NAM_MEF;                         /* = "mef*/
EXTERN const char *NAM_MEF2;                        /* = "mef2*/
EXTERN const char *NAM_MEKR;                        /* = "mekr*/
EXTERN const char *NAM_MEKR2;                       /* = "mekr2*/
EXTERN const char *NAM_MEV;                         /* = "mev*/
EXTERN const char *NAM_SEMV;                        /* = "semv*/
EXTERN const char *NAM_SVME;                        /* = "svme*/
EXTERN const char *NAM_SVME2;                       /* = "svme2*/
EXTERN const char *NAM_SVME3;                       /* = "svme3*/
EXTERN const char *NAM_MFKRH;                       /* = "mfkrh*/
EXTERN const char *NAM_MFKRH2;                      /* = "mfkrh2*/
EXTERN const char *NAM_ModifyEulerOp;               /* = "ModEul*/
EXTERN const char *NAM_MSFKR;                       /* = "msfkr*/
EXTERN const char *NAM_MSFKR2;                      /* = "msfkr2*/
EXTERN const char *NAM_MVSF;                        /* = "mvsf*/
EXTERN const char *NAM_PrintEulerOp;                /* = "PrtEul*/
EXTERN const char *NAM_ScanEulerOp;                 /* = "ScnEul*/
EXTERN const char *NAM_ApplyEulerOp;                /* = "AppEul*/
EXTERN const char *NAM_Color;                       /* = "Color*/
EXTERN const char *NAM_Name;                        /* = "Nome"*/
EXTERN const char *NAM_GetHE;                       /* = "GetHe"*/
EXTERN const char *NAM_GetMate;                     /* = "GetMate"*/
EXTERN const char *NAM_GetNext;                     /* = "GetNext"*/
EXTERN const char *NAM_GetPrev;                     /* = "GetPrev"*/
EXTERN const char *NAM_DoMEV;                       /* = "DoMEV"*/
EXTERN const char *NAM_DoMEF;                       /* = "DoMEF"*/
EXTERN const char *NAM_DoNewLoc;                    /* = "DoNewVertexLocation"*/
EXTERN const char *NAM_DoPutTag;                    /* = "DoPutTag"*/
EXTERN const char *NAM_DoEvalEdge;                  /* = "DoEvaluateEdge"*/
EXTERN const char *NAM_AddLPoint;                   /* = "AddPoint"*/
EXTERN const char *NAM_RemLPoint;                   /* = "RemPoint"*/
EXTERN const char *NAM_EvalEdge;                    /* = "EvaluateEdge"*/
EXTERN const char *NAM_KillCTag;                    /* = "KillCurveTag"*/
EXTERN const char *NAM_KillPolyLine;                /* = "KillPolyLine"*/
EXTERN const char *NAM_NewLine;                     /* = "NewLine"*/
EXTERN const char *NAM_NewPolyLine;                 /* = "NewPolyLine"*/
EXTERN const char *NAM_LengthPoly;                  /* = "LengthPoly"*/
EXTERN const char *NAM_PutCTag;                     /* = "PutCurveTag"*/
EXTERN const char *NAM_Round;                       /* = "Round"*/
EXTERN const char *NAM_RoundAll;                    /* = "RoundAll"*/

EXTERN const char *NAM_AssociaAxisElemento;         /* = "AssAxs*/
EXTERN const char *NAM_DesassociaAxisElemento;      /* = "DesAxs*/
EXTERN const char *NAM_CopySolid;                   /* = "CpySol*/
EXTERN const char *NAM_ListFaceAdjacency;           /* = "LstFacAdj*/
EXTERN const char *NAM_AssociaGrupoElemento;        /* = "AssGrp*/
EXTERN const char *NAM_DesassociaGrupoElemento;     /* = "DesGrp*/
EXTERN const char *NAM_LoadSolido;                  /* = "LodSol*/
EXTERN const char *NAM_RenameSolido;                /* = "RenSol*/
EXTERN const char *NAM_SaveSolido;                  /* = "SavSol*/

EXTERN const char *NAM_AssociaAxisGroup;            /* = "AssAxsGrp*/
EXTERN const char *NAM_AssociaAxisSolid;            /* = "AssAxsSol*/
EXTERN const char *NAM_AssociaGroupGroup;           /* = "AssGrpGrp*/
EXTERN const char *NAM_AssociaGroupSolid;           /* = "AssGrpSol*/
EXTERN const char *NAM_CreateAxisOfTranslation;     /* = "CrtAxsTrn*/
EXTERN const char *NAM_CreateAxisOfRotation;        /* = "CrtAxsRot*/
EXTERN const char *NAM_ListAxis;                    /* = "LstAxs*/
EXTERN const char *NAM_MoveAxis;                    /* = "MovAxs*/
EXTERN const char *NAM_RemoveAxis;                  /* = "RemAxs*/
EXTERN const char *NAM_RenameAxis;                  /* = "RenAxs*/
EXTERN const char *NAM_RotateAxis;                  /* = "RotAxs*/
EXTERN const char *NAM_TransformUsingAxis;          /* = "TrfAxs*/
EXTERN const char *NAM_DesassociaAxisGroup;         /* = "DesAxsGrp*/
EXTERN const char *NAM_DesassociaAxisSolid;         /* = "DesAxsSol*/
EXTERN const char *NAM_DesassociaGroupGroup;        /* = "DesGrpGrp*/
EXTERN const char *NAM_DesassociaGroupSolid;        /* = "DesGrpSol*/
EXTERN const char *NAM_CreateGroup;                 /* = "CrtGrp*/
EXTERN const char *NAM_CreateGroupSetCurrent;       /* = "CrtGrpCur*/
EXTERN const char *NAM_CopyGroup;                   /* = "CpyGrp*/
EXTERN const char *NAM_ListGroup;                   /* = "LstGrp*/
EXTERN const char *NAM_MoveGroup;                   /* = "MovGrp*/
EXTERN const char *NAM_RemoveOneGroup;              /* = "RemOneGrp*/
EXTERN const char *NAM_RemoveGroup;                 /* = "RemGrp*/
EXTERN const char *NAM_RenameGroup;                 /* = "RenGrp*/
EXTERN const char *NAM_RotateGroup;                 /* = "RotGrp*/
EXTERN const char *NAM_SetCurrentGroup;             /* = "SetCurGrp*/
EXTERN const char *NAM_TransferGroup;               /* = "TrnGrp*/

EXTERN const char *NAM_AffineSolid;                 /* = "AffSol*/
EXTERN const char *NAM_TransformSolid;              /* = "TrfSol*/
EXTERN const char *NAM_RotateSolid;                 /* = "RotSol*/
EXTERN const char *NAM_RotateSolidAxis;             /* = "RotSolAxs*/
EXTERN const char *NAM_ScaleSolid;                  /* = "SclSol*/
EXTERN const char *NAM_TranslateSolid;              /* = "TrnSol*/

EXTERN const char *NAM_SetDifference;               /* = "SetDif*/
EXTERN const char *NAM_SetIntersection;             /* = "SetInt*/
EXTERN const char *NAM_SetUnion;                    /* = "SetUni*/
EXTERN const char *NAM_MakeCylinder;                /* = "MakCyl*/
EXTERN const char *NAM_MakeCone;                    /* = "MakCon*/
EXTERN const char *NAM_MakePrism;                   /* = "MakPrm*/
EXTERN const char *NAM_MakePyramid;                 /* = "MakPyr*/
EXTERN const char *NAM_MakeRevolve;                 /* = "MakRev*/
EXTERN const char *NAM_MakeSphere;                  /* = "MakSph*/
EXTERN const char *NAM_MakeTorus;                   /* = "MakTor*/
EXTERN const char *NAM_MakeCube;                    /* = "MakCub*/
EXTERN const char *NAM_MakeSweep;                   /* = "MakSwp*/
EXTERN const char *NAM_SplitSolid;                  /* = "Spl*/
EXTERN const char *NAM_CleanSolid;                  /* = "clean*/
EXTERN const char *NAM_Detach;                      /* = "detach*/
EXTERN const char *NAM_Glue;                        /* = "glue*/
EXTERN const char *NAM_MergeSolid;                  /* = "merge*/
EXTERN const char *NAM_ModifyIds;                   /* = "modify*/
EXTERN const char *NAM_NewLocation;                 /* = "newloc*/
EXTERN const char *NAM_HardRemove;                  /* = "hard*/
EXTERN const char *NAM_SoftRemove;                  /* = "soft*/
EXTERN const char *NAM_Revert;                      /* = "revert*/
EXTERN const char *NAM_RingMove;                    /* = "rmove*/
EXTERN const char *NAM_AllRingMove;                 /* = "armove*/

EXTERN const char *MEN_PerguntaNovoAntigo;          /* = "%s: antigo novo\n*/
EXTERN const char *MEN_PerguntaId;                  /* = "%s: id\n*/
EXTERN const char *MEN_PerguntaNome;                /* = "%s: nome\n*/
EXTERN const char *MEN_CamaraParametros;            /* = "%s: %s Ex Ey Ez Rx Ry Rz scala modo processo pontilhada paralelas\n*/
EXTERN const char *MEN_CoordenadasParametros;       /* = "%s: -a comp cor\n-m x/y/z ; /* = const comp espacamento cor_eixo cor_malha\n*/

EXTERN const char *MEN_NenhumaCamaraCorrente;       /* = "%s: nenhuma camera corrente!\n*/
EXTERN const char *MEN_CamaraNomeNaoEncontrada;     /* = "%s: camera %s nao foi encontrada!\n*/
EXTERN const char *MEN_CamaraIdNaoEncontrada;       /* = "%s: camera %d nao foi encontrada!\n*/
EXTERN const char *MEN_CamaraParametroIncorreto;    /* = "%s: parametros da camera estao incorretos!\n*/
EXTERN const char *MEN_CamaraJaExiste;              /* = "%s: camera %s ja existe!\n*/
EXTERN const char *MEN_CamaraNomeCorrente;          /* = "%s: camera %s e camera corrente!\n*/
EXTERN const char *MEN_CamaraIdCorrente;            /* = "%s: camera %d e camera corrente!\n*/
EXTERN const char *MEN_NenhumaCamaraMonitora;       /* = "%s: nenhuma camera monitora!\n*/
EXTERN const char *MEN_CorInvalida;                 /* = "%s: cor invalida!\n*/
EXTERN const char *MEN_ParametrosIncorretos;        /* = "%s: parametros incorretos!\n*/
EXTERN const char *MEN_ElementoNaoEncontrado;       /* = "%s: elemento %s nao foi encontrado!\n*/
EXTERN const char *MEN_NaoAbriuArquivo;             /* = "%s: nao conseguiu abrir arquivo %s!\n*/
EXTERN const char *MEN_NaoEncontrouAresta;          /* = "%s: nao encontrou aresta %d em %d!\n*/
EXTERN const char *MEN_NaoPossuiMemoria;            /* = "%s: nao possui memoria!\n*/
EXTERN const char *MEN_MSDAbortou;                  /* = "%s: programa abortado!\n*/
EXTERN const char *MEN_NaoEncontrouSolido;          /* = "%s: nao encontrou solido %d!\n*/
EXTERN const char *MEN_NaoEncontrouFace;            /* = "%s: nao encontrou face %d em solido %d!\n*/
EXTERN const char *MEN_NaoEncontrouArestaV;         /* = "%s: nao encontrou aresta %d-%d em solido %s!\n*/
EXTERN const char *MEN_NaoEncontrouArestaF;         /* = "%s: nao encontrou aresta %d-%d (%d-%d) em solido %d!\n*/
EXTERN const char *MEN_NaoEncontrouVertice;         /* = "%s: nao encontrou vertice %d em solido %s!\n*/
EXTERN const char *MEN_NaoArestaPonte;              /* = "%s: %d-%d nao e aresta-ponte ou aresta-strut, solido %d!\n*/
EXTERN const char *MEN_NaoVerticeTerminal;          /* = "%s: vertice %d nao e terminal, solido %d!\n*/
EXTERN const char *MEN_ArestaCircular;              /* = "%s: %d-%d e aresta circular, solido %d!\n*/
EXTERN const char *MEN_FaceSemLoop;                 /* = "%s: face %d nao pode possuir loop, solido %d!\n*/
EXTERN const char *MEN_FaceSemVertice;              /* = "%s: face %d deve possuir apenas um vertice, solido %d!\n*/
EXTERN const char *MEN_VerticesEmLoopsDistintos;    /* = "%s: vertices %d e %d devem estar em loops distintos, solido %d!\n*/

EXTERN const char *MEN_NaoEncontrouAxisNome;        /* = "%s: nao encontrou axis %s!\n*/
EXTERN const char *MEN_NaoEncontrouGroupNome;       /* = "%s: nao encontrou grupo %s!\n*/
EXTERN const char *MEN_SolidoJaExiste;              /* = "%s: solido %s ja existe!\n*/
EXTERN const char *MEN_NaoEncontrouSolidNome;       /* = "%s: nao encontrou solido %s!\n*/
EXTERN const char *MEN_NaoEncontrouGroupId;         /* = "%s: nao encontrou grupo %d!\n*/
EXTERN const char *MEN_NaoEncontrouAxisId;          /* = "%s: nao encontrou axis %d!\n*/
EXTERN const char *MEN_PonteirosNulos;              /* = "%s: ponteiros nulos!\n*/
EXTERN const char *MEN_AxisJaExiste;                /* = "%s: axis %s ja existe!\n*/
EXTERN const char *MEN_GroupJaExiste;               /* = "%s: grupo %s ja existe!\n*/
EXTERN const char *MEN_GrupoCorrenteEliminado;      /* = "%s: grupo corrente pertence ao grupo eliminado!\n*/
EXTERN const char *MEN_NaoPossuiAncestral;          /* = "%s: grupo corrente nao possui ancestral!\n*/
EXTERN const char *MEN_GroupAncestralGroup;         /* = "%s: grupo %d e ancestral do group %d!\n*/
EXTERN const char *MEN_FatorEscalaNulo;             /* = "%s: fator de escala e nulo!\n*/
EXTERN const char *MEN_NaoEncontrouShell;           /* = "%s: nao encontrou shell %d em solido %d!\n*/
EXTERN const char *MEN_MemoriaInvalida;             /* = "%s: memoria %d nao e valida!\n"*/
EXTERN const char *MEN_NaoEncontrouTag;             /* = "%s: nao encontrou tag %d em solido %d!\n"*/
EXTERN const char *MEN_NumeroDeSegmentosInvalido;   /* = "%s: numero de segmentos deve ser maior que 2!\n"*/
EXTERN const char *MEN_OperacaoNaoRealizada;        /* = "%s: operacao nao foi realizada!\n"*/
EXTERN const char *MEN_NaoEncontrouEdgeNo;          /* = "%s: nao encontrou aresta %d em solido %d!\n"*/

#endif
