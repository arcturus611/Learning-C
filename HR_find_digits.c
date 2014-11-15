#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_digits(int n, int d){
	int temp, num_pos;
	num_pos = 0;
	while(n){
		temp = n%10;
		if((1<<temp) & d) num_pos++;
		n/=10;
	}
	return num_pos;
}

int main(int argc, char* argv[]) {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int t, n, divs;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);
        divs = 0;
        
 	for(int i = 1; i<=9; i++){
 		if(!(n%i)){
	 		divs |= (1<<i);
	 	}
 	}
 	
 	printf("%d\n", find_digits(n, divs));
    }
    return 0;
}

