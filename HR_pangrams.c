	//hacker rank pangram question 
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<ctype.h>
	
	#define MAX_LEN 1001
	
	int cmpfnc(const void* a, const void* b){
		return (*(char *)a - *(char *)b);
	}	
	
	int is_pangram(char* line){
		int pangram_score;
		pangram_score = 0;
		int l, i;
		l = strlen(line);
		
		qsort(line, l, sizeof(char), cmpfnc);	
		
		for(i = 1; i<l; i++){
			if(isalpha(line[i])){
				if(tolower(line[i])!=tolower(line[i-1]))	
					pangram_score |= (1<<(tolower(line[i])-'a'));
			}	
		}	
		
		return (pangram_score==0x3ffffff);
	}
	
	int main(int argc, char* argv[]){
		char line[MAX_LEN]; 
		fgets(line, MAX_LEN, stdin);
		line[strchr(line, '\n')- line] = '\0';
		
		if(is_pangram(line)) printf("pangram\n");
		else printf("not pangram\n");
		
		return 0;
	}
