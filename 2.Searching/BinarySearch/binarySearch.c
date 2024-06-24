#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count = 0;

int binarySearch(int *arr, int key, int start, int end) {
	if(start > end) {
		return count;
	}
	count++;
	int mid = start + (end-start)/2;
	
	if(arr[mid] == key) {
		return count;
	}
	else if(arr[mid] > key) {
		end = mid - 1;
		return binarySearch(arr, key, start, end);
	}
	else {
		start = mid + 1;
		return binarySearch(arr, key, start, end);
	}
}

void plotter() {
	srand(time(NULL));
	int *arr;
	int key, c;
	FILE *f1, *f2, *f3;
	f1 = fopen("bestcase.txt", "w");
	f2 = fopen("averagecase.txt", "w");
	f3 = fopen("worstcase.txt", "w");
	
	int n = 2;
	int start, end;
	
	while(n <= 1024) {
		arr = (int *)malloc(n*sizeof(int));
		start = 0;
		end = n-1;
		
		//best case
		for(int i=0; i<n; i++)
			arr[i] = 1;
		key = 1;
		count = 0;
		c = binarySearch(arr, key, start, end);
		fprintf(f1, "%d\t%d\n", n, c);

		//average case
		for(int i=0; i<n; i++) 
			arr[i] = i;
		key = arr[rand()%n +1];
		count = 0;
		c = binarySearch(arr, key, start, end);
		fprintf(f2, "%d\t%d\n", n, c);
		
		//worst case
		for(int i=0; i<n; i++) 
			arr[i] = 1;
		key = 0;
		count = 0;
		c = binarySearch(arr, key, start, end);
		fprintf(f3, "%d\t%d\n", n, c);
	
	
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
	