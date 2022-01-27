#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chessboard.h"
#define N 8

extern int T[N][N];
extern char *C[];
int verif;
int joueur;


void Afficchess(int T1[N][N])
{
    int i,j;
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
            {
                if (j==N-1)
                {
                    if (T1[i][j]==1){printf("P1     %d\n\n",8-i);}
                    if (T1[i][j]==2){printf("Kt1    %d\n\n",8-i);}
                    if (T1[i][j]==3){printf("B1     %d\n\n",8-i);}
                    if (T1[i][j]==4){printf("R1     %d\n\n",8-i);}
                    if (T1[i][j]==5){printf("Q1     %d\n\n",8-i);}
                    if (T1[i][j]==6){printf("K1     %d\n\n",8-i);}
                    if (T1[i][j]==10){printf("P2     %d\n\n",8-i);}
                    if (T1[i][j]==20){printf("Kt2    %d\n\n",8-i);}
                    if (T1[i][j]==30){printf("B2     %d\n\n",8-i);}
                    if (T1[i][j]==40){printf("R2     %d\n\n",8-i);}
                    if (T1[i][j]==50){printf("Q2     %d\n\n",8-i);}
                    if (T1[i][j]==60){printf("K2     %d\n\n",8-i);}
                    if (T1[i][j]==0){printf("..     %d\n\n",8-i);}
                    
                }
                else
                {
                    if (T1[i][j]==1){printf("P1  |  ");}
                    if (T1[i][j]==2){printf("Kt1 |  ");}
                    if (T1[i][j]==3){printf("B1  |  ");}
                    if (T1[i][j]==4){printf("R1  |  ");}
                    if (T1[i][j]==5){printf("Q1  |  ");}
                    if (T1[i][j]==6){printf("K1  |  ");}
                    if (T1[i][j]==10){printf("P2  |  ");}
                    if (T1[i][j]==20){printf("Kt2 |  ");}
                    if (T1[i][j]==30){printf("B2  |  ");}
                    if (T1[i][j]==40){printf("R2  |  ");}
                    if (T1[i][j]==50){printf("Q2  |  ");}
                    if (T1[i][j]==60){printf("K2  |  ");}
                    if (T1[i][j]==0){printf("..  |  ");}
                }
                
            }
    }
    printf("\na      b      c      d      e      f      j      h\n\n");
    
}
void moove(int i1,int i2,int j1,int j2)
{
    int *P1=T[i1];
    int *P2=T[i2];
    *(P2+j2)=*(P1+j1);
    *(P1+j1)=0; 
}
void paawn1(int i1,int i2,int j1,int j2)
{
        if ((i2==i1-1)&&(T[i2][j2]==0)&&(j1==j2))
        {
            moove(i1,i2,j1,j2);
            verif=1;
        }
        else if ((i2==i1-2)&&(T[i2][j2]==0)&&(j1==j2)&&(i1==6)&&(T[i1-1][j1]==0))
        {
            moove(i1,i2,j1,j2);
            verif=1;
        }
        else if ((i2==i1-1)&&(T[i2][j2]>9)&&(j1==j2+1))
        {
            moove(i1,i2,j1,j2);
            verif=1;
        }
        else if ((i2==i1-1)&&(T[i2][j2]>9)&&(j1==j2-1))
        {
            moove(i1,i2,j1,j2);
            verif=1;
        }
        else if (((i2==i1-1)&&(T[i2][j2]==0)&&(j2==j1+1))&&((T[i1-1][j1]>9)&&(T[i1][j1+1]>9)))
        {
            int *Pas1=T[i1];
            moove(i1,i2,j1,j2);
            *(Pas1+j1+1)=0;
            verif=1;
        }
        else if (((i2==i1-1)&&(T[i2][j2]==0)&&(j2==j1-1))&&((T[i1-1][j1]>9)&&(T[i1][j1-1]>9)))
        {
            int *Pas2=T[i1];
            moove(i1,i2,j1,j2);
            *(Pas2+j1-1)=0;
            verif=1;
        }
        else {printf("erreur\n\n\n");};
}
void paawn2(int i1,int i2,int j1,int j2)
{
    if ((i2==i1+1)&&(T[i2][j2]==0)&&(j1==j2))
        {
            moove(i1,i2,j1,j2);
            verif=1;
        }
    else if ((i2==i1+2)&&(T[i2][j2]==0)&&(j1==j2)&&(i1==1)&&(T[i1+1][j1]==0))
        {
            moove(i1,i2,j1,j2);
            verif=1;
        }
    else if ((i2==i1+1)&&(T[i2][j2]<9)&&(T[i2][j2]>0)&&(j1==j2+1))
        {
            moove(i1,i2,j1,j2);
            verif=1;
        }
    else if ((i2==i1+1)&&(T[i2][j2]<9)&&(T[i2][j2]>0)&&(j1==j2-1))
        {
            moove(i1,i2,j1,j2);
            verif=1;
        }
    else if ((i2==i1+1)&&(T[i2][j2]==0)&&(j2==j1+1)&&(T[i1+1][j1]<9)&&(T[i1+1][j1]>0)&&(T[i1][j1+1]<9)&&(T[i1][j1+1]>0))
        {
            int *Pas1=T[i1];
            moove(i1,i2,j1,j2);
            *(Pas1+j1+1)=0;
            verif=1;
        }
    else if ((i2==i1+1)&&(T[i2][j2]==0)&&(j2==j1-1)&&(T[i1+1][j1]<9)&&(T[i1+1][j1]>0)&&(T[i1][j1-1]<9)&&(T[i1][j1-1]>0))
        {
            int *Pas2=T[i1];
            moove(i1,i2,j1,j2);
            *(Pas2+j1-1)=0;
            verif=1;
        }
    else {printf("erreur\n\n\n");};
}

