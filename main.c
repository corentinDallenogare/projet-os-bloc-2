#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "voiture.h"
#include "cirquit.h"




int main(int argc, char**argv){
    int nbreVoiture = 20;
    int nbreTours = 60; //nombre tours
    int longueurTours = 5; //en Km
    int uneHeure = 600 ; //d�finir combient vaut 1h



    int numero[20] = {44, 77, 16, 5, 33, 23, 55, 4, 3, 31, 10, 26, 11, 18, 7, 99, 20, 8, 63, 6};
    maVoiture voitureEnMem[20]; //tableau de voitures
    maVoiture qualif1[15];
    maVoiture qualif2[10];
    for(int i = 0; i < 20 ; i++){ //Attribuer les id au tableau de voiture
        voitureEnMem[i].numero = numero[i];
    }


/* ==========================================

Vendredi matin s�ance d'essais libre d'1h30 (P1)

=============================================*/


    lancerCourse(nbreVoiture,900.0,voitureEnMem);
    creationFichier(nbreVoiture,voitureEnMem,1);
    sleep(1);
    //triDuTableau(voitureEnMem, 20);




/* ==========================================

Vendredi apr�s midi s�ance d'essais libre d'1h30 (P2)

=============================================*/
    lancerCourse(nbreVoiture,900.0,voitureEnMem);
    creationFichier(nbreVoiture,voitureEnMem,2);
    sleep(1);



/* ==========================================

Samedi matin s�ance d'essais libre d'1h (P3)

=============================================*/
    lancerCourse(nbreVoiture,600.0,voitureEnMem);
    creationFichier(nbreVoiture,voitureEnMem,3);
    sleep(1);



/* ==========================================

Samedi apr�s midi s�ance de qualification en 3 parties

Q1, dur�e 18 minutes => �limine 5 voitures
Q2, dur�e 15 minutes => �limine 5 voitures
Q3, dur�e 12 minutes => classe les 10 derni�res voitures

=============================================*/

    lancerCourse(nbreVoiture,180.0,voitureEnMem);  //18 minutes
    triDuTableau(voitureEnMem, nbreVoiture);
    /*for(int k = 0 ; k < 20 ; k++){
        printf("%f %d\n", voitureEnMem[k].meilleurTemps, voitureEnMem[k].numero);
    }*/
    printf("\n");
    nbreVoiture -= 5;
    /*for(int i = 0; i<nbreVoiture; i++){
        qualif1[i] = voitureEnMem[i];
    }
    for(int k = 0 ; k < 15 ; k++){
        printf("%f %d\n", qualif1[k].meilleurTemps, qualif1[k].numero);
    }*/
    sleep(1);


    printf("\n");
    lancerCourse(nbreVoiture,150.0,voitureEnMem);  //15 minutes
    triDuTableau(voitureEnMem, nbreVoiture);
    nbreVoiture -= 5;
    /*for(int j = 0; j<nbreVoiture; j++){
        qualif2[j] = qualif1[j];
    }
    for(int k = 0 ; k < 10 ; k++){
        printf("%f %d\n", qualif2[k].meilleurTemps, qualif2[k].numero);
    }*/
    sleep(1);


    lancerCourse(nbreVoiture,120.0,voitureEnMem);  //12 minutes
    creationFichier(nbreVoiture,voitureEnMem,4);
    sleep(1);
/* ==========================================

Dimanche apr�s midi la course en elle m�me

=============================================*/


    triDuTableau(voitureEnMem, nbreVoiture);
    lancerCourse(nbreVoiture,longueurTours*nbreTours,voitureEnMem);  //nbre de tours * nbre moyen du tour en minutes
    creationFichier(nbreVoiture,voitureEnMem,5);
    sleep(1);


    return 0;
}
