	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>

	void max_contiguous_subarray(int* A, int n){
		int curr_sum, best_sum, val;
		int curr_idx = -1, curr_start_idx = -1, curr_end_idx = -1;
		int all_neg = 1;
		
		//Check if all elements are negative. If they are, answer is the max element in the array
		for(int i = 0; i<n; i++){
			if(A[i]>=0){
				all_neg = 0;
				break;
			}
		}
		
		if(!all_neg){ //For array in which there is atleast one non-negative number...
			best_sum = 0; curr_sum = 0;
			for(int i = 0; i<n; i++){
				val = curr_sum + A[i];

				if(val>=0){
					if (curr_sum == 0) curr_idx = i;
					curr_sum = val;				
				}
				else{
					curr_sum = 0;
				}
			
				if(curr_sum>best_sum){
					best_sum = curr_sum; 
					curr_start_idx = curr_idx;
					curr_end_idx = i;
				}
			
			}
		}else{//If array only has negative numbers...
			best_sum = A[0];
			for(int i = 1; i<n; i++){
				if(A[i]>best_sum) best_sum = A[i];
			}	
		}
		printf("%d ", best_sum);

		return;
	}
	
	void max_non_contiguous_subarray(int* A, int n){	
		int sum = 0;
		int all_neg = 1;
		for(int i= 0; i<n; i++){
			if(A[i]>0){
				sum+=A[i];
				all_neg = 0;
			}
		}
		
		if(all_neg){
			sum = A[0];
			for(int i = 1; i<n; i++){
				if(A[i]>sum) sum = A[i];
			}
		}
		
		printf("%d\n", sum);
		return;
	}

	int main() {
		int T, N;
		scanf("%d", &T);
		
		for(int i = 0; i<T; i++){
			scanf("%d", &N);
			
			int* arr = (int *)malloc(N*sizeof(int));
			for(int j = 0; j<N; j++){
				scanf("%d", arr+j);
			}
			
			max_contiguous_subarray(arr, N);
			max_non_contiguous_subarray(arr, N);
		}

		return 0;
	}

