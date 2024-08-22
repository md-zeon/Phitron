/*
Question: Explain about pass by value and pass by reference with an example.
*/

#include <stdio.h>

void pass_by_value(int x)
{
    x = 100;
}

void pass_by_reference(int *x)
{
    *x = 120;
}

int main()
{
    int x = 10;
    printf("In main x = %d\n", x);

    pass_by_value(x);
    printf("In main after pass by value function call x = %d\n", x);

    pass_by_reference(&x);
    printf("In main after pass by reference function call x = %d\n", x);

    return 0;
}


