
#include <bits/stdc++.h>
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define ll long long
using namespace std;

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
    for (int i = 1; i < n; i++)
    {
        int curr_ele = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curr_ele)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=curr_ele;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}