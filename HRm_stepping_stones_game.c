	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>
	
	void is_sum_of_first_k(long int N){
		long int s = (long int)sqrt((long double)2*N);
		if (s*(s+1) == 2*N) printf("Go On Bob %ld\n", s);
		else printf("Better Luck Next Time\n");
		return;
	}

	int main() {
		int T;
		long int N;
		scanf("%d", &T);
		
		for(int i = 0; i<T; i++){
			scanf("%ld", &N);
			is_sum_of_first_k(N);
		}
		return 0;
	}

