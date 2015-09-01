	/* Coursera Tim Roughgarden Algo-1
		Theory Problem:  You are a given a unimodal array of n distinct elements, meaning that its entries are in increasing order up until its maximum element, after which its elements are in decreasing order. Give an algorithm to compute the maximum element that runs in O(log n) time.
	 */
	 
	 #include<stdio.h>
	 #include<stdlib.h>
	 
	 int operation_count;
	 
	 int* find_max(int* start, int* end)
	 {	
	    // base case
	    if (end - start < 2)
	    {
	        return (*start > *end) ? start: end;
	    }
	    int* p = (end - start) / 3 + start;
	    int* q = (end - start) * 2 / 3 + start;
	    // throw out whichever third has smaller element, recurse on remainder
	    return *p > *q ? find_max(start,q - 1) : find_max(p + 1, end);
	 }
	 
	 int find_peak(int* A, int n){

	 	if (n==1) return A[0];
	 	
	 	int l1 = n/2; //length of first subarray
	 	int l2 = n-l1;  //length of second subarray
	 	
	 	if(A[l1-1]-A[l1-2] < 0)  return find_peak(A, l1); 
	 	else{
	 		if(A[l1] - A[l1-1] < 0) return A[l1-1]; 
	 		else return find_peak(A+l1, l2); 
	 	}
	 	
	 }
	 
	 int find_peak2(int* A, int n){
	 	if (n==1) return A[0];
	 	
	 	int l1 = n/2; //length of first subarray
	 	int l2 = n-l1;  //length of second subarray
	 	
	 	return (A[l1]-A[l1-1] < 0) ? find_peak(A, l1) : find_peak(A+l1, l2) ;
	 }
	 
	 int main(int argc, char* argv[]){
	 	int N; 
	 	scanf("%d", &N);
	 	
	 	int* A = (int *)malloc(N*sizeof(int));
	 	for(int i = 0; i<N; i++){
	 		scanf("%d", A+i);
	 	}
	 	
	 	operation_count = 0; 
	 	printf("Max of the array is %d\n", find_peak(A, N));
	 	printf("The operation count is %d\n", operation_count);
	 	
	 	int* x = find_max(A, A+N-1);		
	 	printf("Max of the array (method 2) is %d\n", *x);
	 
	 	printf("Max of array by method 3 is %d\n", find_peak2(A, N)); 		
	 	return 0;
	 }
	 
