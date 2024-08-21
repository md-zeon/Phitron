#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for abs

int main() {
    // double x;
    // scanf("%lf", &x);
    // int ans = ceil(x);
    // int ans = floor(x);
    // int ans = round(x);
    // printf("%d\n", ans);

    // double ans = sqrt(x);
    // printf("%.2lf\n", ans);

    // int a, b;
    // scanf("%d %d", &a, &b);
    // int ans = pow(a*1.0, b*1.0);
    // printf("%d\n", ans);

    int n;
    scanf("%d", &n);
    int ans = abs(n);
    printf("%d\n", ans);

    return 0;
}