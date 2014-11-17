	//hacker rank, determine numnber of perf squares between two nums
	//again, timed out. what is going on??
	
	#include<stdio.h>
	#include<math.h>
	
	int is_perfect_sqr(int x){
		int y = sqrt(x);
		if(y*y == x) return 1; 
		else return 0;
	}
	
	int main(int argc, char* argv[]){
		int T; 
		scanf("%d", &T);
		
		while(T--){
			int num_sqrs = 0;
			int a, b;
			scanf("%d %d", &a, &b);
			for(int i = a; i<=b; i++)
				num_sqrs += is_perfect_sqr(i);	
			printf("%d\n", num_sqrs);	
		}
		return 0;
	}
