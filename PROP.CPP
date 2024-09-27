#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mensagem.h"
#include "memvirtu.h"
#include "lowparam.h"
#include "lowmacro.h"
#include "lowsolid.h"
#include "eulerops.h"
#include "vectorop.h"
#include "genfunc_.h"
#include "analise_.h"
#include "shpshape.h"
#include "prop.h"
#include "mancommd.h"
#include <cstring>

typedef struct {
    float x;
    float y;
}point;

real MSD_highNamePropriedadeArea(const char *name);
real MSD_highPropriedadeArea(Id sn);
double MSD_lowPropriedadeArea(SPTYPE s);
double MSD_lowPropriedadeAreaFace(FPTYPE f);
double MSD_lowPropriedadeAreaLaco(LPTYPE l);
point* MSD_SA(point* p);

void MSD_execManipulatePropriedade(void)
{
    int ip ;
    char onam[30] ;
    float area, volume, x1, x2, y1, y2, z1, z2, th, d1, d2, d3, d4, d5, d6, d7;
    point p, *p_out = NULL;
                                                   // defini??o das vari?veis locais

    for (ip = 0 ; ip == 0 ; ) {
        switch(optin()) {                 // recupera as o??es do comando

            // - Comando calcula a area - recupera o nome do solido
            case 's':
                p_out = MSD_SA(&p);
                ip = 1;
                printf("SA = (%f, %f)\n", p_out->x, p_out->y);
                break ;

            // - Comando calcula a area - recupera o nome do solido
            case 'a':
                if (1 == sscanf(restbuf, "%s", onam)) {
                    area = MSD_highNamePropriedadeArea(onam) ;
                    ip = 1 ;
                    printf("area = %f\n", - area);
                }
                break ;

            // - Comando calcula o volume - recupera o nome do solido
            case 'v':
                if (1 == sscanf(restbuf, "%s", onam)) {
//                    volume = MSD_highNamePropriedadeVolume(onam) ;
                    ip = 1 ;
                    printf("volume = %f\n", volume);
                }
                break ;

             // - Comando que calcula a rota??o em rela??o a um eixo
            case 'r':
                if (8 == sscanf(restbuf, "%s %f %f %f %f %f %f %f", 
                                           onam, &x1, &y1, &z1, &z2, &y2, &z2, &th)) {
                //    MSD_highNamePropriedadeRotaciona(onam, x1, y1, z1, x2, y2, z2, th) ;
                    ip = 1 ;
                }
                break ;

            // - Comando para criar o primitivo barra L
            case 'l':
                if (6 == sscanf(restbuf, "%s %f %f %f %f %f", 
                                         onam, &d1, &d2, &d3, &d4, &d5)) {
                //    MSD_ highCreatePrimitivoL(onam, d1, d2, d3, d4, d5) ;
                    ip = 1 ;
                }
                break ;

            // - Outros comandos

        }
        if (ip == 0) {
            printf("-avrs nome do s?lido\n") ;
            if (!lineins("? "))
                return ;
        }
    }
}

real MSD_highNamePropriedadeArea(const char *name)
{
    int sn ;                       // identificador do s?lido

    if ((sn = MSD_getSolidIdFromName(name)) == -1) {
        fprintf(stderr, "area: nao encontrou o s?lido %s!\n", name) ;
        return(ERROR) ;
    }
    return(MSD_highArea(sn)) ;
}

real MSD_highPropriedadeArea(Id sn)
{
    SPTYPE s ;                     // ponteiro para o s?lido

    if ((s = MSD_getSolid(sn)) == SNIL) {
        fprintf(stderr, "area: nao encontrou o s?lido %d!\n", sn) ;
        return(0.0) ;
    }
    return(MSD_lowPropriedadeArea(s)) ;
}

