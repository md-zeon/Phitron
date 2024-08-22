/*
Question: Write a function named is_palindrome() which will receive a string as parameter from the main function and this function will return 1 if the string is palindrome, otherwise it will return 0. And with the help of this 1 or 0 print “Palindrome” or “Not Palindrome” in the main function.			Marks: 15

Constraints: String length will be maximum 10.

*/

#include <stdio.h>
#include <string.h>

int is_palindrome(char arr[]) {

    int i = 0, j = strlen(arr) - 1;

    while (i < j) {

        if (arr[i] != arr[j]) {
            return 0;
        }
        i++;
        j--;

    }
    return 1;
}

int main() {

    char arr[10];

    scanf("%s", arr);

    if (is_palindrome(arr)) {

        printf("Palindrome");

    } else {

        printf("Not Palindrome");

    }

    return 0;

}


/*
palindrome:
Input: madam
Output: Palindrome



not palindrome:

Input: mad

Output: Not Palindrome


*/