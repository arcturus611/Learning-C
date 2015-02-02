	/*
	John Watson performs an operation called Right Circular Rotation on an integer array a0,a1 ... an-1. Right Circular Rotation transforms the array from a0,a1 ... aN-1 to aN-1,a0,... aN-2.

He performs the operation K times and tests Sherlock's ability to identify the element at a particular position in the array. He asks Q queries. Each query consists of one integer x, for which you have to print the element ax.
	
	*/
	
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>
	
	int* right_circ_rot(int* A, int N, int K, int* B){
		K = K%N; 	

		int fwd_start_idx = 0; 
		int bck_start_idx = N-K;
		int bck_end_idx = N-1; 
		
		int num_bck_shifted = bck_end_idx - bck_start_idx + 1; 
		
		for(int i = 0, j = bck_start_idx; i<num_bck_shifted; i++, j++){
			B[i] = A[j]; 
		}
		
		for(int i = num_bck_shifted, j=fwd_start_idx; i<N; i++, j++){
			B[i] = A[j];
		}
		
		return B;
	}

	int main(int argc, char* argv[]) {

	    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	    int N, K, Q;
	    scanf("%d %d %d", &N, &K, &Q);
	    int* A = (int *)malloc(N*sizeof(int));
	    int* B = (int *)malloc(N*sizeof(int));
	    
	    for(int i = 0; i<N; i++){
	    	scanf(" %d ", A+i);
	    }
	    
	    B = right_circ_rot(A, N, K, B); 
	    
	    int query_idx; 
            for(int i = 0; i<Q; i++){
            	scanf("%d", &query_idx);
            	printf("%d\n", B[query_idx]); 
            }
            	    
	    return 0;
	}

