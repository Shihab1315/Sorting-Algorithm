
#include <bits/stdc++.h>
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define ll long long
using namespace std;
void mergeSort(int *arr, int st, int end, int mid)
{
    int i = st;
    int j = mid + 1;
    int k = 0;
    int temp[end - st + 1];
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i + st] = temp[i];
    }
}
void merge(int *arr, int st, int end)
{
    int mid = (st + end) / 2;
    if (st >= end)
        return;
    merge(arr, st, mid);
    merge(arr, mid + 1, end);
    mergeSort(arr, st, end, mid);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}