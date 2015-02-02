	/*
	You are given an integer N. Is there a permutation of digits of integer that's divisible by 8? A permutation of digits of integer N is defined as an integer formed by rearranging the digits of N. For example, if the number N = 123, then {123, 132, 213, 231, 312, 321} are the possible permutations
	*/
	
	#include<stdio.h>
	#include<stdlib.h>
	int mult_8_digits[125][10] = {{0}}; 
	
	int get_digit_dist(long long int N, int* N_digits){
		int num_dig = 0;
		while(N){
			N_digits[N%10]++;
			N/=10;
			num_dig++;
		}	
		return num_dig;
	}
	
	void get_mult_8_digits(){
		int num, row;
		row = 0;
		for(int i = 0; i<1000; i+=8){
			num = i;
			get_digit_dist(num, mult_8_digits[row]); 
			row++;
		}
		return;
	}
	
	int is_div_by_8(int* n_dig){
		int count;
		for(int i = 0; i<125; i++){
			count = 0;
			for(int j = 0; j<10; j++){
				if((n_dig[j] && mult_8_digits[i][j]) && (n_dig[j] >= mult_8_digits[i][j])){
					count = count + mult_8_digits[i][j];
				}

				if (count==3){
					return 1;
				} 	
			}	
		}
		
		return 0;
	}
	
	int main(int argc, char* argv[]){
		int T; 
		scanf("%d", &T);
		
		long long int N;	
		int N_digits[10], num_digits, reverse_num; 
		
		get_mult_8_digits();
		
		for(int i = 0; i<T; i++){
			scanf("%lld", &N); 
			for(int j = 0; j<10; j++) N_digits[j]=0;
			
			num_digits = get_digit_dist(N, N_digits); 
			
			if(N==0) printf("YES\n"); 
			else{
				if(num_digits==1){
					if(!(N%8)) printf("YES\n"); 
					else printf("NO\n");
				}else if (num_digits==2){
					if(!(N%8)) printf("YES\n"); 
					else{
						reverse_num = 10*(N%10) + N/10; 
						if(!(reverse_num%8)) printf("YES\n");
						else printf("NO\n");
					}
				}else{
					is_div_by_8(N_digits) ? printf("YES\n"): printf("NO\n");
				}
			}
		}	
		
		return 0;
	}
