# include <stdio.h>
# include <math.h>

int convert888to565(int rgb888){
        int firstOctet, secondOctet, thirdOctet;
        firstOctet = rgb888 >> 16;
        secondOctet = rgb888 >> 8 & 0xFF;
        thirdOctet = rgb888 & 0xFF;
        
        float firstOctetMaxLength, secondOctetMaxLength, thirdOctetMaxLength;
        firstOctetMaxLength = thirdOctetMaxLength = pow(2, 5);
        secondOctetMaxLength = pow(2, 6);
        
        int firstOctetNewVal =  (float) firstOctet / 256.0 * firstOctetMaxLength;
        int secondOctetNewVal =  (float) secondOctet / 256.0 * secondOctetMaxLength;
        int thirdOctetNewVal =  (float) thirdOctet / 256.0 * thirdOctetMaxLength;
        
        return firstOctetNewVal << (5 + 6) | secondOctetNewVal << 5 | thirdOctetNewVal;
}


int main(int argc, char **argv)
{   
        int initValue = 10 << 16 | 10 << 8 | 10;
        printf("initValue %i\n", initValue);
        printf("converted rgb888 to rgb565: %i\n", convert888to565(initValue));
        return 0;
}
    
