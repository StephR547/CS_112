#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Car{
    char manufacturer[50];
    char car_name[50];
    int model_year;
    int cost;

}car;

void display_car(car my_car){
    printf("Manufacturer: %s\n", my_car.manufacturer);
    printf("Car Name: %s\n", my_car.car_name);
    printf("Year Model: %d\n", my_car.model_year);
    printf("Cost of Car: $%d\n", my_car.cost);
}

void scan_car(car *my_car){
    printf("What is the Manufacturer: ");
    scanf("%s", my_car->manufacturer);
    printf("What is the Name of the car: ");
    scanf("%s", my_car->car_name);
    printf("What Year Model is it: ");
    scanf("%d", &my_car->model_year);
    printf("What is the Cost of the car: ");
    scanf("%d", &my_car->cost);
}
void initialize_cars(int **cars, int size){
    *cars=malloc(size*sizeof(int));
}

int main(){
    int *cars;
    car my_car;
    initialize_cars(&cars,5);
    scan_car(&my_car);
    display_car(my_car);
}