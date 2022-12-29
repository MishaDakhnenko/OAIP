#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void main()

{
    int *a,n,m,i;
    printf("%s\n", "How many elements will be in the array? ");
	scanf("%d", &n);

    a = (int*) malloc( n*sizeof(*a) );
    for ( i = 0; i < n; i++) {
        printf("Enter array elements a[%d]=",i+1);
        scanf("%d",&*(a+i));
        } 

    printf("Array: {");
    for ( i = 0; i < n; i++) {
            printf("%d",*(a+i));
            if (i < n-1) {
                printf(", ");
        } 
    }
    printf("}\n");

    int number,max;
    max = *(a+0);
    for( i = 1; i < n; i++){
        if (abs(max) < abs(*(a+i))){
            max = *(a+i);
            number = i;
        }
    }
    printf("The modulus of the maximum element is equal to %d and is numbered [%d]\n", max, number+1);

    int sum,j;
    for( i=0 ; i<n ; i++){
        sum = 0;
        if(*(a+i)>0){
            for( j = i + 1; j < n; j++){
                sum+= *(a+j);
            }
            break;
        }
    }
    printf("The sum is: %d\n",sum);
}