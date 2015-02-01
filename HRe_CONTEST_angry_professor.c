	/*
	Professor is conducting a course on Discrete Mathematics to a class of N students. He is angry at the lack of discipline shown by students and decided to cancel the class if there are less than K students present after the class starts.

	Given the arrival time of each student, your task is to find out if the class gets cancelled or not

	*/

	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>

	int main() {
		int T, N, K, count, a; 
		scanf("%d", &T);
		
		for(int i = 0; i<T; i++){
			scanf(" %d %d", &N, &K);
			
			count = 0;
			
			for(int k = 0; k<N; k++){
				scanf(" %d", &a);
				if(a <= 0) count++;
			}
			
			if (count>=K) printf("NO\n");
			else printf("YES\n");
			
		}
		    
		return 0;
	}

