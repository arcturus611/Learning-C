//HackerRank easy warmup problem (Manasa and the treasure trail)
// NOTE: This works, but is unnecessarily complicated and memory-intensive, and therefore fails for large n (2^n becomes prohibitively large). Check HR_treasure_trail_mod.c

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int idx;

void treasure_trail(int start, int a, int b, int pos, int total_pos, int** v){
	if(pos==total_pos){
		(*v)[idx] = start;
		idx++;
	}else{
		treasure_trail(start+a, a, b, pos+1, total_pos, v);
		treasure_trail(start+b, a, b, pos+1, total_pos, v);
	}
	return;
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

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int T, i, n, a, b, num_vals, k;
    scanf("%d", &T);
    
    for(i = 0; i<T; i++){
    	scanf("%d", &n);
    	scanf("%d", &a);
    	scanf("%d", &b);
    	num_vals = 1;
    	for(k = 0; k<(n-1); k++)
    		num_vals*=2; //coz 2^n doesn't exist in C, and pow() is only for floats
    		
    	int* vals = malloc(num_vals*sizeof(int));
    	idx = 0;
    	treasure_trail(0, a, b, 1, n, &vals); //0: init stone val, 1: index of level in tree
	
	qsort(vals, num_vals, sizeof(int), cmpfnc);
    	print_unique_digits(vals, num_vals);
    	free(vals);
    }
     
    return 0;
}

