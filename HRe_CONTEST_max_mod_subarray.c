	/*
		You are given an array of size N and another integer M.Your target is to find the maximum value of sum of subarray modulo M. 
		Max subarray problem with a tiny twist
		
		Given: Elements of array are int he range 1 to 10^18. wtf. 
	*/

	#include<stdio.h>
	#include<stdlib.h>
	
	long long int max_mod_subarray(long long int* A, long long int N, long long int M){
		for(int i = 0; i<N; i++)
			A[i] = A[i]%M;

		long long int max_ending_here, max_so_far;
		max_ending_here = max_so_far = A[0];
		
		long long int temp_sum, temp_val;
		for(int i = 1; i<N; i++){
			temp_val = A[i];
			temp_sum = (temp_val + max_ending_here)%M;
			
			max_ending_here = ((temp_val > temp_sum) ? temp_val : temp_sum);
			
			max_so_far = ((max_so_far>max_ending_here) ? max_so_far : max_ending_here);  
		}
		
		return max_so_far;
	}
	
	int main(int argc, char* argv[]){
		int T;
		long long int N, M;
		scanf("%d", &T);
		
		for(int i = 0; i<T; i++){
			scanf("%lld %lld", &N, &M);
			long long int* A = (long long int *)malloc(N*sizeof(long long int));
			for(int j = 0; j<N; j++)
				scanf("%lld", A+j);
			printf("%lld\n", max_mod_subarray(A, N, M)); 
			free(A);
		}	
		
		return 0;
	}
