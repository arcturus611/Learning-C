	//HR sherlock and arrays
	
	#include<stdio.h>
	
	int sum_of_elements(int* ar, int l, int r){
		int sum = 0;
		for(int i = l; i<=r; i++)
			sum+=ar[i];
		
		return sum;
	}

	int sherlock_arrays(int s, int* ar){
		
		int is_equal = 0;
		int left_sum, right_sum;
		
		for(int i = 0; i<=s-1; i++){
			left_sum = sum_of_elements(ar, 0, i-1);
			right_sum = sum_of_elements(ar, i+1, s-1);
			if(left_sum == right_sum){
				is_equal = 1;
				break;
			}
		}
		
		return is_equal;	
	}
	
	//sherlock_arrays() was taking too long for long arrays, because it was calculating the whole sum again and again, when all that was required was adding (or subtracting) the present element for left_sum (or right_sum). That's what this new function does, and it works correctly!
	int sherlock_arrays_1(int s, int* ar){
		int left_sum, right_sum, i;
		left_sum = 0; //for idx = 0
		right_sum = 0;
		for(i = 1; i<=s-1; i++)
			right_sum += ar[i];
		if(left_sum==right_sum){
			return 1;
		}
		
		for(i = 1; i<=s-1; i++){
			left_sum+=ar[i-1]; //add prev element
			right_sum-=ar[i];
			if(left_sum==right_sum) 
				return 1;
		}
		
		return 0;
	}
	
	int main(int argc, char* argv[]){
		int T;
		scanf("%d", &T);
		int N, i, j; 
		
		for(i = 0; i<T; i++){
			scanf("%d", &N);
			int ar[N];
			for(j = 0; j<N; j++)
				scanf("%d", &ar[j]);
			
			/*if (sherlock_arrays(N, ar)) printf("YES\n");
			else printf("NO\n");*/ 
			
			if (sherlock_arrays_1(N, ar)) printf("YES\n"); 
			else printf("NO\n"); 
			
		}
		return 0;
	}
