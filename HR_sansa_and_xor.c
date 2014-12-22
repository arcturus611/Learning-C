	//HR (mod) sansa and xor
	/*
	@input1: T (number of test cases)
	@input2a: N (number of elements of array)
	@input2b: arr 
	.... all inputs
	@output: (for each test case): xor of (xor of each subarray)
	*/
	
	#include<stdio.h>
	#include<stdlib.h>
	
	int arr_xor(int* arr, int n, int s, int x){
		int y = x;
		int i = s;
		
		for(int j = 0; j<n; j++){
			y ^= arr[i+j]; 
		}

		return y;
	}
	
	int continuous_xor(int* arr, int N){
		
		int x = 0;
		int i, j, k;
		
		for(i = 0; i<N; i++){
			j = N - i;
			for(k = 0; k<j; k++){
				x = arr_xor(arr, i + 1, k, x);
			}
		}
		
		return x;
	}
	
	int new_continuous_xor(int* arr, int N){
		int x = 0;
		if (N%2 == 0) return 0;
		else {
			for(int i = 0; i<N; i+=2){
				x^=arr[i];
			}
			return x;
		}
	}
	
	int main(int argc, char* argv[]){
		int T, N;
		scanf("%d", &T);
		
		for(int i = 0; i<T; i++){
			scanf("%d", &N);
			int arr[N];
			for(int j = 0; j<N; j++)
				scanf("%d", &arr[j]);
				
		//	printf("%d\n", continuous_xor(arr, N));
			printf("%d\n", new_continuous_xor(arr, N));
		}
		
		return 0;	

	}
