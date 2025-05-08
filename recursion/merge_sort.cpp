//merge sort...still need practice
//time complexity= O(nlogn)
//space complexity= O(n)
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low,int mid,int high){
    vector<int> ans;
    int l=low;
    int r=mid+1;
    while(l<=mid && r<=high){
        if(arr[l]<=arr[r]){
            ans.push_back(arr[l]);
            l++;
        }
        else{
            ans.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid){
       
            ans.push_back(arr[l]);
            l++;
        
    }
     while(r<=high){
       
            ans.push_back(arr[r]);
            r++;
        
    }
    for(int i=low;i<=high;++i){
        arr[i]=ans[i-low];
    }
    
}

void mergeSort(vector<int>& arr, int low,int high){
    
    if(low==high){
        return;
    }
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
    
}

int main() {
 vector<int> arr= {3,4,9,8,1,2,5,7,6};
 mergeSort(arr,0,8);
 for(auto it:arr){
     cout<<it<<' ';
 }
  

}