double MSD_lowPropriedadeArea(SPTYPE s)
{
    DPTYPE d;
    FPTYPE f;
    double area = 0;

    for (d = SolSShells(s) ; d != DNIL ; d = SheNextD(d))
        for (f = SheSFaces(d) ; f != FNIL ; f = FacNextF(f))
            area += MSD_lowPropriedadeAreaFace(f);
            MSD_lowSetNormal(s, TRUE) ;
MSD_lowSetEdgeAngle(s) ;
MSD_lowSetInfo(s) ;
    return(area);
}

double MSD_lowPropriedadeAreaFace(FPTYPE f)
{
    LPTYPE l;
    double area = 0;

    area = MSD_lowPropriedadeAreaLaco(FacFLOut(f));
    for (l = FacFLoops(f) ; l != LNIL ; l = LooNextL(l))
        if (l != FacFLOut(f))
            area -= MSD_lowPropriedadeAreaLaco(l);
    return(area);
}

/*** Calculo da area do laco ***/
double MSD_lowPropriedadeAreaLaco(LPTYPE l)
{
    HPTYPE he ;
    VPTYPE v1 ;
    vector aa, bb, cc, dd, vv1 ;

    veczer(dd) ;
    he = LooLEdg(l) ;
    v1 = HalVtx(he) ;
    he = HalNxt(he) ;
    do {
        veccopy(vv1, VerVCoord(v1)) ;
        vecminus(aa, VerVCoord(HalVtx(he)), vv1) ;
        vecminus(bb, VerVCoord(HalVtx(HalNxt(he))), vv1) ;
        cross(cc, aa, bb) ;
        vecplus(dd, dd, cc) ;
    } while ((he = HalNxt(he)) != LooLEdg(l)) ;
    return(-0.5 * dot(FacFeq(LooLFace(l)), dd)) ;
}

double f(double x, double y)
{
	//return y*y*(2+sin(x));
    return (x-2)*(x-2)+(100*y+1)*(100*y+1);
    //  if (x < 0) {
    //     x = x*(-1);
    //  }
    //  return y*y + x; //y^2 + mod(x)
//   if (y > -0.5 && y < 0.5)
//     return y*y - 1000.0+2;
//   return y * y + 5.0 * y + 6.0+2;
}


point* MSD_SA(point *pi)
{
    double s0 = -5.0;
    int n = 2;       // number of variables
    int p = n * 20;  // m?ximo de itera??es local (perturba??es da solu??o atual)
    int l = n * 10;  // N?mero m?ximo de sucessos por itera??o
    double alfa = 0.98;
    double T0 = 5.0;
    double deltay = 5.0;

    //double sx0 = s0;
    //double sy0 = s0;
    double T = T0;
    int j = 1; // contador global
    int k = 1; // contador de solu??es aceitas
    //int c = 1; // crystallization factor
    srand(time(NULL));
    double x[2];
    double s[2];
    int c[2];
    int index = 0;
    // Inicializa vetores 
    c[0] = c[1] = 1;
	s[0] = s[1] = s0;
	x[0] = x[1] = s0;
    // loop principal
    while (k != 0) {
        int i = 1; // contador local
		
        k = 0;
        while (k < l && i < p) {
        	if (2.0 * rand()/(double)RAND_MAX - 1.0 > 0) {
        		index = 1;
			} else {
				index = 0;
			}
			//printf("index %d\n", index);
            double dx = 0.0;
            for (int kk = 0 ; kk < c[index] ; kk ++) {
                dx += 2.0 * rand()/(double)RAND_MAX - 1.0;
            }
            dx = dx / (double)c[index] * deltay;
            // Salva valores anteriores
            double xt[2];
            memcpy(&xt, &x, sizeof(x));
            xt[index] = xt[index] + dx;
            

            double delta = f(xt[0], xt[1]) - f(x[0], x[1]);

            if (delta < 0 || exp(-delta/T) > rand()/(double)RAND_MAX) {
                memcpy(&x, xt, sizeof(xt));
                k ++;
                if (c[index] > 1) c[index] --;
            }
            else
                if (c[index] < 80) c[index] ++;
            i ++;
        }
        
        T *= alfa;
    }
    pi->x = x[0];
    pi->y = x[1];

    return pi;
}

