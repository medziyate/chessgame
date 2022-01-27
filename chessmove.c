#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#define N 8

int i,j;
int n=1;
int ech1,ech2;


extern int T[N][N];
extern char *C[];
extern int verif;
extern int joueur;

extern void Afficchess(int T1[N][N]);
extern void moove(int, int, int ,int);
extern void chessmove(char cc1[2],char cc2[2]);

extern void paawn1(int,int,int,int);
extern void paawn2(int,int,int,int);

extern void knight1(int,int,int,int);
extern void knight2(int,int,int,int);

extern void rook1(int,int,int,int);
extern void rook2(int,int,int,int);

extern void bishop1(int,int,int,int);
extern void bishop2(int,int,int,int);

extern void queen1(int,int,int,int);
extern void queen2(int,int,int,int);

extern void king1(int,int,int,int);
extern void king2(int,int,int,int);

extern int echec1(void);
extern int echec2(void);


int main()
{
    char cs1[3];
    char cs2[3];
    Afficchess(T);
    
    
    while(1)
    {
        verif=0;
        printf("Tour %d : \n",n);
        printf("Move Joueur Blanc : \n");
        while(1)
        {
            joueur=1;
            ech1=0;
            ech1=echec1();
            printf("which one ?\n"); 
            gets(cs1);
            printf("where ?\n"); 
            gets(cs2);
            printf("\n\n");       
            chessmove(cs1,cs2);
            if ((verif==1)&&(ech1==0)){break;}
        }
        verif=0;
        Afficchess(T);
        printf("Move Joueur Noir: \n"); 

        while(1)
        {
            joueur=2;
            ech2=0;
            ech2=echec2();
            printf("which one ?\n"); 
            gets(cs1);
            printf("where ?\n"); 
            gets(cs2);
            printf("\n\n");       
            chessmove(cs1,cs2);
            if ((verif==1)&&(ech2==0)){break;}
        }
        Afficchess(T);

        if (n==4){return 0;}//cas erreur boucle infinie
        n++;
    }
    
    return 0;
}

 