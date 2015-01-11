	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>

	int main() {
	    
	    int N, x;
	    scanf("%d", &N);
	    int sum = 0;
	    
	    for(int i = 0; i<N; i++){
		scanf("%d", &x);
		sum+=x;
	    }
	    
	    printf("%.1lf", sum/2.0);
	    
	    return 0;
	}

