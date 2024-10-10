#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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

real MSD_highNamePropriedadeArea(const char *name);
real MSD_highPropriedadeArea(Id sn);
double MSD_lowPropriedadeArea(SPTYPE s);
double MSD_lowPropriedadeAreaFace(FPTYPE f);
double MSD_lowPropriedadeAreaLaco(LPTYPE l);
real MSD_highNamePropriedadeVolume(const char *name);
real MSD_highPropriedadeVolume(Id sn);
double MSD_lowPropriedadeVolume(SPTYPE s);
double MSD_lowPropriedadeVolumeFace(FPTYPE f, vector PntMedio);
double MSD_lowPropriedadeVolumeLaco(LPTYPE l, vector PntMedio);
float MSD_SA(void);

void MSD_execManipulatePropriedade(void)
{
    int ip ;
    char onam[30] ;
    vector center ;
    float area, volume, a, b, c, d, x1, x2, y1, y2, z1, z2, th, d1, d2, d3, d4, d5, d6, d7;
                                                   // defini??o das vari?veis locais

    for (ip = 0 ; ip == 0 ; ) {
        switch(optin()) {                 // recupera as o??es do comando

            // - Comando calcula a area - recupera o nome do solido
            case 'a':
                if (1 == sscanf(restbuf, "%s", onam)) {
                    area = MSD_highNamePropriedadeArea(onam) ;
                    ip = 1 ;
                    printf("area = %f - passou pjj or aqui\n", - area);
                }
                break ;

            // - Comando calcula o volume - recupera o nome do solido
            case 'v':
                if (1 == sscanf(restbuf, "%s", onam)) {
                    volume = MSD_highNamePropriedadeVolume(onam) ;
                    ip = 1 ;
                    printf("volume 27.03.2020 = %f\n", volume);
                }
                break ;

            // - Comando calcula o cento de gravidade - recupera o nome do solido
            case 'c':
                if (1 == sscanf(restbuf, "%s", onam)) {
                    // MSD_highNamePropriedadeCentro(onam) ;
                    ip = 1 ;
                    printf("volume 27.03.2020 = %f\n", volume);
                }
                break ;

            // - Comando que calcula o espelhamento em rela??o a um plano
            case 'e':
                if (8 == sscanf(restbuf, "%s %f %f %f %f", 
                                           onam, &a, &b, &c, &d)) {
                //    MSD_highNamePropriedadeEspelha(onam, a, b, c, d) ;
                    ip = 1 ;
                }
                break ;

            // - Comando para criar o primitivo barra L
            case 'u':
                if (6 == sscanf(restbuf, "%s %f %f %f %f %f %f", 
                                         onam, &d1, &d2, &d3, &d4, &d5, &d6)) {
                //    MSD_ highCreatePrimitivoU(onam, d1, d2, d3, d4, d5, d6) ;
                    ip = 1 ;
                }
                break ;

            case 's':
                MSD_SA() ;
                ip = 1;
                break ;

            // - Outros comandos

        }
        if (ip == 0) {
            printf("-avrs nome do solido\n") ;
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

real MSD_highNamePropriedadeVolume(const char *name)
{
    int sn ;                       // identificador do s?lido

    if ((sn = MSD_getSolidIdFromName(name)) == -1) {
        fprintf(stderr, "volume: nao encontrou o s?lido %s!\n", name) ;
        return(ERROR) ;
    }
    return(MSD_highVolume(sn)) ; 
}

real MSD_highPropriedadeVolume(Id sn)
{
    SPTYPE s ;                     // ponteiro para o s?lido

    if ((s = MSD_getSolid(sn)) == SNIL) {
        fprintf(stderr, "volume: nao encontrou o s?lido %d!\n", sn) ;
        return(0.0) ;
    }
    return(MSD_lowPropriedadeVolume(s)) ;
}

double MSD_lowPropriedadeVolume(SPTYPE s)
{
    DPTYPE d;
    FPTYPE f;
    VPTYPE v;
    double volume = 0;
    int contador_vertices = 0;
    vector ponto_medio;
    
    // Calculo do Ponto Medio
    veczer(ponto_medio);
    for (d = SolSShells(s) ; d != DNIL ; d = SheNextD(d))
        for (v = SheSVerts(d) ; v != VNIL; v = VerNextV(v)) {
            contador_vertices ++;
            vecplus(ponto_medio, ponto_medio, VerVCoord(v));
		}
	for (int i = 0 ; i < 3 ; i ++)
	    ponto_medio[i] = ponto_medio[i] / (float) contador_vertices;

    for (d = SolSShells(s) ; d != DNIL ; d = SheNextD(d))
        for (f = SheSFaces(d) ; f != FNIL ; f = FacNextF(f))
            volume += MSD_lowPropriedadeVolumeFace(f, ponto_medio);
    
	MSD_lowSetNormal(s, TRUE) ;
    MSD_lowSetEdgeAngle(s) ;
    MSD_lowSetInfo(s) ;
    return(volume);
}

double MSD_lowPropriedadeVolumeFace(FPTYPE f, vector PntMedio)
{
    LPTYPE l;
    double volume = 0;

/*    area = MSD_lowPropriedadeAreaLaco(FacFLOut(f)); */
    for (l = FacFLoops(f) ; l != LNIL ; l = LooNextL(l))
/*        if (l != FacFLOut(f)) */
            volume += MSD_lowPropriedadeVolumeLaco(l, PntMedio);
    return(volume);
}

/*** Calculo da area do laco ***/
double MSD_lowPropriedadeVolumeLaco(LPTYPE l, vector PntMedio)
{
    HPTYPE he ;
    VPTYPE v1 ;
    vector aa, bb, cc, vv1 ;
    double dd = 0;

/*    veczer(dd) ; */
    he = LooLEdg(l) ;
    v1 = HalVtx(he) ;
    he = HalNxt(he) ;
    do {
        veccopy(vv1, VerVCoord(v1)) ;
        vecminus(vv1, vv1, PntMedio);
        veccopy(aa, VerVCoord(HalVtx(he))) ;
        vecminus(aa, aa, PntMedio);
        veccopy(bb, VerVCoord(HalVtx(HalNxt(he)))) ;
        vecminus(bb, bb, PntMedio);
        cross(cc, aa, bb) ;
        dd += dot(vv1, cc) ;
    } while ((he = HalNxt(he)) != LooLEdg(l)) ;
    return(dd / 6.0) ;
}

double hh(double *y)
{
  if (y[0] > -0.5 && y[0] < 0.5)
    return y[0]*y[0] - 1000.0;
  return y[0] * y[0] + 5.0 * y[0] + 6.0;
}

double g(double y)
{
	return (y - 3)*y*y*y*(y - 6)*(y - 6)*(y - 6)*(y - 6);
}

double h(double y)
{
	return y*y*y*y - 9.0*y*y*y + 10.0*y*y + 4.0*y + 12.0;
}

double f(double *x)
{
	return x[0]*x[0] + x[1]*x[1];//return 100.0*sqrt(fabs(x[1] - 0.01*x[0]*x[0])) + 0.01*fabs(x[0] + 10.0);
}

#define dim 2

// --> a function with two variables, we are going to have two crystallization factors
float MSD_SA(void)
{
	double fmax, fmin, fmed;
	double ffmin;
    double smin[dim];
    double min[dim];
    min[0] = -15.0; min[1] = -3.0;
    double max[dim];
    max[0] = 5.0;  max[1] =  3.0;
    double s0[dim];
	//s0[0] = (max[0] - min[0]) * 0.5 + min[0];
	//s0[1] = (max[1] - min[1]) * 0.5 + min[1];
    
    int n = dim;           // --> number of variables
    int p = n * 20;        // --> Maximum number of candidate evaluation for thermal equilibrium
    int l = n * 40;        // --> Maximum number of accepted solution for thermal equilibrium
    double alfa = 0.99;    // --> Temperature decrease
    double T0 = 50.0;      // --> Initial termperature
    double delta[dim];     // --> Maximum skip - maximum value to change the parameter
    //delta[0] = (max[0] - min[0]) * 0.25;
    //delta[1] = (max[1] - min[1]) * 0.25;

    double s[dim];
	//s[0] = s0[0]; 
	//s[1] = s0[1];          // --> set initial guess
    double T = T0;         // --> set initial temperature
    int j = 1;             // contador global
    int k = 1;             // --> counter for accepted solutions
    int c[dim];
	//c[0] = c[1] = 1;       // --> crystallization factor for the variable
    srand(time(NULL));
    ffmin = f(s);
    //smin[0] = s[0];
	//smin[1] = s[1];
    FILE *saida;
    saida = fopen("saida.txt", "w");
    // inicializa
    for (int ll =0; ll < dim; ll++) {
    	s0[ll] = (max[ll] - min[ll]) * 0.5 + min[ll];
    	delta[ll] = (max[ll] - min[ll]) * 0.25;
    	s[ll] = s0[ll];
    	c[ll] = 1;
    	smin[ll] = s[ll];
	}
	printf("\r\nVariaveis inicializadas ");
    // loop principal
    while (k != 0) {       // --> Have we reached the frozen state (k == 0)? Converged.
                           // -->  if k == 0 there is no accepted solutions, frozen state
        int i = 1;         // --> start the counter for candidate evaluation
        k = 0;             // --> start the counter for frozen state, number of accepted solutions
        
        fmin = fmax = fmed = f(s);
        
        while (k < l && i < p) {  // --> Have we reached the thermal equilibrium?
                                  // --> The number of candidate evaluation is enough (i == p)? Thermal equilibrium
                                  // --> The number of accepted solutions is enough ( k == l)? Thermal equilibrium
            int ii = (int)((double)dim * rand()/(double)RAND_MAX);
            double ss[dim];

            do {
    			double d = 0.0;       // --> Next candidate evaluation
                for (int kk = 0 ; kk < c[ii] ; kk ++) {   // --> Evaluate the cristalization factor
                    d += 2.0 * rand()/(double)RAND_MAX - 1.0;
                }
                d = d / (double)c[ii] * delta[ii];           // --> Multiply by the maximum jump - skip
                //ss[0] = s[0];
			    //ss[1] = s[1];
			    memcpy(&ss, &s, sizeof(s));
			    ss[ii] += d;
			} while (ss[ii] < min[ii] || ss[ii] > max[ii]);
			printf("*");
            
            double delta = f(ss) - f(s);           // --> evaluate the difference in energy

            if (delta < 0 || exp(-delta/T) > rand()/(double)RAND_MAX) {
            	                     // --> if energy is lower (delta < 0)? we accept the candidate
            	                     // --> if the Boltzman probability is accepted? we accept the candidate
                s[ii] = ss[ii];      // --> set the new solution
                k ++;                // --> increase the accepted solution counter
                if (c[ii] > 1) c[ii] = c[ii] - 1;   // --> decrease the crystalization factor
                //c[ii] = 1;
                if (fmin > f(s)) fmin = f(s);
                if (ffmin > f(s)) {
                   ffmin = f(s);
				   //smin[0] = s[0];
				   //smin[1] = s[1];	
				   memcpy(&smin, &s, sizeof(smin));
				}
                if (fmax < f(s)) fmax = f(s);
                fmed += f(s);
            }
            else {
			
                if (c[ii] < 40) {
                	printf("\r\nc[ii] = %d", c[ii]);
					c[ii] ++;   
				}        // --> if the candidate is rejected, we increase the crystallization factor
            }
            i ++;                    // --> increase the candidate evaluation counter
        }
        fmed = fmed / (double)k;
        fprintf(saida, "%f, %f, %f, %f, %2d, %2d, %d, %d\n", T, fmin, fmed, fmax, k, i, c[0], c[1]);
        printf("\r\n%f, %f, %f, %f, %2d, %2d, %d, %d\n", T, fmin, fmed, fmax, k, i, c[0], c[1]);
        
        T *= alfa;                   // --> decrease the temperature using geometric schedule
    }
    fclose(saida);
    printf("\r\nresult = %f, %f\n", smin[0], smin[1]);
    return s[0];
}

