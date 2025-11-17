//0-1 er modde hobe elements
#include <bits/stdc++.h>

using namespace std;
void bucketSort(float *arr,int n){
    vector<float>bucket[n];
    //inserting elements into buckets
    for(int i=0;i<n;i++){
        int idx=arr[i]*n;
        bucket[idx].push_back(arr[i]);
    }
    //sorting individual buckets
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
         sort(bucket[i].begin(),bucket[i].end());
        }
    }
    //combining elements from bucket
    int idx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[idx++]=bucket[i][j];
           // idx++;
        }
    }
}
int main()
{

   float arr[]={0.13,0.45,0.12,0.89,0.75,0.63,0.85,0.39};
  int n=sizeof(arr)/sizeof(arr[0]);

   bucketSort(arr,n);
for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }cout<<endl;
    return 0;
}