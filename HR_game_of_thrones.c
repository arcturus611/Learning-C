	//game of thrones!
	//determine if the given string can be anagramed to a palindrome
	
	
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <stdlib.h>
	
	int cmpfnc(const void* a, const void* b){
		return (*(char *)a - *(char *)b);
	}	
	 
	void findIfPalind(char *arr)
	{
	    int flag = 0;
	    int strike = 0;
	    int count = 1;
	    int l = strlen(arr);
	    
	    qsort(arr, l, sizeof(char), cmpfnc); //sort array in alphabetical order
	    
	    for(int i = 1; i<l; i++){
	    	if(arr[i]==arr[i-1]) count++;
	    	else{
	    		if (count%2) strike++;
	    		if(strike>1) {
	    			flag = 1;
	    			break;
	    		}
	    		count = 1;
	    	}
	    }
	    
	    if (flag==0) printf("YES\n");
	    else printf("NO\n");
	    
	    return;
	}
	
	int main() {

	    char arr[100001];
	    scanf("%s",arr);
	    findIfPalind(arr);
	    return 0;
	}

