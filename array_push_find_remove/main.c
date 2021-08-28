#include <stdio.h>
#include "array.h"


int main(){

    for (int i = 0; i <= 254; i++)
        ar_push(5);
    ar_push(3);
//    ar_remove(0);
    int val = 3;
    printf("first %i is at %i\n", val, ar_find_first(val));
    for (int i = 0; i <= 255; i++){
        printf("%i", list[i]);
        if (i % 100 == 0)
            printf("\n");
    }
    printf("\n");
}
