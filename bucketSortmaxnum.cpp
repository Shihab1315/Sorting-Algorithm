// any floot number elements
#include <bits/stdc++.h>
using namespace std;
void bucketSort(float *arr, int n)
{
    vector<float> bucket[n];
    // Find maximum and minimum element
    float max_ele = arr[0];
    float min_ele = arr[0];
    // finding range
    for (int i = 1; i < n; i++)
    {
        max_ele = max(max_ele, arr[i]);
        min_ele = min(min_ele, arr[i]);
    }

    float range = (max_ele - min_ele) / n;

    // inserting elements into buckets
    for (int i = 0; i < n; i++)
    {
        int idx = (arr[i] - min_ele) / range;
        // boundary elements
        float diff = (arr[i] - min_ele) / range - idx;
        if (diff == 0 && arr[i] != min_ele)
        {
            bucket[idx - 1].push_back(arr[i]);
        }
        else
        {
            bucket[idx].push_back(arr[i]);
        }
    }
    // sorting individual buckets
    for (int i = 0; i < n; i++)
    {
        if (!bucket[i].empty())
        {
            sort(bucket[i].begin(), bucket[i].end());
        }
    }
    // combining elements from bucket
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[idx] = bucket[i][j];
            idx++;
        }
    }
}
int main()
{

    float arr[] = {0.13, 2.45, 0.12, 0.89, 6.75, 0.63, 50.85, 0.39};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}