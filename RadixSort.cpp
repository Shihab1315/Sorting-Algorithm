
#include <bits/stdc++.h>

using namespace std;
void countsort(int arr[], int n, int pos)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / pos) % 10]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n, int max)
{
    int m = max;
    for (int pos = 1; m / pos > 0; pos *= 10)
    {
        countsort(arr, n, pos);
    }
}

int main()
{

    int arr[] = {97, 57, 208, 699, 125, 756};

    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    radixSort(arr, n, max);
    for (int i = 0; i < n; i++)
    {
     cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}