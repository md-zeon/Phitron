#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int save[], int n)
{

    if (n == 1)
    {
        return 0;
    }
    else if (save[n] != -1)
    {
        return save[n];
    }
    else if (n == 2)
    {
        return save[n] = abs(a[2] - a[1]);
    }
    else
    {
        int choice1 = solve(a, save, n - 1) + abs(a[n] - a[n - 1]);
        int choice2 = solve(a, save, n - 2) + abs(a[n] - a[n - 2]);

        return save[n] = min(choice1, choice2);
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n + 1], dp[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = -1;
    }

    cout << solve(a, dp, n);

    return 0;
}