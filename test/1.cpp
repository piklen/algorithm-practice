#include <iostream>
using namespace std;
void print(int arr[])
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}
void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void insertSort(int arr[])
{
    int n = 10;
    if (n < 2)
    {
        return;
    }
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 0 && arr[j] < arr[j - 1])
        {
            swap(arr, j, j - 1);
            j--;
        }
    }
}
int main()
{
    int arr[] = {3, 43, 56, 6, 7, 3, 5, 63654, 34, 10};
    print(arr);
    insertSort(arr);
    print(arr);
    return 0;
}
// 选择排序