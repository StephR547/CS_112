# include <stdio.h>
int main(){
    int x = 4;
    int y = 10;

if (x > 3) {
    if (y < 4) {
        printf("I am here\n");
    }
    else {
        printf("I am instead over here\n");
    }
} else {
    if (y > 10) {
        printf("This is where I am\n");
    } else {
        printf("Nevermind, I am here\n");
    }
}
}


