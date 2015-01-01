	/*
		The  maximum subarray problem, as solved by Kadane by dynamic programming
	*/

	#include<stdio.h>
	
	int main(int argc, char* argv[]){
		int A[] = {1, -1, -1, 1, 1, 2, 4, -78, 5};
		int max_ending_here, max_so_far; 
		max_ending_here = max_so_far = A[0];
		
		int temp_sum;
		for(int i = 1; i<9; i++){
			temp_sum = A[i] + max_ending_here;
			max_ending_here = ((A[i]>temp_sum) ? A[i] : temp_sum);
			max_so_far = ((max_so_far>max_ending_here) ? max_so_far : max_ending_here);  
		}
		
		printf("Max subarray is %d\n", max_so_far);
		return 0;
	}
