#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int linearSearch(int* arr, int key, int n) {
	int count = 0;
	for(int i=0; i<n; i++) {
		count++;
		if(arr[i] == key) {
	    	return count;
	    }
	}
	return count;
}

void plotter() {
	srand(time(NULL));
	int* arr;
	int key, count;
	FILE *f1, *f2, *f3;
	f1 = fopen("bestcase.txt", "w");
	f2 = fopen("averagecase.txt", "w");
	f3 = fopen("worstcase.txt", "w");
	
	int n = 2;
	while(n <= 1024) {
		arr = (int*)malloc(n * sizeof(int));
		
		//best case
		for(int i=0; i<n; i++) 
			arr[i] = 1;
		key = 1;
		count = linearSearch(arr, key, n);
		fprintf(f1, "%d\t%d\n", n, count);

		//average case
		for(int i=0; i<n; i++) 
			arr[i] = rand() % n;
		key = rand() % n;
		count = linearSearch(arr, key, n);
		fprintf(f2, "%d\t%d\n", n, count);		

		//worst case
		for(int i=0; i<n; i++) 
			arr[i] = 0;
		key = 1;
		count = linearSearch(arr, key, n);
		fprintf(f3, "%d\t%d\n", n, count);
			
		n = n * 2;
		free(arr);
	}
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
}		
		
int main() {
	plotter();
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		