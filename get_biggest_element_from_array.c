#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


struct structName {int a; int b ;};

int main () {
   int array[] = { 1,41,2,1,23,123,41,12,123,1212,15,16,4,324,1234,0,321,5,231,3,2,112,3,412 };
   int array_size = sizeof(array)/sizeof(array[0]);
   
   struct timespec begin, end; 
   clock_gettime(CLOCK_REALTIME, &begin);

   int biggest_num = 0;
   for (int i = 0; i < array_size; i++){
       if (array[i] > biggest_num)
           biggest_num = array[i];
   }
   clock_gettime(CLOCK_REALTIME, &end);
   printf("%i, time %lu\n", biggest_num, end.tv_nsec - begin.tv_nsec);
   
   struct timespec begin2, end2; 
   clock_gettime(CLOCK_REALTIME, &begin2);
   qsort(array, array_size, sizeof(int), cmpfunc);
   int res = array[array_size-1];
   clock_gettime(CLOCK_REALTIME, &end2);
   printf("%i, time %lu\n", res, end2.tv_nsec - begin2.tv_nsec);
   
   struct structName *structVal = malloc(sizeof(*structVal));
   structVal->a = 5;
   (*structVal).a = 5;

}
