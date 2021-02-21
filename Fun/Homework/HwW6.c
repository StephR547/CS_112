#include <stdio.h>

int main(){
    int height;
    int width;
    int count;
    printf("Please Enter a Size:");
    scanf("%d",&width);
    for(height = 1; height <= width; height++){
        for(count = 1; count <= height; count++){
            printf("*");
        }
        printf("\n");
    }
    
}