#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char nums[n+1];
    scanf("%s", nums);

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i] - '0';
    }

    printf("%d", sum);

    return 0;
}