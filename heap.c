#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXL 1000

void swap (int *array, int *mas)
{
    int t = *array;
    *array=*mas;
    *mas = t;
}
int main()
{
    int array[MAXL], n ,i ,sh=0,b;
    
    scanf("%i", &n);
    for (i=0;i<n;++i){
	scanf("%i", &array[i]);
    }
    while(1)
    {
	b=0;
	for(i=0;i<n;++i){
	    if(i*2+2+sh<n){
		if(array[i+sh]>array[i*2+1+sh] || array[i+sh]>array[i*2+2+sh]){
		    if (array[i*2+1+sh]<array[i*2+2+sh]){
			swap(&array[i+sh],&array[i*2+1+sh]);
			b=1;
			}
			else if (array[i*2+2+sh]<array[i*2+1+sh]){
			    swap(&array[i+sh],&array[i*2+2]);
			    b=1;
			}
		    }
		}
	    else if (i*2+1+sh<n){
		if (array[i+sh]>array[i*2+1+sh]){
		    swap(&array[i+sh],&array[i*2+1+sh]);
		    b=1;
		}
	    }
	}
	if (!b) sh++;
	if(sh+2==n)
	break;
    }
    for (i=0;i<n;++i){
	printf("%i%c",array[i], (i!=n-1)?' ':'\n');
    }
    return 0;
}