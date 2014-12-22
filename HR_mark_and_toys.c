	//HR_mark and toys (easy)
	
	#include<stdlib.h>
	#include<stdio.h>
	
	int cmpfnc(const void* a, const void* b){
		return (*(int *)a-*(int *)b);
	}
	
	int find_max_num_toys(int* prices, int N, int K){
		qsort(prices, N, sizeof(int), cmpfnc);
		int sum, i;
		sum = 0;
		i = 0;
		while(sum<=K){
			sum+=prices[i];
			i++;
		}
		
		return i-1;	
	}
	
	int main(int argc, char* argv[]){
		int N, K;
		scanf("%d %d", &N, &K);
		int prices[N], i;
		for(i = 0; i<N; i++){
			scanf("%d", &prices[i]);
		}
		
		printf("%d\n", find_max_num_toys(prices, N, K));
		
		return 0;
	}
