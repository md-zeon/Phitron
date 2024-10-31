#include <bits/stdc++.h>
using namespace std;

void init_code()
{

}

const int N = 1e5+7;
int nums[N];

void merge(int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;
    int L[left_size + 1];
    int R[right_size + 1];

    for (int i = left, j = 0; i <= mid; i++, j++)
    {
        L[j] = nums[i];
    }
    for (int i = mid + 1, j = 0; i <= right; i++, j++)
    {
        R[j] = nums[i];
    }
    L[left_size] = R[right_size] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = left; i <= right; i++)
    {
        if (L[lp] <= R[rp])
        {
            nums[i] = L[lp];
            lp++;
        }
        else
        {
            nums[i] = R[rp];
            rp++;
        }
    }

}

void mergeSort(int left, int right)
{
    if (left == right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main()
{
    init_code();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    mergeSort(0, n-1);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}