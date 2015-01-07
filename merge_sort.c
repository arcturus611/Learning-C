	/* Merge Sort!*/
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>
	#define LEN 10

	
	void mergesort(int* a, int len){
		
		if (len<=1) return;
	
		int l1, l2; 
		l1 = len/2; 
		l2 = len - l1; 
			
		mergesort(a, l1);
		mergesort(a + l1, l2);
		
		int* b = (int* )malloc(len*sizeof(int));
		int* a1; int* a2; 
		a1 = a; 
		a2 = a+l1;
		int a1_end, a2_end; 
		a1_end = 0; a2_end = 0;

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
			
		return;
	
	}
	
	int main (int argc, char* argv[]){
		int* a = (int *)malloc(LEN*sizeof(int));
		for (int i = 0; i<LEN; i++)
			scanf("%d", a+i);
		
		printf("Array is...");
		for(int i = 0; i<LEN; i++)
			printf("%d ", a[i]);
		printf("\n");
			
		mergesort(a, LEN);
		printf("\n Sorted array is...");
		for(int i = 0; i<LEN; i++)
			printf("%d ", a[i]);
		printf("\n");
		
		return 0;
	}
