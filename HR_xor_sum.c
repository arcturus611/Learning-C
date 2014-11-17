//times out for large number of large numbers. 
#include <stdio.h>
#define MODVAL 1000000007

int xor_sum; //make it global so that changes with recursion
 
struct node {
	int x;
	struct node* prev;
};
 
int powerset(int *v, int n, struct node *up)
{
	
	struct node me;
 
	if (!n) {
		int subset_xor = 0;		
		while (up) {
			subset_xor = subset_xor ^ (up->x);
			up = up->prev;
		}
		
		xor_sum += subset_xor;
		xor_sum = xor_sum%MODVAL;
		
	} else {
		me.x = *v;
		me.prev = up;
		powerset(v + 1, n - 1, up);
		powerset(v + 1, n - 1, &me);
	}
	
	return xor_sum;
}
 
int main(int argc, char **argv)
{
	int T; 
	scanf("%d", &T);
	
	while(T--){
		int N;
		scanf("%d", &N);
		int arr[N];
		
		for(int i = 0; i<N; i++){
			scanf("%d", &arr[i]);
		}
		
		xor_sum = powerset(arr, N, 0)%MODVAL;
		printf("%d\n", xor_sum);
		xor_sum = 0;
	}
	return 0;
}
