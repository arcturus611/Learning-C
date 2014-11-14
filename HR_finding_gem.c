#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 100

int bitcount(int u){
	int b;
	for(b =0; u; b++)
		u &= (u-1);
	return b;
}

int main() {
    int N, i, j, letters, all_letters, l;
    all_letters = 0x3ffffff; 
    
    char str[MAX_LEN];
    scanf("%d", &N);
    for(i = 0; i<N; i++){
        scanf("%s", str);
        l = strlen(str);
        letters = 0;
        for(j = 0; j<l; j++){
            letters |= (1<<(str[j]-'a'));        
        }
        all_letters &= letters;
    }
    printf("%d\n", bitcount(all_letters));
    return 0;
}

