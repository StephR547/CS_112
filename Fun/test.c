#include <stdio.h>

void display(int array[2][3]);
{
    for (int row=0; row<2; row++)
    {
        for (int col=0; col<2; col++)
        {
            scanf("%d", &array[row][col]);
        }
    }
    for (int row=0; row<2; row++)
    {
        for (int col=0; col<2; col++)
        {
            printf("%d", array[row][col]);
            if(col==2)
            {
                printf("\n");
            }
        }
    }
}

int main()
{
    int test = 1;
    display(test);
}