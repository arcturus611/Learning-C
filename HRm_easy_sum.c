		#include <stdio.h>
		#include <string.h>
		#include <math.h>
		#include <stdlib.h>
	
		void easy_sum_mod(long int N, long int m){
			int r = N%m;
			printf("%ld\n", (N/m)*m*(m-1)/2 + r*(r+1)/2);
			return;
		}

		int main() {
			int T; 
			long int N, m;
			scanf("%d", &T);
		
			for(int i = 0; i<T; i++){
				scanf("%ld %ld", &N, &m);
				easy_sum_mod(N, m);	
			}
			
			return 0;
		}
