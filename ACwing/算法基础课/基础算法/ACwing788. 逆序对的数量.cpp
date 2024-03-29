#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int const N = 1e5 + 10;
int n;
long long sum = 0;
int a[N];
int temp[N];
void merge_sort(int a[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            sum += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= r)
    {
        temp[k++] = a[j++];
    }
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        a[i] = temp[j];
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n - 1);
    cout << sum << endl;
    return 0;
}