	//hackerrank easy challenge (insertion sort-part1)
	
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>
	#include <assert.h>
	
	void insertionSort(int ar_size, int *  ar) {
		int V; 
		V = ar[ar_size-1]; //last element (unsorted one)
		
		int curr_i; 
		curr_i = ar_size - 2; //start from last but one element
		
		int j;
		
		while(curr_i>=0 && ar[curr_i]>V){//curr_i>=0 : check for array bound
			ar[curr_i+1] = ar[curr_i];
			for(j = 0; j < ar_size; j++) printf("%d ", ar[j]);
			printf("\n");
			curr_i--;
		}
		ar[curr_i+1] = V; 
		for(j = 0; j < ar_size; j++) printf("%d ", ar[j]); 
		printf("\n");
		return;
	}
	
	int main(int argc, char* argv[]) {
	   
		int _ar_size;
		scanf("%d", &_ar_size);
		int _ar[_ar_size], _ar_i;
		for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) 
			scanf("%d", &_ar[_ar_i]); 
		
		insertionSort(_ar_size, _ar);
	   
	        return 0;
	}

