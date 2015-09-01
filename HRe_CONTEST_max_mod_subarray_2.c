	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>

	void max_contiguous_subarray(long long int* A, long long int n, long long int m){
	
			for(long long int i = 0; i<n; i++)
				A[i] = A[i]%m;
	
			long long int curr_sum, best_sum, val;

			best_sum = 0; curr_sum = 0;
			
			for(long long int i = 0; i<n; i++){
				curr_sum = (curr_sum + A[i])%m;

				if(curr_sum>best_sum){
					best_sum = curr_sum; 
				}
			
			}
	
		printf("%lld\n", best_sum);

		return;
	}

	int main() {
		int T;
		long long int N, M;
		scanf("%d", &T);
		
		for(int i = 0; i<T; i++){
			scanf("%lld %lld", &N, &M);
			
			long long int* arr = (long long int *)malloc(N*sizeof(long long int));
			for(long long int j = 0; j<N; j++){
				scanf("%lld", arr+j);
			}
			
			max_contiguous_subarray(arr, N, M);
		}

		return 0;
	}

