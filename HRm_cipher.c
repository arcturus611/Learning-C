	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>
	
	void decode_msg(int* msg, int K, int N){
		// input msg of length N+K-1, decoded msg of length N
		int L = N+K-1;
		
		//edge cases: K>=N; very easy: just backward xor from N-1.
		if(K>=N){
			for(int i = N-1; i>0; i--)
				msg[i]^=msg[i-1];
			for(int i = 0; i<N; i++)
				printf("%c", msg[i] + '0');
			printf("\n");
			return;
		}

		//for S elements from start and end, we can do backward/fwd xor. 	
		//S is used instead of K because K can be much bigger than N/2, in which case you might end up 
		//doing unnecessary calculations.
		int S;
		if(N%2==0) S = N/2;
		if(N%2==1) S = (N+1)/2;
		if (S>K) S = K; 
		for(int i = S-1; i>=1; i--){
			msg[i]^=msg[i-1]; //backward xor	
			msg[L-1-i]^=msg[L-i]; //forward xor
		}
		
		//for the rest, slightly different xor-ing
		for(int i = 0; i<N-2*S; i++){
			for(int j = 1; j<S; j++){
				msg[S+i]^=msg[S+i-j];
			}
		}
		
		//print results
		for(int i = 0; i<S; i++)
			printf("%c", msg[i] + '0');
		for(int i = 0; i<N-2*S; i++)
			printf("%c", msg[S+i] + '0');
		int st;
		if (N%2 && (S==(N+1)/2)) st = S-2;
		else st = S-1; 
		for(int i = st; i>=0; i--){
			printf("%c", msg[L-1-i] + '0');
		}
		printf("\n");
		return;
	}


	int main(int argc, char* argv[]) {
		int N, K;
		scanf("%d %d", &N, &K);
	
		char read_msg[N+K-1];	
		scanf("%s", read_msg);
		
		int msg[N+K-1];
		for(int i = 0; i<N+K-1; i++){
			msg[i] = read_msg[i] - '0';
		}
		
		decode_msg(msg, K, N); // sending int array etc for decoding
		
		return 0;
	}

