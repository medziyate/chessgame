#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#define N 8

int i,j;
int n=1;
int ech1,ech2;
int joueur;


extern int T[N][N];
extern char *C[];
extern int verif;
extern int joueur;

extern void Afficchess(int T1[N][N]);
extern void moove(char cc1[2],char cc2[2]);
extern int chessmove(char cc1[2],char cc2[2]);

extern int paawn1(int,int,int,int);
extern int paawn2(int,int,int,int);

extern int knight1(int,int,int,int);
extern int knight2(int,int,int,int);

extern int rook1(int,int,int,int);
extern int rook2(int,int,int,int);

extern int bishop1(int,int,int,int);
extern int bishop2(int,int,int,int);

extern int queen1(int,int,int,int);
extern int queen2(int,int,int,int);

extern int king1(int,int,int,int);
extern int king2(int,int,int,int);

extern int echec1(int M[N][N]);
extern int echec2(int M[N][N]);

extern int moovevirtu1(char cc1[2],char cc2[2]);
extern int moovevirtu2(char cc1[2],char cc2[2]);

int main()
{
    char cs1[3];
    char cs2[3];
    Afficchess(T);
    int verif1,verif2,verif3;
    
    while(1)
    {
        printf("Tour %d : \n",n);
        printf("Move Joueur Blanc : \n");
        joueur = 1;
        while(1)
        {
            verif1=echec1(T);
            printf("which one ?\n"); 
            gets(cs1);
            printf("where ?\n"); 
            gets(cs2);
            printf("\n\n");
            verif2=chessmove(cs1,cs2);
            if (verif2==1)
            {
                verif3=moovevirtu1(cs1,cs2);
                if (verif3==1)
                {
                    continue;
                }
                else
                {
                    moove(cs1,cs2);
                    break;
                
                }
            }
            else
            {
                continue;
            }      
            
        }
        Afficchess(T);
        printf("Move Joueur Noir: \n"); 
        joueur = 2;

        while(1)
        {

            verif1=echec2(T);
            printf("which one ?\n"); 
            gets(cs1);
            printf("where ?\n"); 
            gets(cs2);
            printf("\n\n");
            verif2=chessmove(cs1,cs2);
            if (verif2==1)
            {
                verif3=moovevirtu2(cs1,cs2);
                if (verif3==1)
                {
                    continue;
                }
                else
                {
                    moove(cs1,cs2);
                    break;
                }
            }
            else
            {
                continue;
            }        
        }
        Afficchess(T);

        if (n==4){return 0;}//cas erreur boucle infinie
        n++;
    }
    
    return 0;
}

 