#include <stdio.h>
#include <math.h>

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
        float userInput = scanVal("devider");
        for (int i = 0; i <= 500.0; i++)
            if  (i % (int) userInput == 0)
                printf("%i ", i);
        printf("\n");
}
