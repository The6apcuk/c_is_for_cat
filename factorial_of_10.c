#include <stdio.h>
#include <math.h>

int main(){
        int res = 1;
        for (int i = 1; i <= 10; i++)
            res *= i;
        printf("res is %i\n", res);
}
