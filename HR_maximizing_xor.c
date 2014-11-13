#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    
    int mx, i, j, temp;
    mx = 0;
    for (i = l; i<=r; i++){
        for(j = l; j<=r; j++){
            temp = i^j;
            if(temp>mx) mx = temp;
        }
    }
    return mx;

}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}

