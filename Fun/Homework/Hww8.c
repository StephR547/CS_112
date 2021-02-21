#include <stdio.h>
#include <string.h>

int main(){
    char apple[20] = "Apple";
    char pie[20] = "Pie";
    char cake[20] = "Cake";

    strcpy(pie,apple);
    strcpy(cake,apple);

    printf("%s\n%s\n", pie, cake);

}