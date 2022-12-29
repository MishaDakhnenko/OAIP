#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the dimension of the square matrix:\n");
    scanf("%d",&n);
    int a[n][n];

    printf("The matrix will be filled with random numbers from -1 to 10\n");
    int p,o;
    p=10;
    o=-1;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            a[i][j]=o+rand()%(p - o +1);
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    int i,f,q,j;
    q=1;

    for(int j=0;j<n;j++){
        int p = 0;
        int sum=0;
        for (int i = 0; i < n; i++) 
        if(a[i][j]>=0) p++;
        if(p==n){
            for(int k=0;k<n;k++)
            sum+=a[k][j];
            printf("Sum of columns with positive elements: %d\n",sum);
            q=0;
        }
    }
        if(q==1)
    {
        printf("No such columns\n");
    }
    
    int sum,summin;
    for (int i = 0; i< n - 1; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            if (j != n - 1)
            {
                sum += abs(a[i - j][j]);
            }
            if ((i == 0) || (summin > sum))
            {
                summin = sum;
            }
        }
    }
    
    for (int i = 1; i< n - 1; i++) 
    {
        int sum = 0;
        for (int j = 0; j < n - i; j++)
        {
            sum += abs(a[i + j][n - i - j]);
        }
        if (summin > sum)
        {
            summin = sum;
        }
    }
    if (abs(a[n - 1][n - 1]) < summin)
    {
        summin = abs(a[n - 1][n - 1]);
    }
    printf("The min sum of the modules of the elements of the diagonal parallel to the secondary: %d\n",summin);
    return 0;
}