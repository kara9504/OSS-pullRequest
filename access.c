#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

long timediff(clock_t t1,clock_t t2){ 
	return (t2-t1)*1000/CLOCKS_PER_SEC; 
} 

int main(int argc,char *argv[]){
	int array_size = 3932160;
	//int array_size = 1966080; 

	srand(time(NULL));
	
	if(argc >= 2) 
		array_size = atoi(argv[1]); 

	long long repeat_times = 20000000 * (long long)500;
	//long long array[array_size]; 
	long* array = (long*)malloc(array_size*sizeof(long)); 

	for(int i = 0; i < array_size; ++i){
		array[i]=rand(); 
	} 

	long long j = 0, k = 0; 
	long long c = 0;
	clock_t start = clock();

	while(j++ < (repeat_times)){
		if(k == array_size) 
			k=0;
		int position = ((c + k) * j) % array_size;
		c += array[k] + position; 
		c = c % 100000; 
		k++;
	} 
	
	clock_t end = clock();

	printf("Time : %lums\n", timediff(start,end)); 

	return 0; 
}
