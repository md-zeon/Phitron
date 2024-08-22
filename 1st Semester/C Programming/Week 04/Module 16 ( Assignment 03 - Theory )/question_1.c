/*
Question: Write a C program to take positive integer N as input and print a pattern shown in the sample input output.						Marks: 20
Constraints: 1 <= N <= 5

N = 5

    1
   123
  12345
 1234567
123456789
 1234567
  12345
   123
    1
*/


#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int s = n - 1; int k = 1;

    for (int i = 1; i <= (2*n)-1; i++) {

        for (int j = 1; j <= s; j++) {
            printf(" ");
        }

        for (int j = 1; j <= k; j++) {
            printf("%d", j);
        }

        printf("\n");

        if(i < n) {
            s -= 1;
            k += 2;
        } else {
            s += 1;
            k -= 2;
        }
    }
    

    return 0;
}