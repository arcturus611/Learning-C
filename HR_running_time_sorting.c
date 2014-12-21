	#include <stdio.h>
	#include <stdlib.h> // for srand, rand
	#include <math.h>
	#include <assert.h>

	int InsertionSortShifts, QuickSortSwaps;
	
	void swap(int* x, int idx1, int idx2){
		int temp = x[idx1]; 
		x[idx1] = x[idx2]; 
		x[idx2] = temp; 
	}

	int partition(int* a, int end1, int end2){
		int pivot = end2; //(end1+end2)/2; 
		int i;
		int newPivot = end1;  // this is what we need to calculate and return

		swap(a, pivot, end2); //this may look a little redundant, because pivot = end2 in the first operation in this function, but that's just for this particular problem. Pivot is not ALWAYS chosen to be equal to end2, and it is for the other cases that we need this swapping.

		for(i = end1; i<end2; i++){
			if (a[i]<=a[end2]){
				QuickSortSwaps++;
				swap(a, i, newPivot); 	
				newPivot++; // increase the newPivot index only if you are stuffing smaller values to the left of it. 
			}
		} 
	
		swap(a, newPivot, end2); // put orig pivotVal into the newPivot index
		QuickSortSwaps++;
		
		return newPivot; 
	}


	void quicksort(int* a, int end1, int end2, int array_size){
		if (end2-end1<=0){
			return;
		}

		int newPivot; 
		newPivot = partition(a, end1, end2);
	
		quicksort(a, end1, newPivot-1, array_size); 

		quicksort(a, newPivot+1, end2, array_size); 
	
		return; 
	}
	
	void insertionSort(int ar_size, int *  ar) {
	
		int V; 
		V = ar[ar_size-1]; //last element (unsorted one)
		
		int curr_i; 
		curr_i = ar_size - 2; //start from last but one element
		
		while(curr_i>=0 && ar[curr_i]>V){
			InsertionSortShifts++;
			ar[curr_i+1] = ar[curr_i];
			curr_i--;
		}
		ar[curr_i+1] = V; 
	
		return;
	}

	int main(void) {
	   	InsertionSortShifts = 0;
	   	QuickSortSwaps = 0;
	   	
     		int _ar_size;
		scanf("%d", &_ar_size);
		int _ar[_ar_size], _ar_i, x[_ar_size];
		for(_ar_i = 0; _ar_i < _ar_size; _ar_i++){
	   		scanf("%d", &_ar[_ar_i]); 
	   		x[_ar_i] = _ar[_ar_i];
	   	}
		
		int i, sub_ar_size;
		sub_ar_size = 1;
		
		for(i = 1; i < _ar_size; i++){
			sub_ar_size++;
			insertionSort(sub_ar_size, _ar);
		}
		
	 	quicksort(x, 0, _ar_size-1, _ar_size);  
	 
	 	printf("%d\n", InsertionSortShifts - QuickSortSwaps);
	 		
	        return 0;
	}
