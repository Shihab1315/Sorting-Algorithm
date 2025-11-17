
#include <bits/stdc++.h>

using namespace std;
int partition(int arr[],int first,int last){
int pivot=arr[last];
int i=first-1;//for inserting elements < pivot
//for finding elements < pivot
for(int j=first;j<last;j++){
    if(arr[j]<=pivot){
        i++;
        swap(arr[i],arr[j]);
    }
}

//now i is pointing to the last element <pivot
//correct for pivot will be - i+1
i++;
swap(arr[i],arr[last]);
return i;
}

void quickSort(int arr[],int first,int last){
    //base case
  if(first>=last)return;
//recursive case
int pi=partition(arr,first,last);
quickSort(arr,first,pi-1);
quickSort(arr,pi+1,last);


}
int main()
{

   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   quickSort(arr,0,n-1);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }cout<<endl;
    return 0;
}