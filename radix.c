#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printarray(int* array, int n)
{
    int i;
    printf("[");
    for(i=0; i<n; i++){
	printf("%d ",array[i]);
    }
    printf("]\n");
}

int findlargestnum(int * array,int n)
{
    int i;
    int largestnum = -1;
    
    for(i=0; i<n; i++){
	if(array[i] > largestnum)
	    largestnum = array[i];
	}
	
    return largestnum;
}

//Radix sort
void radix(int * array,int n)
{
    printf("\n\n running radix on unsorted list! \n\n");
    
    //base 10 is used
    int i;
    int semisorted[n];
    int significantdigit = 1;
    int largestnum = findlargestnum(array,n);
    
    //loop until we reach the largest significant digit
    while(largestnum / significantdigit > 0){
	
	printf ("\t sorting: %d's place " , significantdigit);
	printarray(array,n);
	
	int bucket[10] = { 0 };
	
	//counts the number of keys or digits thet will go into each bucket
	for(i=0; i<n; i++){
	    bucket[(array[i] / significantdigit) % 10]++;
	}
	    
	for (i=1; i<10; i++){
	    bucket[i] += bucket[i - 1];
	}
	    
	    //use the bucket to fill a semisorted array
	for(i=n-1; i>=0; i--){
	    semisorted[--bucket[(array[i]/ significantdigit)%10]]=array[i];
	}
	    
	for(i=0; i<n; i++){
	    array[i]=semisorted[i];
	}
	    //move to next significant digit
	significantdigit *=10;
	    
	printf("\n\t bucket: ");
	printarray(bucket, 10);
    }
}


int main()
{
    printf("\n\n running radix sort example in c! \n");
    printf("----------------------------\n");
    
    int n = 12;
    int list[] = {10, 2, 303, 4021, 293, 1, 0, 429, 480, 92, 299, 14};
    
    printf("\n unsortedlist: ");
    printarray(&list[0], n);
    
    radix(&list[0], n);
    
    printf("\n sorted list: ");
    printarray(&list[0], n);
    printf("\n");
    
    return 0;
}