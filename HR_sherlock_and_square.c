#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MODVAL (10*10*10*10*10*10*10*10*10 + 7)

unsigned long long int expo(unsigned long long int a, int b){
  unsigned long long int result = 1;

  while (b){
    if (b%2==1){
      result = (result*a)%MODVAL;
    }
    b /= 2;
    a = (a*a)%MODVAL;
  }

  return result%MODVAL;
}

unsigned long long int exp_by_squaring(unsigned long long int a, int k){
    if (k==1) return a%MODVAL;
    if (k==2) return (a*a)%MODVAL;
    if(!(k%2)) 	return (exp_by_squaring((a*a)%MODVAL, k/2))%MODVAL;
    else if(k%2) return (a%MODVAL)*((exp_by_squaring((a*a)%MODVAL, (k-1)/2))%MODVAL);	
    return 0;
}

unsigned long long int sides_of_square(int n){
    unsigned long long int sides;
    sides = 2 + (exp_by_squaring(2, n+1))%MODVAL;    
//    sides = 2+ expo(2, n+1)%MODVAL;
    return (sides%MODVAL);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T; 
    scanf("%d", &T);
    int arr[T]; 
    
    for (int i = 0; i<T; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i<T; i++){
    	printf("%llu\n", sides_of_square(arr[i]));
    }
    
    return 0;
}

