/*
Question: Write a C program to take positive integer N as input and print a pattern shown in the sample input output.						Marks: 20
Constraints: 1 <= N <= 9
N = 5

    1
   22
  333
 4444
55555
*/

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= n-i; j++) {
            printf(" ");
        }
        for(int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}