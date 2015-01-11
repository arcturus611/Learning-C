	/* Counting number of inversions in array */
	
	#include<stdio.h>
	#include<stdlib.h>
	
	void print_array(int* a, int n){
		for(int i = 0; i<n; i++)
			printf("%d, ", a[i]);
		
		printf("\n");
		
		return;
	}
	
	int count_split_inversions(int* a, int len){
		printf("\nInside split inversions code...\n");
		int* b = (int* )malloc(len*sizeof(int));
		
		int* a1; int* a2; 
		int l1 = len/2;
		a1 = a; 
		a2 = a+l1;
		int count = 0;
		
		int a1_end = 0, a2_end = 0; 

		for(int i = 0; i<len; i++){
			if(!a1_end && !a2_end){
				if((*a1) <= (*a2)){
					b[i] = *a1;
					if (a1 <= (a+l1-1)) a1++;
					if (a1 == (a+l1)) a1_end = 1;
				}else{
					b[i] = *a2; 
					if (a2 <= (a + len -1)) a2++;
					if (a2 == (a + len)) a2_end = 1;
					count = count + (l1 - (a1-a));
				}
			}
			else if(a1_end){
				b[i] = *a2; 
				a2++;
			}
			else if(a2_end){
				b[i] = *a1;
				a1++;
			}
		}
		
		for(int i = 0; i<len; i++)
			a[i] = b[i];
		
		return count;
		
	}
	
	int count_inversions(int* A, int len){
		if (len<=1) return 0; 
		int l1 = len/2; 
		int l2 = len - l1;
		
		int x, y, z;
		
		x = count_inversions(A, l1); //left inversions
		print_array(A, l1); 
		printf("...Number of inversions for above array: %d\n\n", x);
		
		y = count_inversions(A+l1, l2); //right inversions
		print_array(A+l1, l2); 
		printf("....Number of inversions for above array: %d\n\n", y);
		
		z = count_split_inversions(A, len);
		print_array(A, len); 
		printf(".....Number of inversions for above array: %d\n\n", z);
		
		return x + y + z;	
	}
	
	int  main(int argc, char* argv[]){
		int N;
		scanf("%d", &N);
		int* arr = (int *)malloc(N*sizeof(int));
		
		for(int i = 0; i<N; i++)
			scanf("%d", arr + i);
			
		printf("\nNumber of inversions in given array: %d\n", count_inversions(arr, N));
		
		return 0;
	}
