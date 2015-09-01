	/*
	On the eve of Diwali, Hari is decorating his house with a serial light bulb set. The serial light bulb set has N bulbs placed sequentially on a string which is programmed to change patterns every second. If atleast one bulb in the set is on at any given instant of time, how many different patterns of light can the serial light bulb set produce? 
	
	*/
	
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>

	long int diwali_lights(int n){
	    long int a = 1;
	    for(int i = 1; i<=n; i++){
		a = a<<1;
		a = a%100000;
	    }
	    return a-1;
	}

	int main() {

	    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	    int T, N; 
	    scanf("%d", &T);
	    for(int i = 0; i<T; i++){
		scanf("%d", &N);
		printf("%ld\n", diwali_lights(N));
	    }
		        
	    return 0;
	}
