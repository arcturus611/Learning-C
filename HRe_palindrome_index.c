	/*
	   Palindrome Index (Hacker Rank)
		Output the array index at which when the letter is removed, 
		the rest of the array is a palindrome.
	*/
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#define MAX_LEN 100005 
	
	int is_palindrome(char* A, int i1, int i2){
		for(int i = i1, j = i2; i<j; i++, j--){
			if(A[i]!=A[j]) return 0;
		}
		return 1;
	}
	
	int get_palindrome(char* A, int len){

		for(int i = 0, j = len-1; i<j; i++, j--){
			if(A[i]!=A[j]){
				if(is_palindrome(A, i+1, j)) return i;
				else if (is_palindrome(A, i, j-1)) return j;
			}
		}
		
		return -1;
	}
	
	int main(int argc, char* argv[]){
		int T; 
		if(!scanf("%d", &T)) printf("Enter valid number of cases!\n");
		char* str = (char *)malloc(MAX_LEN*sizeof(char));
		int len;
	        
		for(int i = 0; i<T; i++){
			if(!scanf("%s", str)) printf("Enter valid string!\n");
			len = strlen(str);
			
			printf("%d\n", get_palindrome(str, len));		
		}
		
		return 0;
	}
	
