#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void generate_trail_nums(int** arr, int n, int a, int b){
	int count = n;
	int a_scale, b_scale; 
	a_scale = n-1; b_scale = 0;
	for(int i = 0; i<count; i++){
		*(*arr + i) = a_scale*a + b_scale*b;
		a_scale--;
		b_scale++;
	}
}

int cmpfnc(const void* a, const void* b){
	int a1, b1;
	a1 = *(int*)a;
	b1 = *(int*)b;
	return (a1-b1);
}

void print_unique_digits(int* v, int n){
	int i;
	printf("%d ", v[0]);
	for(i = 1; i<n; i++){
		if(v[i]!=v[i-1])
			printf("%d ", v[i]);
	}
	printf("\n");
	
	return;
}

int main(int argc, char* argv[]) {

    int T, n, a, b;
    scanf("%d", &T);
    
    while(T--){
    	scanf("%d", &n);
    	scanf("%d", &a);
    	scanf("%d", &b);
    	
    	int* trail_nums = malloc((n)*sizeof(int));
    	generate_trail_nums(&trail_nums, n, a, b);
    	
    	qsort(trail_nums, n, sizeof(int), cmpfnc);
    	
    	print_unique_digits(trail_nums, n);
    	free(trail_nums);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

