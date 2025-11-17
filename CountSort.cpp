
#include <bits/stdc++.h>

using namespace std;
void countSort(int arr[], int n, int r)
{
    int count[r + 1] = {0}; // Initialize all the elements of zero first time count array
    int output[n];
    // Count the frequency of each element
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    // Update the count array to store cumulative counts
    for (int i = 1; i <= r; i++)
    {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }
    // Copy the sorted array to the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
int main()
{

    int arr[] = {1, 2, 4, 3, 0, 2, 1, 7, 1, 4, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Find the maximum element to set the range for counting sort
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    countSort(arr, n, max);
    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}