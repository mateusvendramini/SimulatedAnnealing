/* 
  PROJETO USPDesigner
  MODULO: ROV (Criacao de Formas Especificas)
  Copyright (C) 1989 a 2008, Marcos Tsuzuki, All rights reserved
  Universidade de Sao Paulo, EPUSP-PMR

   NOME DO ARQUIVO: rovtrian.cpp
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
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "mensagem.h"
#include "memvirtu.h"
#include "lowparam.h"
#include "lowsolid.h"
#include "eulerops.h"
#include "vectorop.h"
#include "mancommd.h"
#include "shpshape.h"
#include "basrov__.h"

void MSD_highNameMakeTriangulo(const char *name, real a, real b, real c, real h);

void MSD_execNameMakeTriangulo(void)
{
   char  name[30];
   float a, b, c, h;

   while (5 != sscanf(restbuf, "%s %f %f %d", name, &a, &b, &c, &h))
   {
      printf("ROV.triangulo nome a b c h\n");
      if (!lineins("? "))
      {
         return;
      }
   }
   MSD_highNameMakeTriangulo(name, a, b, c, h);
}

void MSD_highNameMakeTriangulo(const char *name, real a, real b, real c, real h)
{
   SPTYPE        optr;
   SPTYPE        pptr;
   real          aux, x, y;
   int           flag = 1, GOld;
   Id            sn, face;
   vector        normal;
   static vector vec = { 0.0, 0.0, 1.0, 0.0 };

   if (MSD_getSolidIdFromName(name) != -1)
   {
      fprintf(stderr, MEN_SolidoJaExiste, NAM_RovTriangulo, name);
      return;
   }

   x = (b * b + a * a - c * c) * 0.5 / a;
   if ((aux = b * b - x * x) < 0)
   {
      fprintf(stderr, MEN_SolidoJaExiste, NAM_MakeCube, name);
      return;
   }
   y = sqrt(aux);

   GOld         = Gdoinversion;
   Gdoinversion = FALSE;
   sn           = MSD_getMaxSolidId();
   if ((optr = MSD_lowMVSF(sn, 1, 1, 1, 0.0, 0.0, 0.0)) == SNIL)
   {
      flag = 0;
   }
   if (MSD_highMEV(sn, 1, 1, 2, a, 0.0, 0.0) == ERROR)
   {
      flag = 0;
   }
   if (MSD_highMEV(sn, 1, 2, 3, x, y, 0.0) == ERROR)
   {
      flag = 0;
   }
   if (MSD_highMEF(sn, 1, 3, 1, 2) == ERROR)
   {
      flag = 0;
   }
   if (flag == 1)
   {
      MSD_lowFaceEq(FacFLOut(MSD_getFace(optr, 1)), normal);
      face = dot(normal, vec) > 0.0 ? 1 : 2;
      if (MSD_lowMakeSweep(MSD_getFace(optr, face), 0.0, 0.0, h) == ERROR)
      {
         flag = 0;
      }
      if (flag == 1)
      {
         MSD_lowSetNormal(optr, TRUE);
         MSD_lowSetEdgeAngle(optr);
         MSD_lowSetInfo(optr);
      }
   }
   if (flag == 0)
   {
      MSD_lowHardRemove(optr);
   }
   if (flag == 1)
   {
      MSD_lowAddEulerOp(optr, HARDREM, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0);
   }
   Gdoinversion = GOld;

   if (flag == 1)
   {
      strcpy(SolName(optr), name);
      SolType(optr)      = SOLIDO_TIPO_BARRA;
      SolGeometria(optr) = BARRA_GEOM_TRIANGULO;
      SolFronteira(optr) = FRONTEIRA_CV;
      SolParam1(optr)    = a;
      SolParam2(optr)    = b;
      SolParam3(optr)    = c;
      SolParam4(optr)    = h;
      makevec(SolPrincDir(optr), 0.0, 0.0, 1.0, 0.0);
   }

   if (flag == 0)
   {
      return;
   }
   GOld         = Gdoinversion;
   Gdoinversion = FALSE;
   sn           = MSD_getMaxSolidId();
   if ((pptr = MSD_lowMVSF(sn, 1, 1, 1, 0.0, 0.0, 0.0)) == SNIL)
   {
      flag = 0;
   }
   if (MSD_highMEV(sn, 1, 1, 2, a, 0.0, 0.0) == ERROR)
   {
      flag = 0;
   }
   if (MSD_highMEV(sn, 1, 2, 3, x, y, 0.0) == ERROR)
   {
      flag = 0;
   }
   if (MSD_highMEF(sn, 1, 3, 1, 2) == ERROR)
   {
      flag = 0;
   }
   if (flag == 1)
   {
      MSD_lowSetNormal(pptr, TRUE);
      MSD_lowSetEdgeAngle(pptr);
      MSD_lowSetInfo(pptr);
      strcpy(SolName(pptr), "PerTriangular");
      SolPerfil(optr) = sn;
   }
   if (flag == 0)
   {
      MSD_lowHardRemove(pptr);
   }
   if (flag == 1)
   {
      MSD_lowAddEulerOp(pptr, HARDREM, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0);
   }
   Gdoinversion = GOld;
}