void knight1(int i1,int i2,int j1,int j2)
{
    if (T[i2][j2]==0||T[i2][j2]>9)
    {

        if ((i2==i1-2)&&(j2==j1-1))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1-2)&&(j2==j1+1))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1+2)&&(j2==j1+1))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1+2)&&(j2==j1-1))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1+1)&&(j2==j1-2))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1+1)&&(j2==j1+2))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1-1)&&(j2==j1-2))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1-1)&&(j2==j1+2))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else {printf("erreur1\n\n\n");};
    }
    else {printf("erreur2\n\n\n");};
}

void knight2(int i1,int i2,int j1,int j2)
{
    if (T[i2][j2]<9)
    {

        if ((i2==i1-2)&&(j2==j1-1))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1-2)&&(j2==j1+1))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1+2)&&(j2==j1+1))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1+2)&&(j2==j1-1))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1+1)&&(j2==j1-2))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1+1)&&(j2==j1+2))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1-1)&&(j2==j1-2))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else if ((i2==i1-1)&&(j2==j1+2))
            {
                moove(i1,i2,j1,j2);
                verif=1;
            }
        else {printf("erreur1\n\n\n");};
    }
    else {printf("erreur2\n\n\n");};
}

void rook1(int i1,int i2,int j1,int j2)
{
    int d,s;
    int v1=0;
    if ((j2==j1)&&(i1>i2))
        {
            d=i1-i2;
            for (s=1;s<d;s++)
            {
                if (T[i1-s][j1]!=0)
                {
                    printf("erreur4\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&((T[i1-d][j1]>9)||(T[i1-d][j1]==0)))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur5\n\n\n");} 
        }
    else if ((j2==j1)&&(i1<i2))
        {
            d=i1-i2;
            for (s=1;s<d;s++)
            {
                if (T[i1-s][j1]!=0)
                {
                    printf("erreur6\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&((T[i1-d][j1]>9)||(T[i1-d][j1]==0)))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur7.1\n\n\n");} 
        }
    else if ((i2==i1)&&(j1>j2))
        {
            d=j1-j2;
            for (s=1;s<d;s++)
            {
                if (T[i1][j1-s]!=0)
                {
                    printf("erreur7.2\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&((T[i1][j1-d]>9)||(T[i1][j1-d]==0)))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur7.3\n\n\n");} 
        }
    else if ((i2==i1)&&(j1<j2))
        {
            d=j1-j2;
            for (s=1;s<d;s++)
            {
                if (T[i1][j1-s]!=0)
                {
                    printf("erreur8\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&((T[i1][j1-d]>9)||(T[i1][j1-d]==0)))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur9\n\n\n");} 
        }
    else {printf("erreur10\n\n\n");} 
}

void rook2(int i1,int i2,int j1,int j2)
{
    int d,s;
    int v1=0;
    if ((j2==j1)&&(i1>i2))
        {
            d=i1-i2;
            for (s=1;s<d;s++)
            {
                if (T[i1-s][j1]!=0)
                {
                    printf("erreur11\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1-d][j1]<9))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur12\n\n\n");} 
        }
    else if ((j2==j1)&&(i1<i2))
        {
            d=i1-i2;
            for (s=1;s<d;s++)
            {
                if (T[i1-s][j1]!=0)
                {
                    printf("erreur13\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1-d][j1]<9))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur14\n\n\n");} 
        }
    else if ((i2==i1)&&(j1>j2))
        {
            d=j1-j2;
            for (s=1;s<d;s++)
            {
                if (T[i1][j1-s]!=0)
                {
                    printf("erreur15\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1][j1-d]<9))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur16\n\n\n");} 
        }
    else if ((i2==i1)&&(j1<j2))
        {
            d=j1-j2;
            for (s=1;s<d;s++)
            {
                if (T[i1][j1-s]!=0)
                {
                    printf("erreur17\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1][j1-d]<9))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur18\n\n\n");} 
        }
    else {printf("erreur19\n\n\n");} 
}

void bishop1(int i1,int i2,int j1,int j2)
{
    int d,s;
    int v1=0;
    if ((j2>j1)&&(i1>i2))
        {
            d=i1-i2;
            for (s=1;s<d;s++)
            {
                if (T[i1-s][j1+s]!=0)
                {
                    printf("erreur20\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1-d][j1+d]>9)||(T[i1-d][j1+d]==0))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur21\n\n\n");} 
        }
    else if ((j2<j1)&&(i1<i2))
        {
            d=j1-j2;
            for (s=1;s<d;s++)
            {
                if (T[i1+s][j1-s]!=0)
                {
                    printf("erreur22\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1+d][j1-d]>9)||(T[i1+d][j1-d]==0))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur23\n\n\n");} 
        }
    else if ((j2<j1)&&(i2<i1))
        {
            d=j1-j2;
            for (s=1;s<d;s++)
            {
                if (T[i1-s][j1-s]!=0)
                {
                    printf("erreur24\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1-d][j1-d]>9)||(T[i1-d][j1-d]==0))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur25\n\n\n");} 
        }
    else if ((j2>j1)&&(i1<i2))
        {
            d=j2-j1;
            for (s=1;s<d;s++)
            {
                if (T[i1+s][j1+s]!=0)
                {
                    printf("erreur26\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1+d][j1+d]>9)||(T[i1+d][j1+d]==0))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur27\n\n\n");} 
        }
    else {printf("erreur28\n\n\n");} 
}   

void bishop2(int i1,int i2,int j1,int j2)
{
    int d,s;
    int v1=0;
    if ((j2>j1)&&(i1>i2))
        {
            d=i1-i2;
            for (s=1;s<d;s++)
            {
                if (T[i1-s][j1+s]!=0)
                {
                    printf("erreur29\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1-d][j1+d]<9))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur30\n\n\n");} 
        }
    else if ((j2<j1)&&(i1<i2))
        {
            d=j1-j2;
            for (s=1;s<d;s++)
            {
                if (T[i1+s][j1-s]!=0)
                {
                    printf("erreur31\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1+d][j1-d]<9))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur32\n\n\n");} 
        }
    else if ((j2<j1)&&(i2<i1))
        {
            d=j1-j2;
            for (s=1;s<d;s++)
            {
                if (T[i1-s][j1-s]!=0)
                {
                    printf("erreur33\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1-d][j1-d]<9))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur34\n\n\n");} 
        }
    else if ((j2>j1)&&(i1<i2))
        {
            d=j2-j1;
            for (s=1;s<d;s++)
            {
                if (T[i1+s][j1+s]!=0)
                {
                    printf("erreur35\n\n\n");
                    v1=1;
                    return;
                }
            }
            if ((v1==0)&&(T[i1+d][j1+d]<9))
            {
                moove(i1,i2,j1,j2);
                verif=1;    
            }
            else {printf("erreur36\n\n\n");} 
        }
    else {printf("erreur37\n\n\n");} 
}   

void queen1(int i1,int i2,int j1,int j2)
{
    int d,s;
    int v1=0;
    if (((j2>j1)&&(i1>i2))||((j2<j1)&&(i1<i2))||((j2<j1)&&(i2<i1))||((j2>j1)&&(i1<i2)))
        {
            bishop1(i1,i2,j1,j2);
        }
    else if (((j2==j1)&&(i1>i2))||((j2==j1)&&(i1<i2))||((j2<j1)&&(i1==i2))||((j2>j1)&&(i1==i2)))
        {
            rook1(i1,i2,j1,j2);
        }
    else {printf("erreur38\n\n\n");} 
}

void queen2(int i1,int i2,int j1,int j2)
{
    int d,s;
    int v1=0;
    if (((j2>j1)&&(i1>i2))||((j2<j1)&&(i1<i2))||((j2<j1)&&(i2<i1))||((j2>j1)&&(i1<i2)))
        {
            bishop2(i1,i2,j1,j2);
        }
    else if (((j2==j1)&&(i1>i2))||((j2==j1)&&(i1<i2))||((j2<j1)&&(i1==i2))||((j2>j1)&&(i1==i2)))
        {
            rook2(i1,i2,j1,j2);
        }
    else {printf("erreur38\n\n\n");} 
} 

void king1(int i1,int i2,int j1,int j2)
{
    if (((j2==j1)&&(i2==i1+1))||((j2==j1)&&(i2==i1-1))||((j2==j1+1)&&(i2==i1))||((j2==j1-1)&&(i1==i2)))
    {
        rook1(i1,i2,j1,j2);
    }
    else if (((j2==j1+1)&&(i2==i1+1))||((j2==j1+1)&&(i2==i1-1))||((j2==j1-1)&&(i2==i1+1))||((j2==j1-1)&&(i2==i1-1)))
    {
        bishop1(i1,i2,j1,j2);
    }
    else{printf("erreur40\n\n");}
}

void king2(int i1,int i2,int j1,int j2)
{
    if (((j2==j1)&&(i2==i1+1))||((j2==j1)&&(i2==i1-1))||((j2==j1+1)&&(i2==i1))||((j2==j1-1)&&(i1==i2)))
    {
        rook2(i1,i2,j1,j2);
    }
    else if (((j2==j1+1)&&(i2==i1+1))||((j2==j1+1)&&(i2==i1-1))||((j2==j1-1)&&(i2==i1+1))||((j2==j1-1)&&(i2==i1-1)))
    {
        bishop2(i1,i2,j1,j2);
    }
    else{printf("erreur41\n\n");}
}

void chessmove(char cc1[2],char cc2[2])
{
    int i;
    int i1,i2,j1,j2;
    int r2,r1;

    for(i=0;i<64;i++)
    {
        r1=strncmp(cc1,C[i],2);
        r2=strncmp(cc2,C[i],2);
        if (r2==0)
        {
            i2=i/8;
            j2=i%8;
        }
        if (r1==0)
        {
            i1=i/8;
            j1=i%8;
        }
    }
    if ((T[i1][j1]==1)&&(joueur==1))//pawn 1
    {
        
        paawn1(i1,i2,j1,j2);
        
    }
    else if ((T[i1][j1]==10)&&(joueur==2))//pawn 2
    {
  
        paawn2(i1,i2,j1,j2);
        
    }
    else if ((T[i1][j1]==2)&&(joueur==1))//knight 1
    {

        knight1(i1,i2,j1,j2);

    }
    else if ((T[i1][j1]==20)&&(joueur==2))//knight 1
    {

        knight2(i1,i2,j1,j2);

    }
    else if ((T[i1][j1]==4)&&(joueur==1))//rook 1
    {

        rook1(i1,i2,j1,j2);

    }
    else if ((T[i1][j1]==40)&&(joueur==2))//rook 2
    {

        rook2(i1,i2,j1,j2);

    }
    else if ((T[i1][j1]==3)&&(joueur==1))//bishop 1
    {

        bishop1(i1,i2,j1,j2);

    }
    else if ((T[i1][j1]==30)&&(joueur==2))//bishop 2
    {

        bishop2(i1,i2,j1,j2);

    }
    else if ((T[i1][j1]==5)&&(joueur==1))//queen 1
    {

        queen1(i1,i2,j1,j2);

    }
    else if ((T[i1][j1]==50)&&(joueur==2))//queen 2
    {

        queen2(i1,i2,j1,j2);

    }
    
    else if ((T[i1][j1]==6)&&(joueur==1))//king 1
    {

        king1(i1,i2,j1,j2);

    }
    else if ((T[i1][j1]==60)&&(joueur==2))//king 2
    {

        king2(i1,i2,j1,j2);

    }
    
    else {printf("erreur3\n\n\n");};
}

int echec1(void)//king 1 echec verification
{
    int i,j,kgi,kgj;
    int k1pos=0;
    int ve1=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if (T[i][j]==6)
            {
                kgi=i;
                kgj=j;
                k1pos = 1;
                break;
            }
        }
        
    }
    if (k1pos==1)
    {
        for(i=1;i<8;i++)
        {
            if ((T[kgi-i][kgj+i]!=50)&&(T[kgi-i][kgj+i]!=30)&&(T[kgi-i][kgj+i]!=0))
            {
                break;
            }

            else if ((T[kgi-i][kgj+i]==50)||(T[kgi-i][kgj+i]==30))
            {
                printf("\nechec 1\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi-i][kgj-i]!=50)&&(T[kgi-i][kgj-i]!=30)&&(T[kgi-i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi-i][kgj-i]==50)||(T[kgi-i][kgj-i]==30))
            {
                printf("\nechec 1\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi+i][kgj+i]!=50)&&(T[kgi+i][kgj+i]!=30)&&(T[kgi+i][kgj+i]!=0))
            { 
                break;
            }

            else if ((T[kgi+i][kgj+i]==50)||(T[kgi+i][kgj+i]==30))
            {
                printf("\nechec 1\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi+i][kgj-i]!=50)&&(T[kgi+i][kgj-i]!=30)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi+i][kgj-i]==50)||(T[kgi+i][kgj-i]==30))
            {
                printf("\nechec 1\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi+i][kgj]!=50)&&(T[kgi+i][kgj]!=40)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi+i][kgj]==50)||(T[kgi+i][kgj]==40))
            {
                printf("\nechec 1\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi-i][kgj]!=50)&&(T[kgi-i][kgj]!=40)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi-i][kgj]==50)||(T[kgi-i][kgj]==40))
            {
                printf("\nechec 1\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi][kgj+i]!=50)&&(T[kgi][kgj+i]!=40)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi][kgj+i]==50)||(T[kgi][kgj+i]==40))
            {
                printf("\nechec 1\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi][kgj-i]!=50)&&(T[kgi][kgj-i]!=40)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi][kgj-i]==50)||(T[kgi][kgj-i]==40))
            {

                printf("\nechec 1\n\n");
                ve1=1;
                return ve1;
            }
        }
    
        //knight echec verif
        if ((T[kgi+1][kgj+2]==20)||(T[kgi+2][kgj+1]==20)||(T[kgi-2][kgj+1]==20)||(T[kgi-1][kgj+2]==20)||(T[kgi+2][kgj-1]==20)||(T[kgi+1][kgj-2]==20)||(T[kgi-2][kgj-1]==20)||(T[kgi-1][kgj-2]==20))
        {
            printf("\nechec 1\n\n");
            ve1=1;
            return ve1;
        }
        return 0;
      

    }
    else {printf("\nerreur : cant find king 1\n\n");}

}

int echec2(void)//king 2 echec verification
{
    int i,j,kgi,kgj;
    int k1pos=0;
    int ve1=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if (T[i][j]==60)
            {
                kgi=i;
                kgj=j;
                k1pos = 1;
                break;
            }
        }
        
    }
    if (k1pos==1)
    {
        for(i=1;i<8;i++)
        {
            if ((T[kgi-i][kgj+i]!=5)&&(T[kgi-i][kgj+i]!=3)&&(T[kgi-i][kgj+i]!=0))
            {
                break;
            }

            else if ((T[kgi-i][kgj+i]==5)||(T[kgi-i][kgj+i]==3))
            {
                printf("\nechec 2\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi-i][kgj-i]!=5)&&(T[kgi-i][kgj-i]!=3)&&(T[kgi-i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi-i][kgj-i]==5)||(T[kgi-i][kgj-i]==3))
            {
                printf("\nechec 2\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi+i][kgj+i]!=5)&&(T[kgi+i][kgj+i]!=3)&&(T[kgi+i][kgj+i]!=0))
            { 
                break;
            }

            else if ((T[kgi+i][kgj+i]==5)||(T[kgi+i][kgj+i]==3))
            {
                printf("\nechec 2\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi+i][kgj-i]!=5)&&(T[kgi+i][kgj-i]!=3)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi+i][kgj-i]==5)||(T[kgi+i][kgj-i]==3))
            {
                printf("\nechec 2\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi+i][kgj]!=5)&&(T[kgi+i][kgj]!=4)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi+i][kgj]==5)||(T[kgi+i][kgj]==4))
            {
                printf("\nechec 2\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi-i][kgj]!=5)&&(T[kgi-i][kgj]!=4)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi-i][kgj]==5)||(T[kgi-i][kgj]==4))
            {
                printf("\nechec 2\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi][kgj+i]!=5)&&(T[kgi][kgj+i]!=4)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi][kgj+i]==5)||(T[kgi][kgj+i]==4))
            {
                printf("\nechec 2\n\n");
                ve1=1;
                return ve1;
            }
        }
        for(i=1;i<8;i++)
        {
            if ((T[kgi][kgj-i]!=5)&&(T[kgi][kgj-i]!=4)&&(T[kgi+i][kgj-i]!=0))
            {
                break;
            }

            else if ((T[kgi][kgj-i]==5)||(T[kgi][kgj-i]==4))
            {

                printf("\nechec 2\n\n");
                ve1=1;
                return ve1;
            }
        }
    
        //knight echec verif
        if ((T[kgi+1][kgj+2]==2)||(T[kgi+2][kgj+1]==2)||(T[kgi-2][kgj+1]==2)||(T[kgi-1][kgj+2]==2)||(T[kgi+2][kgj-1]==2)||(T[kgi+1][kgj-2]==2)||(T[kgi-2][kgj-1]==2)||(T[kgi-1][kgj-2]==2))
        {
            printf("\nechec 2\n\n");
            ve1=1;
            return ve1;
        }
        return 0;
      

    }
    else {printf("\nerreur : cant find king 1\n\n");}

}
