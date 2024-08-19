#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int freq[m+1];

    for (int i = 0; i <= m; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        freq[num]++;
    }

    for (int i = 1; i <= m; i++) {
        printf("%d\n", freq[i]);
    }

    return 0;
}