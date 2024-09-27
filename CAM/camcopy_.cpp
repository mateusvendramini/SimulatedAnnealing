/* 
  PROJETO USPDesigner
  MODULO: CAM (Camera Manipulation)
  Copyright (C) 1989 a 2008, Marcos Tsuzuki, All rights reserved
  Universidade de Sao Paulo, EPUSP-PMR

   NOME DO ARQUIVO: camcopy_.cpp
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
#include "mancommd.h"
#include "disdispl.h"

#ifdef __Extended_Version
void MSD_execNameCopyCamera(void)
{
   char name1[15], name2[15];

   while (2 != sscanf(restbuf, "%s %s", name1, name2))
   {
      printf(MEN_PerguntaNovoAntigo, NAM_CopyCamara);
      if (!lineins("? "))
      {
         return;
      }
   }
   MSD_highNameCopyCamera(name1, name2);
}

#endif

int MSD_highNameCopyCamera(const char *name1, const char *name2)
{
   CTYPE *cptr;
   Id    cn1, cn2;

   if ((cn1 = MSD_getCameraIdFromName(name1)) == -1)
   {
      fprintf(stderr, MEN_CamaraNomeNaoEncontrada,
              NAM_CopyCamara, name1);
      return(ERROR);
   }
   if (MSD_getCameraIdFromName(name2) != -1)
   {
      fprintf(stderr, MEN_CamaraJaExiste,
              NAM_CopyCamara, name2);
      return(ERROR);
   }
   if ((cn2 = MSD_highCopyCamera(cn1)) != -1)
   {
      cptr = MSD_getCamera(cn2);
      strcpy(cptr->cname, name2);
      return(SUCCESS);
   }
   return(ERROR);
}

#ifdef __Extended_Version
void MSD_execCopyCamera(void)
{
   int i1;

   while (2 != sscanf(restbuf, "%d", &i1))
   {
      printf(MEN_PerguntaId, NAM_CopyCamara);
      if (!lineins("? "))
      {
         return;
      }
   }
   printf("Id = %d\n", MSD_highCopyCamera(i1));
}

#endif

int MSD_highCopyCamera(int cn)
{
   CTYPE *cptr;
   Id    cn1;

   cn1 = MSD_getMaxCameraId();
   if ((cptr = MSD_getCamera(cn)) == (CTYPE *)NIL)
   {
      fprintf(stderr, MEN_CamaraIdNaoEncontrada,
              NAM_CopyCamara, cn);
      return(ERROR);
   }
   return(MSD_lowCopyCamera(cptr, cn1));
}

int MSD_lowCopyCamera(CTYPE *cptr, Id cn)
{
   real Ex, Ey, Ez, Rx, Ry, Rz, ampl;
   int  mode, elim, hash, edge;

   Ex   = cptr->eye[0];
   Ey   = cptr->eye[1];
   Ez   = cptr->eye[2];
   Rx   = cptr->ref[0];
   Ry   = cptr->ref[1];
   Rz   = cptr->ref[2];
   ampl = cptr->scale;
   mode = cptr->mode;
   hash = cptr->dash;
   elim = cptr->hid;
   edge = cptr->smooth;
   return(MSD_lowCreateCamera(cn, Ex, Ey, Ez, Rx, Ry, Rz, ampl,
                              mode, elim, hash, edge) != (CTYPE *)NIL);
}
