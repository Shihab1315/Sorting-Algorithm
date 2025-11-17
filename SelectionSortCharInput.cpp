
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void selectionSort(vector<char> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        // finding minimum elements in unsorted array
        int minidx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[minidx])
            {
                minidx = j;
            }
        }
        // placing minimum element at begining
        if (i != minidx)
        {
            swap(v[i], v[minidx]);
        }
    }
    return;
}
int main()
{

    vector<char> v={'d','a','t','y','b','c','s'};

    selectionSort(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
