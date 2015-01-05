	/* Make It Anagram. Given two strings, delete the min number of characters to make 
	them anagrams.
	*/
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#define MAX_LEN 10000
	
	int make_them_anagram(char* a, char* b){
		int l1 = strlen(a); 
		int l2 = strlen(b);
		
		int* x = (int *)malloc(l1*sizeof(int));
		int* y = (int *)malloc(l2*sizeof(int));
		
		for(int i = 0; i<l1; i++)
			x[i] = 1; 
			
		for(int i = 0; i<l2; i++)
			y[i] = 1;
			
		for(int i = 0; i<l1; i++){ // choice of string you start with is arbitrary
			for(int j = 0; j<l2; j++){
				if(y[j]){ //choose only the letters yet unselected
					if (a[i]==b[j]){
						y[j] = 0; //if match, strike
						x[i] = 0;
						break; //stop comparing with second string and move forward
					}
				}
			}
		}
		
		int M = 0;
		for(int i = 0; i<l1; i++)
			M+=x[i];
			
		for(int i = 0; i<l2; i++)
			M+=y[i];
		
		free(x);
		free(y);
		
		return M;
	}
	
	int main(int argc, char* argv[]){
		char* s1 = (char *)malloc(MAX_LEN*sizeof(char));
		char* s2 = (char *)malloc(MAX_LEN*sizeof(char));
		
		scanf("%s", s1);
		scanf("%s", s2);
		
		printf("%d", make_them_anagram(s1, s2));
		
		free(s1);
		free(s2);
		
		return 0;
	}
