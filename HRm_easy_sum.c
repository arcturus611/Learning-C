	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>
	
	void easy_sum_mod(long int N, long int m){
		int temp;
		
		if(N==m){
			if (N%2){
				temp = (N-1)/2;
				printf("%ld\n", N*temp);
			}else{
				temp = N/2;
				printf("%ld\n", temp*(N-1));
			}				
			return;
		}
		
		if(N<m){
			if (N%2){
				temp = (N+1)/2;
				printf("%ld\n", N*temp);
			}else{
				temp = N/2;
				printf("%ld\n", temp*(N+1));
			}	
			return;
		}
		 
		if(N>m){
			int d = N/m; 
			long int a1, a2;
			
			if (m%2){
				temp = (m-1)/2;
				a1 = d*m*temp;
			}else{
				temp = m/2;
				a1 = d*(m-1)*temp;
			}
			
			int r = N%m;
			if (r%2){
				temp = (r+1)/2;
				a2 = r*temp;
			}else{
				temp = r/2;
				a2 = (r+1)*temp;
			}
						
			printf("%ld\n", a1 + a2);
			return;
		}
		
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
