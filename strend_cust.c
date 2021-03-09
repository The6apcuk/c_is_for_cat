#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>



bool strend(char *s, char *t)
{
    // Get sizes for  s and t
    int s_size = 0;
    while (*(s + s_size++) != '\0')
        ;
        
    int t_size = 0;
    while (*(t + t_size++) != '\0')
        ;
    // Get size difference between s and t
    int size_diff = s_size - t_size;
    
    // In case t is greater than s -> FAIL here 
    if (size_diff < 0){
        return false;
    }
    
    // Skip beginning of s until the sizes of t and s are the same   
    while (size_diff--)
        s++;
        
    // Check that s equals t until the end of s
    while (*s++ == *t++ && *s != '\0')
        ;
        
    // If it is the end of s and t and they still equal -> success
    if (*s == *t && *s == '\0')
        return true;
    return false;
        
}

int main(){
    printf("%s\n", strend("hehez", "ez") ? "true": "false");
//    printf("ololo\n");
    return 0;
}


