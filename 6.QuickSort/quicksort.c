#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count = 0;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
	

int partition(int *arr, int low, int high) {
	int pivot = arr[low];
	int i=low;
	int j=high+1;
	do {
  	  do {
  	    count++;
  	    i++;
  	  } while(arr[i] <= pivot);
  	  do {
  	    count++;
      	    j--;
  	  } while(arr[j] > pivot);
  	
  	  if(i<=j) {
  	    swap(&arr[i], &arr[j]);
  	  }
  	} while(i<=j);
  	swap(&arr[low], &arr[j]);
  	return j;
}
  	  
		

void quicksort(int *arr, int low, int high) {
	if(low >= high) {
		return;
	}
	int p = partition(arr, low, high);
	quicksort(arr, low, p-1);
	quicksort(arr, p+1, high);
}

void plotter() {
	int *arr, n;
	srand(time(NULL));
	FILE *f1, *f2, *f3;
	f1 = fopen("q_b.txt", "a");
	f2 = fopen("q_w.txt", "a");
	f3 = fopen("q_a.txt", "a");
	
	n = 4;
	while(n<1034) {
	    arr = (int*)malloc(sizeof(int)*n);
	    
	    //Best case
	    for(int i=0; i<n; i++) {
	        *(arr+i) = 5; //same value for each elements
	    }
	    count = 0;
	    quicksort(arr, 0, n-1);
	    fprintf(f1, "%d\t%d\n", n, count);
	    
	    //Worst case
	    for(int i=0; i<n; i++) {
	    	*(arr+i) = i+1;
	    }
	    count = 0;
	    quicksort(arr, 0, n-1);
	    fprintf(f2, "%d\t%d\n", n, count);
	    
	    //Average case
	    for(int i=0; i<n; i++) {
	    	*(arr+i) = rand()%n;
	    }
	    count = 0;
	    quicksort(arr, 0, n-1);
	    fprintf(f3, "%d\t%d\n", n, count);
	    
	    n *= 2;
	    free(arr);
	}
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	
}

int main() {
        plotter();
}

