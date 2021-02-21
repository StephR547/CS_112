#include <stdio.h>

int main(){
    int rock;
    int loveshack = 1;
    printf("What size array do you want?\nPlease enter in size:");
    scanf("%d", &rock); 

    int my_ray[rock];

    for(int lobster = 0; lobster < rock; lobster++){
        my_ray[lobster] = loveshack;
        loveshack++;
        printf("%d\n",my_ray[lobster]);
}
}