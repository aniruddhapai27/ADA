#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count = 0;


void merge(int *arr, int low, int mid, int high) {
        int left_length = (mid-low)+1;
        int right_length = (high-mid);

        int i, j, k;
        int left[left_length];
        int right[right_length];
        for(i=0; i<left_length; i++) {
                left[i] = arr[low+i];
        }
        for(i=0; i<right_length; i++) {
                right[i] = arr[mid+1+i];
        }

        i=0;
        j=0;
        k=low;
        while(i < left_length && j < right_length) {
        	count++;
                if(left[i] < right[j]) {
                        arr[k] = left[i];
                        i++;
                }
                else {
                        arr[k] = right[j];
                        j++;
                }
                k++;
        }

        while(i<left_length) {
                arr[k++] = left[i];
                i++;
        }
        while(j<right_length) {
                arr[k++] = right[j];
                j++;
        }

}
void mergesort(int* arr, int low, int high) {
        if(low>=high) {
                return;
        }
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);

        merge(arr, low, mid, high);

}

void plotter() {
	int *arr, n;
	srand(time(NULL));
	FILE *f1, *f2, *f3;
	f1 = fopen("m_b.txt", "a");
	f2 = fopen("m_w.txt", "a");
	f3 = fopen("m_a.txt", "a");
	
	for(n=2; n<=1024; n*=2) {
	    arr = (int *)malloc(sizeof(int)*n);
	    
	    //Best case
	    for(int i=0; i<n; i++) {
	    	*(arr+i) = i+1;
	    }
	    count = 0;
	    mergesort(arr, 0, n-1);
	    fprintf(f1, "%d\t%d\n", n, count);
	    
	    //worst case
	    count = 0;
	    for(int i=0; i<n; i++) {
	    	*(arr+i) = n-i-1;
	    }
	    mergesort(arr, 0, n-1);
	    fprintf(f2, "%d\t%d\n", n, count);
	    
	    //Average case
	    for(int i=0; i<n; i++) {
	    	*(arr+i) = rand()%n;
	    }
	    count = 0;
	    mergesort(arr, 0, n-1);
	    fprintf(f3, "%d\t%d\n", n, count);
	    
	    free(arr);
	}    
	
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
}

int main() {
    plotter();
}