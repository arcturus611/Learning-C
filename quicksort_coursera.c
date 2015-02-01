#include <stdio.h>
#include <stdlib.h> // for srand, rand
#include <time.h>
//#include "quickSort.h"
//#define LENGTH 10 
int COMPARISON_COUNT = 0;

void swap(int* x, int idx1, int idx2){
	int temp = x[idx1]; 
	x[idx1] = x[idx2]; 
	x[idx2] = temp; 
}

/* Tim Roughgarden's algorithm- exactly the same, but with different variable names. Used his var names because of programming assignment requirement.
*/

int cmpfnc(const void* a, const void* b){
	return (*(int* )a - *(int *)b);
}

int median_of_three_idx(int* x, int* y){
	if((x[0]>=x[1] & x[0]<=x[2]) | (x[0]>=x[2] & x[0]<=x[1])) return y[0];
	else if ((x[1]>=x[0] & x[1]<=x[2]) | (x[1]<=x[0] & x[1]>=x[2])) return y[1];
	else if ((x[2]>=x[0] & x[2]<=x[1]) | (x[2]<=x[0] & x[2]>=x[1])) return y[2];
	return -1;
}

int partition(int* a, int end1, int end2){
	int mid = (end1 + end2)/2;
	int temp1[3];
	int temp2[3]; 
	temp1[0] = a[end1];
	temp1[1] = a[mid]; 
	temp1[2] = a[end2];
	temp2[0] = end1; 
	temp2[1] = mid; 
	temp2[2] = end2;
	
	/*printf("Array is: \n"); 
	for(int i = end1; i<=end2; i++)
		printf("%d, ", a[i]);
	printf("Median elements are: %d, %d,%d\n", a[end1], a[mid], a[end2]);*/
	
	int pivot = median_of_three_idx(temp1, temp2); //Pivot method varies 
/*	printf("Pivot is: %d\n\n", pivot);*/
	
	int i = end1 + 1; // to the left of i: all elements smaller than pivot_val, plus pivot_val (only temp). to the right: all eles larger than pivot_val
	int j;  

	swap(a, pivot, end1); 

	for(j = end1 + 1; j<=end2; j++){
		if (a[j]<=a[end1]){
			swap(a, j, i); 	
			i++; // increase i only if stuffing smaller values to the left of pivot. 
		}
	} 
	
	swap(a, i-1, end1); 
	
	return i-1; 
}


void quicksort(int* a, int end1, int end2){
	if (end2-end1<=0){
		return;
	}
	
	COMPARISON_COUNT = COMPARISON_COUNT + (end2 - end1);

	int newPivot = partition(a, end1, end2);

	/*for(int i = 0; i<array_size; i++)
		printf("%d ", a[i]);
	printf("\n");*/
	/*
	quicksort(a, end1, newPivot-1, array_size); 

	quicksort(a, newPivot+1, end2, array_size); */
	
	
	quicksort(a, end1, newPivot-1); 
	

	quicksort(a, newPivot+1, end2); 
	
	return; 
}

int main(int argc, char** argv){


/*	int x[LENGTH]; 
	int i;
	srand(time(NULL)); */
	
/*	int _ar_size;
	scanf("%d", &_ar_size);
	int x[_ar_size], _ar_i;
		
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
		scanf("%d", &x[_ar_i]); 
	}	

	printf(" \n The given array is :\n "); 
	for(int i =0; i< _ar_size; i++){
		printf("%d ", x[i]); 
	}
	printf("\n"); 
	//quicksort(x, 0, _ar_size-1, _ar_size);*/
	int _ar_size = 0;
	int* x = (int *)malloc(10000*sizeof(int));
	
	FILE* fp; 
	fp = fopen("QuickSort.txt", "r");
	while(fscanf(fp, "%d", x+ _ar_size)==1){
		_ar_size++;
	}
	fclose(fp);
	
/*	printf(" \n The input array is : "); 
	for(int i =0; i< _ar_size; i++){
		printf("%d ", x[i]); 
	}
	printf("\n");
	*/
	
	quicksort(x, 0, _ar_size-1);

	printf(" \n The sorted array is : "); 
	for(int i =0; i< _ar_size; i++){
		printf("%d ", x[i]); 
	}
	printf("\n");
	
	printf("# of comparisons = %d\n", COMPARISON_COUNT);
	
	free(x);
}
