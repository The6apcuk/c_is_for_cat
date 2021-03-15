#include <stdio.h>

int strncpy_(char *dest, const char *src, size_t n){
    if (n < 0){
        return -1;
    }
    
    // copy from src to dest until 
    while (n && *src != '\0'){
        *dest++ = *src++;
        n--;
    }
    
    // if n = 0 -> we do nothing as no space left to write   
    // if n > 0 and src has no data -> we append dest with nulls
        
    while (n--)
        *dest++ = '\0';  
    return 0;
}

int strncat_(char *dest, const char *src, size_t n){
    if (n < 0){
        return -1;
    }
    
    // go to the end of dest
    while (*dest)
        dest++;
        
    
    // copy from src to dest until 
    while (n && *src != '\0'){
        *dest++ = *src++;
        n--;
    }
        
    *dest++ = '\0';  
    return 0;
}



int main(){
    size_t n = 15;

    char initial_default[4] = "123";
    char initial[n];
    char initial2[n];
    for (int i=0; i < n-1; i++)
        initial[i] = initial2[i] = '\0';
    
    char dest_default[] = "Hello_";
    char dest[n];
    char dest2[n];
    for (int i=0; i < n; i++)
        dest[i] = dest2[i] = '\0';

    
    int i = 0;
    for (int i=0; dest_default[i]; i++)
        dest[i] = dest2[i] = dest_default[i];
    for (int i=0; initial_default[i]; i++)
        initial[i] = initial2[i] = initial_default[i];
    
    n = 10;
    int offset = n+1-10;
      
    strncat(dest, initial, n);
    printf("strncat: %s\n", dest);
    strncat_(dest2, initial2, n);

    printf(dest[n-offset] < '0' ? "strncat[%i]==%i\n" : "strncat[%i]==%c\n" , n-offset, dest[n-offset]);
    printf("strncat_: %s\n", dest2);
    printf(dest2[n-offset] < '0' ? "strncat_[%i]==%i\n" : "strncat_[%i]==%c\n", n-offset, dest2[n-offset]);
    
    
    return 0;
}
