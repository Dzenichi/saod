#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    
    int i,j,min,n,temp;
    
    printf("Число элементов массива");
    scanf("%d", &n);
    
    int *array=(int*)malloc(n*sizeof(int));
    
    clock_t begin = clock();
    
    for(i=0;i<=n-1;i++){
	array[i]=rand()%100;
    }
    
    for(i=0;i<=n-1;j++){
	min=i;
	for(j=i+1; j<=n; j++){
	    if(array[j]<array[min]){
	    min=j;
	    }
	}

    
    temp=array[i];
    array[i]=array[min];
    array[min]=temp;
    }
    for(i=0; i<n-1; i++){
	printf("%d\t%d\n", i+1,array[i]);
    }
    clock_t end =clock();
    printf("%f sec: \n", (double)(end-begin) / CLOCKS_PER_SEC);
    return 0;
}