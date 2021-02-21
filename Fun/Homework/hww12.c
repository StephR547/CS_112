#include <stdio.h>

    void scan_int(int *one){
        scanf("%d", one);
    }
    int main(){
       int variable;
       scan_int(&variable);
       printf("%d\n", variable);

    }
   