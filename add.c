#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

long timediff(clock_t t1,clock_t t2){ 
	return (t2-t1)*1000/CLOCKS_PER_SEC; 
} 

int main(int argc,char *argv[]){
	int array_size = 1966080; 
	
	srand(time(NULL));

	if(argc >= 2) 
		array_size = atoi(argv[1]); 

	long long repeat_times = (long long)20000000 * 500;
	long *arr1 = (long*)malloc(array_size*sizeof(long)); 
	long *arr2 = (long*)malloc(array_size*sizeof(long)); 
	long *arr3 = (long*)malloc(array_size*sizeof(long)); 

	for(int i = 0; i < array_size; ++i){
		arr1[i]=rand(); arr2[i]=rand();
	} 

	long long j = 0, k = 0; 
	long long c = 0;
	clock_t start = clock();

	while(j++ < (repeat_times)){
		if(k >= array_size) 
			k=0;
		arr3[k] = arr1[k] + arr2[k];
		k++;
	} 
	
	clock_t end = clock();

	printf("Time : %lums\n", timediff(start,end)); 

	return 0; 
}
