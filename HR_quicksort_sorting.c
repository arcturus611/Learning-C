	//quicksort partition (easy) hackerrank
	
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>
	#include <assert.h>
	
	void partition(int ar_size, int *  ar) {
		
		if(ar_size==0 || ar_size==1)
			return;
	
		int pivot_value = ar[0];
		
		int lower_partition_idx = 0; 
		
		int i, j;
		
		for (i = lower_partition_idx+1; i<=ar_size-1; i++){
			if(ar[i]<pivot_value){
				int temp = ar[i];
				for(j = i; j>lower_partition_idx; j--){
					ar[j] = ar[j-1];
				}
				ar[j] = temp;
				lower_partition_idx++;
			}
		}
				
		partition(lower_partition_idx, ar); 
		partition(ar_size-lower_partition_idx-1, ar+lower_partition_idx+1);
			
		return;
	}
	
	int main(int argc, char* argv[]) {
	   
		int _ar_size;
		scanf("%d", &_ar_size);
		int _ar[_ar_size], _ar_i;
		
		for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
			scanf("%d", &_ar[_ar_i]); 
		}	

		partition(_ar_size, _ar);
		
		for(_ar_i = 0; _ar_i< _ar_size; _ar_i++){
			printf("%d ", _ar[_ar_i]);
		}
		printf("\n");
				   
		return 0;
	}

