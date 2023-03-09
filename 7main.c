#include <stdio.h>
#include <stdlib.h>

void vvod(int**, int, int);
void vivod(int**, int, int);
void proverka(int**, int, int);

int main(){
    int **matr;
    int n,m;
    printf("Vvedite kol-vo strok:\n");
    scanf("%d",&n);
    printf("Vvedite kol-vo stolbcov:\n");
    scanf("%d",&m);
    vvod(matr,n,m);
}
void vvod(int **a, int n,int m){
    a = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) 
    {
        a[i]= (int*)malloc(m * sizeof(int));
        for(int j = 0;j < m;j++)
        {
            printf("Vvedite element  a[%d][%d]: ",i+1,j+1);
            scanf("%d",(a[i]+j));
        }
     }
     vivod(a,n,m);
}
void vivod (int **a, int n,int m)
{
    printf("Vvedennaz matrica:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%2d",*(a[i]+j));
        }
        printf("\n");
    }
    proverka(a,n,m);
}
void proverka(int **a, int n, int m)
{
    int stroki,kolonni;
    int p = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(*(a[i]+j) < 0 && p == 0){
                stroki = i;
                kolonni = j;
                printf("Otricatel'niy element pod nomerom ': [%d][%d]\n",stroki+1,kolonni+1);
                p = 1;
            }
        }
    }
    if(p == 0)
    printf("Otracatelnix net \n");           
}