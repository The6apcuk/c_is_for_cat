#include "array.h"
#include <stdlib.h>


int ar_push(double element)
{
    if (end_idx < MAX_VAL)
        list[end_idx++] = element;
}

int ar_find_first(double element)
{
    long i;
    for (i=0; i < end_idx && list[i] != element && i < MAX_VAL; i++);
    
    return list[i] == element ? i : ERROR;
}

int ar_remove(long remove_idx)
{
    if (remove_idx >= 0 && remove_idx < end_idx){
        for (long i = remove_idx; i != end_idx && i < MAX_VAL; i++)
            list[i] = list[i+1];
        end_idx--;
    }
}
