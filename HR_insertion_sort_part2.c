	//HR easy challenge: insertion sort (part 2, the full sorting!)	
	// Insertion sort: 
	// Input line 1: number of elements to be sorted. 
	// Input line 2: elements to be sorted.
	// Output: each step of insertion sort
	
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
		
		while(ar[curr_i]>V){
			ar[curr_i+1] = ar[curr_i];
			curr_i--;
		}
		ar[curr_i+1] = V; 
	
		return;
	}
	
	int main(void) {
	   
     		int _ar_size;
		scanf("%d", &_ar_size);
		int _ar[_ar_size], _ar_i;
		for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) 
	   		scanf("%d", &_ar[_ar_i]); 
		
		int i, sub_ar_size, j;
		sub_ar_size = 1;
		
		for(i = 1; i < _ar_size; i++){
			sub_ar_size++;
			insertionSort(sub_ar_size, _ar);
			for(j = 0; j < _ar_size; j++) printf("%d ", _ar[j]); 
			printf("\n");
		}
	   
	        return 0;
	}
