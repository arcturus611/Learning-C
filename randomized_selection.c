	/*
	Randomized Selection Algorithm
	For a given input array, return the ith order statistic of the array. That is, the ith smallest element of the array. This can be done in linear time (wtf!)
	
	*/
	#include<stdio.h>
	#include<stdlib.h>
	
	void swap(int* x, int idx1, int idx2){
		int temp = x[idx1]; 
		x[idx1] = x[idx2]; 
		x[idx2] = temp; 
	}

	int partition(int* a, int end1, int end2){
		int pivot = (end1+end2)/2; //rand()%(end2-end1+1); 
		int i;
		int newPivot = end1;  // this is what we need to calculate and return
	
		swap(a, pivot, end2); 

		for(i = end1; i<end2; i++){
			if (a[i]<=a[end2]){
				swap(a, i, newPivot); 	
				newPivot++; // increase the newPivot index only if stuffing smaller values to its left
			}
		}	 
	
		swap(a, newPivot, end2); // put orig pivotVal into the newPivot index
	
		return newPivot; 
	}
	
	int randomized_selection(int* A, int n, int idx){
		if(n==1) return A[0];
		int p = partition(A, 0, n-1);
		if(p==idx) return A[p]; 
		else if (p>idx) return randomized_selection(A, p, idx); 
		else return randomized_selection(A+p+1, n-p-1, idx-p-1); 
	}
	
	int main(int argc, char* argv[]){
		int N, select_idx;
		scanf("%d %d", &N, &select_idx);
		
		int* A = (int *)malloc(N*sizeof(int));
		for(int i = 0; i<N; i++)
			scanf(" %d", &A[i]);
		
		printf("%d is the %d-th element of the array (starting count from index 0 to %d)\n", randomized_selection(A, N, select_idx), select_idx, N-1);		
				
		return 0;
	}
