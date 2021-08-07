#include <stdio.h>
#include <stdint.h>

#define BYTE_LENGTH 8

uint64_t create_mask(int byte_idx, int bytes_quantity);

uint64_t convert(uint64_t val, int bytes_q)
{    
        uint64_t res = 0;
        int inverted_i = 0;
        
        for (int i = 1; i <= bytes_q; i++){
                uint64_t mask = create_mask(i, bytes_q);
                if (i <= bytes_q / 2){
                        res |= (mask & val) >> ((bytes_q - 2 * i + 1) * BYTE_LENGTH);
                }
                else{ 
                        inverted_i =  bytes_q - i + 1;
                        res |= (mask & val) << ((bytes_q - 2 * inverted_i + 1) * BYTE_LENGTH);
                }
        }
        
        return res;
}

uint64_t create_mask(int byte_idx, int bytes_quantity){
        uint64_t mask = 0;
            
        for (int cur_byte=1; cur_byte <= bytes_quantity; cur_byte++){
            
                if (mask)
                        mask <<= BYTE_LENGTH;
                if (cur_byte == byte_idx)
                        mask |= 0xFF;
        }
        
        return mask;
}

int main(int argc, char **argv)
{
        long unsigned val = 257;
        int bytes = 8;
        printf("converting %lu with %i bytes: %lu\n", val, bytes, convert(val, bytes));
        return 0;
}

