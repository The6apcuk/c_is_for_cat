#include <stdio.h>


int main(){
    
        // get two values from user
        printf("Please input height:\n");
        char height[256];
        fgets(height, sizeof height, stdin);
        
        int height_int = 0;
        for (int i=0; height[i] != '\0' &&  height[i] != '\n'; i++)
            height_int = 10 * height_int + (height[i] - '0');
            
        printf("Please input wides:\n");
        char width[256];
        fgets(width, sizeof width, stdin);
        
        int width_int = 0;
        for (int i=0; width[i] != '\0' &&  width[i] != '\n'; i++)
            width_int = 10 * width_int + (width[i] - '0');

        printf("height %i, wides %i\n", height_int, width_int);
        
        float perimeter = ((float) ((width_int + height_int) * 2)) * 39.37;
        float area = ((float) (width_int * height_int)) * 39.37;
        printf("perimeter %f, area %f\n", perimeter, area);
        
}
