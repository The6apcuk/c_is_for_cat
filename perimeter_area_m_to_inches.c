#include <stdio.h>
#include <math.h>

#define METER_TO_INCH_COEF 39.37

float scanVal(char valName[]){
        printf("Please input %s:\n", valName);
        char val[256];
        fgets(val, sizeof val, stdin);

        float val_float = 0;
        int dotLevel = 0;
        for (int i = 0; val[i] != '\0' &&  val[i] != '\n'; i++)
                if (val[i] == '.'){
                        dotLevel = 1;
                }
                else if (not dotLevel){
                        val_float = 10 * val_float + (val[i] - '0');
                }
                else{
                        val_float += ((val[i] - '0') * pow(10, - dotLevel));
                        dotLevel += 1;
                }
        return val_float;
}



int main(){
    
        // get two values from user
        float height_float = scanVal("height");
        float width_float = scanVal("width");

        printf("height %f, wides %f\n", height_float, width_float);
        
        float perimeter = (width_float + height_float) * 2 * METER_TO_INCH_COEF;
        float area = width_float * height_float * METER_TO_INCH_COEF;
        printf("perimeter %f, area %f\n", perimeter, area);
        
}
