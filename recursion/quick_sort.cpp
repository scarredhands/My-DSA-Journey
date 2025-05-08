//quickSort (cram the algo ;)
//tc= O(nlogn)
//sc= O(1)

#include <bits/stdc++.h>
using namespace std;

//for partitioning array so that all ele smaller than the pivot are at left to pivot and all ele larger than pivot are at right to pivot. 
int f(vector<int> &arr, int low,int high){
    int i=low;
    int j=high;
    while(i<j){ //
        while(arr[i]<=arr[low] && i<=high-1){
            i++;
        }
        while(arr[j]>arr[low] && j>=low+1){
            j--;
        }
       if(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
       }
    }
    int temp=arr[low];
        arr[low]=arr[j];
        arr[j]=temp;
    return (j);
}

void quickSort(vector<int>& arr, int low,int high){
    if(low<high){
        int partition= f(arr,low,high);
        quickSort(arr,low,partition-1);
        quickSort(arr,partition+1,high);
    }

    
}

int main() {
 vector<int> arr= {3,4,9,8,1,2,5,7,6};
 quickSort(arr,0,8);
 
 for(auto it:arr){
     cout<<it<<' ';
 }
  

}
