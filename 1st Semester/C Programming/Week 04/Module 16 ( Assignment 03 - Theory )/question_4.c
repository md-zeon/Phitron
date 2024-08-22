/*
Question: Show the 4 types of examples of functions given below with an example. You can give any example you want, but make sure you are giving different examples for all the four types..					Marks: 20
Has Return + Parameter
Has Return + No Parameter
No Return + Parameter
No Return + No Parameter

sample input:
5 6
12 3
12 4

sample output:
11
9
30
3

*/


#include <stdio.h>

//Has Return + Parameter

int add(int a, int b)
{
    int c = a + b;
    return c;
}

//Has Return + No Parameter

int sub()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a - b;
    return c;
}

//No Return + Parameter

void mul(int a, int b)
{
    int c = a * b;
    printf("%d\n", c);
}

//No Return + No Parameter

void div()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a / b;
    printf("%d\n", c);
}


int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c = add(a, b);
    int d = sub();
    printf("%d\n", c);
    printf("%d\n", d);

    mul(a, b);
    div();



    return 0;
}