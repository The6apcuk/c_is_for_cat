#include <stdio.h>

int strncpy_(char *dest, const char *src, size_t n){
    if (n < 0){
        return -1;
    }
    
    while (n && *src){
        *dest++ = *src++;
        n--;
    }
        
    if ( !n && *src )
        *++dest = '\0';
    else if(n && !*src){
        while (n--)
            *++dest = '\0';
    }
    
        
}


int main(){
    char initial[] = "12345678";
    char dest[10];
    size_t n = 10;

    strncpy(dest, initial, n);
    printf("strncpy: %s\n", dest);

    char initial2[] = "12345678";
    char dest2[10];
    size_t n2 = 10;

    strncpy_(dest2, initial2, n2);
    printf("strncpy_: %s\n", dest2);
    
    
    return 0;
}
