	/* 
		Binary Search algorithm demonstrating logarithmic running time 
	*/
	
	#include<stdio.h>
	#include<stdlib.h>
	
	void binary_search(int* A, int n, int x){
		printf("Array is...");
		for(int i = 0; i<n; i++)
			printf("%d, ",A[i]);
		printf("\n and the element to be found is %d\n", x);
		 
		if(n==1){
			if(x==A[0]) printf("Found %d in array\n", x);
			else printf("%d not present in array\n", x);
			return; 
		}
		
		int mid = n/2;
		int y = A[mid-1];
		if(x==y) printf("Found %d in array\n", x);
		else if(x>y) binary_search(A + mid, n-mid, x);
		else if (x<y) binary_search(A, mid, x);
	
		return;
	}
	
	int main(int argc, char* argv[]){
		int N; 
		printf("Enter number of elements in array: ");
		scanf("%d", &N);
		
		int* arr = (int *)malloc(N*sizeof(int));
		printf("Enter array elements :");
		for (int i = 0; i<N; i++)	
			scanf("%d", arr+i);
			
		int x;
		printf("Enter number to be searched: ");
		scanf("%d", &x);
		
		binary_search(arr, N, x);
		
		return 0;
	}
