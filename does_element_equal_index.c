	/*You are given a sorted (from smallest to largest) array A of n distinct integers which can be positive, negative, or zero. You want to decide whether or not there is an index i such that A[i] = i. Design the fastest algorithm that you can for solving this problem. */

	/*
	NOTE: Someone else posted a much better way of doing this. The same logic, but the style is quite different, so you actually see the O(logn) theory at work. 
	Instead of sending arrays, send an array and its end-points. Vary the end-points at each recursion, not the array itself.
	*/	
	#include<stdio.h>
	#include<stdlib.h>
	
	int num_comparisons = 0; 
	/* NOTE : Increment num_comparisons every time 
	we perform an <= or >= or == operation on array elements*/
	
	int does_element_equal_index1(int* a, int l, int u){
		int mid = (l+u)/2;
		
		while((mid>=l) & (mid<=u)){
			mid = (l+u)/2;
			num_comparisons++;
			if(a[mid]>mid)	u = mid; 
			else if (a[mid]<mid) l = mid; 
			else if (a[mid]==mid) return mid;
			if(mid==l){
				if(a[u]==u) return u;
			}
		}
		
		return -1;
		
	}
	
	int does_element_equal_index(int* a, int* a_i, int n){	
		int n1 = n/2; 
		int n2 = n-n1; 

		if(n==1){
			num_comparisons++;
			if(a[0]==a_i[0]) return a[0];
		}
		
		num_comparisons++;
		
		if(a[n1-1]>=a_i[n1-1]) //check first subarray for the element...
			return does_element_equal_index(a, a_i, n1);
		else{//...not in the first subarray, so check second subarray
			num_comparisons++;
			
			if(a[n1]<=a_i[n1]) 
				return does_element_equal_index(a+n1, a_i+n1, n2);
			return -1;  //subarray not eligible for a[i]==i
		}
		
		return -1; //subarray's ends correctly positioned, 
		//but there's no element in between that actually matches its index value
	}
	
	int main(int argc, char* argv[]){
		int N;
		scanf("%d", &N);
		
		int* arr = (int *)malloc(N*sizeof(int)); 		
		for(int i = 0; i<N; i++)
			scanf("%d", &arr[i]);
			
		int* arr_idx = (int *)malloc(N*sizeof(int));
		for(int i = 0; i<N; i++)
			arr_idx[i] = i;
			
		int A = does_element_equal_index(arr, arr_idx, N); 
		if(A==-1) printf("No such element\n"); 
		else printf("Element at index %d\n", A);
		
		printf("Number of comparisons is: %d\n", num_comparisons);
		
		num_comparisons=0;
		
		int B = does_element_equal_index1(arr, 0, N-1); 
		if(B==-1) printf("(method 2) No such element\n"); 
		else printf("(method 2) Element at index %d\n", B);
		
		printf("Number of comparisons is: %d\n", num_comparisons);
		 
		return 0;
	}
	
