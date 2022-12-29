#include <stdio.h>
#include <stdlib.h>

int main(){
    int m,n,i,j;
    printf("Enter the number of matrix row:\n");
    scanf("%d",&n);
    printf("Enter the number of matrix columns:\n");
    scanf("%d",&m);
    int **a;

    a = (int**)malloc(n * sizeof(int*));

    for ( i = 0; i < n; i++) 
    {
        a[i]= (int*)malloc(m * sizeof(int));
        for( j = 0;j < m;j++)
        {
            printf("Enter elements a[%d][%d]: ",i+1,j+1);
            scanf("%d",(a[i]+j));
        }
    }

    printf("Introduced matrix:\n");
    for( i = 0;i < n;i++){
        for( j = 0;j < n;j++){
            printf("%4d",*(a[i]+j));
        }
        printf("\n");
    }

    int zamen_str, zamen;
    int *sum;
    sum = (int*)malloc( n*sizeof(*sum) );
    for(int i = 0;i < n;i++)
    {
        *(sum+i) = 0;
        for( j = 0; j < m; j++){
            if(*(*(a+i)+j) > 0 && *(*(a+i)+j)%2==0){
                *(sum+i)+= *(*(a+i)+j);
            }
        }
    }

    for( i = 0 ; i < n - 1; i++) 
    {

        for(j = 0 ; j < n - i - 1 ; j++)
        {
            if(*(sum+j) > *(sum+(j+1)))
            {
                zamen = *(sum+j);
                *(sum+j) = *(sum+(j+1));
                *(sum+(j+1)) = zamen;
                for(int k=0;k<m;k++)
                {
                    zamen_str = *(*(a+j)+k);
                    *(*(a+j)+k) = *(*(a+(j+1))+k);
                    *(*(a+(j+1))+k) = zamen_str;
                }
            }
        }  
    }
    printf("The transformed matrix in accordance with the growth of characteristics:\n");

    for( i = 0; i < n; i++)
    {
        for( j = 0; j < m; j++)
        {
            printf("%4d",*(*(a+i)+j));
        }
        printf("\n");
    }
    return 0;
}