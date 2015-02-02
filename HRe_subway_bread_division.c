	/*
	Problem: Martha is interviewing at Subway. One of the rounds of the interview requires her to cut a bread of size l×b into smaller identical pieces such that each piece is a square having maximum possible side length with no left over piece of bread.

	My solution: Imagine a rectangle lXb. If you want to cut out squares, the length of the square must divide both the sides of the rectangle. It must also leave no remainder. Therefore,  if square side is a, lXb = nXaXa. And l%a = 0, b%a = 0. And we want the biggest such a. So a must be the gcd of l and b. 
	*/
	
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>
	
	int gcd(int x, int y){
		while(y){
			int t = y; 
			y = x%y; 
			x = t; 
		}
		return x;
	}

	int main() {

	    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	    int T, l, b, a;
	    scanf("%d", &T);
	    
	    for(int i = 0; i<T; i++){
	    	scanf("%d %d", &l, &b); 
	    	a = gcd(l, b);
	    	printf("%d\n", (l/a)*(b/a)); 
	    }
	    
	    return 0;
	}

