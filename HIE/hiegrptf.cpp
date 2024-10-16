/* 
  PROJETO USPDesigner
  MODULO: HIE (Estrutura Hierarquica)
  Copyright (C) 1989 a 2008, Marcos Tsuzuki, All rights reserved
  Universidade de Sao Paulo, EPUSP-PMR

   NOME DO ARQUIVO: hiegrptf.cpp
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
#include <string.h>
#include "mensagem.h"
#include "memvirtu.h"
#include "lowparam.h"
#include "lowmacro.h"
#include "lowsolid.h"
#include "vectorop.h"
#include "mancommd.h"
#include "hiegroup.h"

#ifdef __Extended_Version
void MSD_execNameTransferGroup(void)
{
   char gname1[30], gname2[30];

   while (2 != sscanf(restbuf, "%s %s", gname1, gname2))
   {
      printf("Transfer Group: parent child\n");
      if (!lineins("? "))
      {
         return;
      }
   }
   MSD_highNameTransferGroup(gname1, gname2);
}

#endif

int MSD_highNameTransferGroup(const char *name1, const char *name2)
{
   Id gn1, gn2;

   if ((gn1 = MSD_getGroupIdFromName(name1)) == -1)
   {
      fprintf(stderr, MEN_NaoEncontrouGroupNome, NAM_TransferGroup, name1);
      return(ERROR);
   }
   if ((gn2 = MSD_getGroupIdFromName(name2)) == -1)
   {
      fprintf(stderr, MEN_NaoEncontrouGroupNome, NAM_TransferGroup, name2);
      return(ERROR);
   }
   return(MSD_highTransferGroup(gn1, gn2));
}

#ifdef __Extended_Version
void MSD_execTransferGroup(void)
{
   int gn1, gn2;

   while (2 != sscanf(restbuf, "%d %d", &gn1, &gn2))
   {
      printf("Transfer Group: gn1 gn2\n");
      if (!lineins("? "))
      {
         return;
      }
   }
   MSD_highTransferGroup(gn1, gn2);
}

#endif

int MSD_highTransferGroup(int gn1, int gn2)
{
   GPTYPE gptr1;
   GPTYPE gptr2;

   if ((gptr1 = MSD_getGroup(gn1)) == GNIL)
   {
      fprintf(stderr, MEN_NaoEncontrouGroupId, NAM_TransferGroup, gn1);
      return(ERROR);
   }
   if ((gptr2 = MSD_getGroup(gn2)) == GNIL)
   {
      fprintf(stderr, MEN_NaoEncontrouGroupId, NAM_TransferGroup, gn2);
      return(ERROR);
   }
   if (MSD_lowIsAncestorGroup(gptr2, gptr1))
   {
      fprintf(stderr, MEN_GroupAncestralGroup, NAM_TransferGroup, gn1, gn2);
      return(ERROR);
   }
   return(MSD_lowAssociaGroupGroup(gptr2, gptr1));
}
