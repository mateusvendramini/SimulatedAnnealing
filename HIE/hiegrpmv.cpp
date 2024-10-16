/* 
  PROJETO USPDesigner
  MODULO: HIE (Estrutura Hierarquica)
  Copyright (C) 1989 a 2008, Marcos Tsuzuki, All rights reserved
  Universidade de Sao Paulo, EPUSP-PMR

   NOME DO ARQUIVO: hiegrpmv.cpp
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
#include "mensagem.h"
#include "memvirtu.h"
#include "lowparam.h"
#include "lowmacro.h"
#include "lowsolid.h"
#include "vectorop.h"
#include "mancommd.h"
#include "disdispl.h"
#include "genfunc_.h"
#include "hiegroup.h"

#ifdef __Extended_Version
void MSD_execNameMoveGroup(void)
{
   char  gname[30];
   float x, y, z;

   while (4 != sscanf(restbuf, "%s %f %f %f", gname, &x, &y, &z))
   {
      printf("MoveGroup: Group dx dy dz\n");
      if (!lineins("? "))
      {
         return;
      }
   }
   MSD_highNameMoveGroup(gname, x, y, z);
}

#endif

int MSD_highNameMoveGroup(const char *name, real x, real y, real z)
{
   int gn;

   if ((gn = MSD_getGroupIdFromName(name)) == -1)
   {
      fprintf(stderr, MEN_NaoEncontrouGroupNome, NAM_MoveGroup, name);
      return(ERROR);
   }
   return(MSD_highMoveGroup(gn, x, y, z));
}

#ifdef __Extended_Version
void MSD_execMoveGroup(void)
{
   float x, y, z;
   int   gn;

   while (4 != sscanf(restbuf, "%d %f %f %f", &gn, &x, &y, &z))
   {
      printf("MoveGroup: gn dx dy dz\n");
      if (!lineins("? "))
      {
         return;
      }
   }
   MSD_highMoveGroup(gn, x, y, z);
}

#endif

int MSD_highMoveGroup(int gn, real x, real y, real z)
{
   GPTYPE gptr;
   vector vec;

   if ((gptr = MSD_getGroup(gn)) == GNIL)
   {
      fprintf(stderr, MEN_NaoEncontrouGroupId, NAM_MoveGroup, gn);
      return(ERROR);
   }
   makevec(vec, x, y, z, 1.0);
   return(MSD_lowMoveGroup(gptr, vec));
}

int MSD_lowMoveGroup(GPTYPE gptr, vector disp)
{
   SPTYPE optr;
   APTYPE aptr;

   for (AllSolids(optr))
   {
      if (MSD_lowIsAncestorGroup(gptr, SolGroup(optr)))
      {
         MSD_lowTranslate(optr, disp[0], disp[1], disp[2]);
      }
   }

   for (AllAxis(aptr))
   {
      if (MSD_lowIsAncestorGroup(gptr, MSD_getGroupAxis(aptr)))
      {
         MSD_lowMoveAxis(aptr, disp);
      }
   }

   return(SUCCESS);
}
