#include <stdio.h>
#include <math.h>

int main(){
        
        float radius = 6;
        float perimeter = 2 * radius * M_PI ;
        float area =  pow(radius, 2) * M_PI;
        printf("perimeter %f, area %f\n", perimeter, area);
        printf("PI is %f\n", M_PI);
}
