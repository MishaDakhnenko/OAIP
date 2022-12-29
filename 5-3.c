#include <stdio.h>
#include <stdlib.h>

int main(){
    int m,n,i,j;
    printf("Enter the number of matrix row:\n");
    scanf("%d",&n);
    printf("Enter the number of matrix columns:\n");
    scanf("%d",&m);
    float a[n][m];

    printf("The matrix will be filled with random numbers from -10 to 10\n");
    int p,o;
    p=10;
    o=-1;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            a[i][j]=o+rand()%(p - o +1);
            printf("%6.1f",a[i][j]);
        }
        printf("\n");
    }

    int k;
    printf("Negative number address:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(a[i][j]<0){
                printf("[%d][%d]\n",i+1,j+1);
                k=j;
            }
        }
    for(int i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(k==j)
            a[i][j]=a[i][j]/2;
        }
        
    }
    printf("A column containing one negative element will be reduced by 2 times\nResulting matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%6.1f",a[i][j]);
        }
        printf("\n");
    }
    return 0;   
}