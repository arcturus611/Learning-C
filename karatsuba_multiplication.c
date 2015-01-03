	/* Karatsuba Multiplication Algorithm, as explained in Tim Roughgarden's coursera class
	Jan 3, 2015*/
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	
	int min_fn(int a, int b){
		return (a<b)?a:b;	
	}
	
	int num_of_digits(int A){
		int n = 0;
		while(A){
			n++;
			A/=10;
		}
	//	printf("Number of digits in %d is %d\n", c, n);
		return n;
	}
	
	int* split_into_half(int x, int n, int n_min){
		int* A = (int* )malloc(4*sizeof(int));
		int n_1, n_2; 
		
		n_2 = n_min/2; //!
		n_1 = n-n_2;
		A[0] = x/pow(10, n_2); //removing last n_2 digits
		A[1] = x - A[0]*pow(10, n_2);
		A[2] = n_1; 
		A[3] = n_2;
		
	//	printf("Splitting %d into %d and %d, with %d and %d digits resp", x, A[0], A[1], A[2], A[3]);
		
		return A;	
	}
	
	int karatsuba_mult(int x, int y, int n1, int n2){
		int p;
		if(n1 == 1 || n2 == 1){
		 	p = x*y;
	//		printf("Product of %d and %d is %d\n", x, y, p);
			return p;
		}
		
		int* A; int* C; int n3, n4, n_min;
		
		n_min = min_fn(n1, n2);
		
		A = split_into_half(x, n1, n_min);
		C = split_into_half(y, n2, n_min);
		
		int ac, bd, prod_of_sums, ad_plus_bc; 
		
		ac = karatsuba_mult(A[0], C[0], A[2], C[2]);
		bd = karatsuba_mult(A[1], C[1], A[3], C[3]);
		
		n3 = num_of_digits(A[0] + A[1]);
		n4 = num_of_digits(C[0] + C[1]);
		prod_of_sums = karatsuba_mult(A[0]+A[1], C[0]+C[1], n3, n4);
		
		ad_plus_bc = prod_of_sums - ac - bd; 
		
		p = ac*pow(10, A[3] + C[3]) + ad_plus_bc*pow(10, A[3]) + bd;  
	//	printf("Product of %d and %d is %d\n", x, y, p);
		return p;
	}
	
	int main(int argc, char* argv[]){
		int x, y; 
		scanf("%d %d", &x, &y);
		int dig_x, dig_y; 
		printf("Enter number of digits in x and y, please: ");
		scanf("%d %d", &dig_x, &dig_y);
		
		printf("Product of %d and %d is %d\n", x, y, karatsuba_mult(x, y, dig_x, dig_y));
		
		return 0;
	}
