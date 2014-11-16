	//bit manipulation practice!
	
	#include<stdio.h>
	#include<stdbool.h>
	typedef enum{LOUISE, RICHARD} player;
	char* players[2] = {"Louise", "Richard"};
	
	unsigned long long int prev_pow_2(unsigned long long int x){
		x = x|(x>>1); 
		x = x|(x>>2);
		x = x|(x>>4); 
		x = x|(x>>8); 
		x = x|(x>>16); 
		return (x-(x>>1));
	}
	
	bool is_pow_2(unsigned long long int u){
		return (!(u==0) && ((u & (u-1))==0));
	}
	
	void play_game(unsigned long long int u){
		player curr_player = LOUISE;
		player last_player = RICHARD;
		
		while(u>1){
			if(is_pow_2(u)) u = u>>1;
			else u = u - prev_pow_2(u);
		
			last_player = curr_player;
			curr_player = !curr_player;
		}
		
		printf("%s\n", players[last_player]);
		return;
	}
	
	int main(int argc, char* argv[]){
		int t;
		unsigned long long int x;
		
		scanf("%d", &t);
		while(t--){
			scanf("%llu", &x);
			play_game(x);
		}
		return 0;
	}
