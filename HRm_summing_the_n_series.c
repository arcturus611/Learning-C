	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>

	int main() {

		int T; 
		scanf("%d", &T);
		long int N, a; 
		for (int i = 0; i<T; i++){
			scanf("%ld", &N);
			a = N%(1000000007);
			printf("%ld\n", (a*a)%1000000007);
		}	
    		return 0;
	}

